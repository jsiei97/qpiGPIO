/**
 * @file SysfsGPIO.cpp
 * @author Johan Simonsson
 * @brief A sysfs gpio wrapper.
 */

/*
 * Copyright (C) 2014 Johan Simonsson
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <QFile>
#include <QFileInfo>
#include <QDebug>
#include <QRegExp>

#include "SysfsGPIO.h"
#include "DebugDefines.h"

bool SysfsGPIO::configureGPIO(GPIO_Pin gpionr, QString direction)
{
    if(GPIO_NONE == gpionr)
    {
        myErr() << "Bad gpio num";
        return false;
    }

    //First check that the export file is there,
    //if it is missing then the sysfs gpio "module" is not loaded.
    QFile gpioExport("/sys/class/gpio/export");
    if(!gpioExport.exists())
    {
        myErr() << "missing file: /sys/class/gpio/export";
        return false;
    }

    //If value does not exist then export
    QFile gpioDirection(QString("/sys/class/gpio/gpio%1/direction").arg(gpionr));
    if(!gpioDirection.exists())
    {
        //myOut() << gpioDirection.fileName();

        if (!gpioExport.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            myErr() << "Cant open file:" << gpioExport.fileName();
            return false;
        }

        QTextStream out(&gpioExport);
        out << gpionr << "\n";
        gpioExport.close();
        sleep(1);
    }

    {
        if (!gpioDirection.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            myErr() << gpioDirection.fileName();
            return false;
        }

        QTextStream out(&gpioDirection);
        out << direction << "\n";
        gpioDirection.close();
    }

    return true;
}

bool SysfsGPIO::writeGPIO(GPIO_Pin gpionr, bool value)
{
    if(true==value)
    {
        return writeGPIO(gpionr, GPIO_HIGH);
    }
    else
    {
        return writeGPIO(gpionr, GPIO_LOW);
    }
}

bool SysfsGPIO::writeGPIO(GPIO_Pin gpionr, GPIO_State value)
{
    if(GPIO_UNDEF == value)
    {
        //What did you plan to do?
        return false;
    }

    //Open and write 1/0 to value file
    QFile gpioFile(QString("/sys/class/gpio/gpio%1/value").arg(gpionr));

    if (!gpioFile.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        myErr() << "FAILURE can't open gpio file gpioPath:" << gpioFile.fileName();
        return false;
    }

    QTextStream out(&gpioFile);
    out << value << "\n";
    gpioFile.close();

    return true;
}


GPIO_Pin SysfsGPIO::checkGPIO(QString nr)
{
    //If string is gpio17 -> 17
    QRegExp rx("gpio([0-9]{1,3})");
    if (rx.indexIn(nr) != -1) {
        nr = rx.cap(1);
    }

    //"17" to 17
    bool ok;
    int value = nr.toInt(&ok);
    if(false==ok)
        return GPIO_NONE;

    return checkGPIO(value);
}

GPIO_Pin SysfsGPIO::checkGPIO(int nr)
{
    switch ( nr )
    {
        case GPIO_Pin03 :
        case GPIO_Pin05 :
        case GPIO_Pin07 :
        case GPIO_Pin08 :
        case GPIO_Pin10 :
        case GPIO_Pin11 :
        case GPIO_Pin12 :
        case GPIO_Pin13 :
        case GPIO_Pin15 :
        case GPIO_Pin16 :
        case GPIO_Pin18 :
        case GPIO_Pin19 :
        case GPIO_Pin21 :
        case GPIO_Pin22 :
        case GPIO_Pin23 :
        case GPIO_Pin24 :
        case GPIO_Pin26 :
        case GPIO_Pin29 :
        case GPIO_Pin31 :
        case GPIO_Pin32 :
        case GPIO_Pin33 :
        case GPIO_Pin35 :
        case GPIO_Pin36 :
        case GPIO_Pin37 :
        case GPIO_Pin38 :
        case GPIO_Pin40 :
            return (GPIO_Pin)nr;
            break;
        default :
            break;
    }
    return GPIO_NONE;
}

