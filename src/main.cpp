/**
 * @file main.cpp
 * @author Johan Simonsson
 * @brief A test app for the sysfs gpio wrappern
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

#include <QDebug>
#include "gpio_RaspberryPi.h"
#include "SysfsGPIO.h"

#include "DebugDefines.h"

int main()
{
    myOut() << "A little sysfs gpio test app";

    SysfsGPIO gpio;

    if(!gpio.configureGPIO(GPIO_Pin13, GPIO_DIRECTION_OUTPUT))
    {
        myErr() << "configure failed...";
        return false;
    }

    for( int i=0 ; i<10 ; i++ )
    {
        if(i%2==0)
        {
            myOut() << "High";
            gpio.writeGPIO(GPIO_Pin13, GPIO_HIGH);
        }
        else
        {
            myOut() << "Low";
            gpio.writeGPIO(GPIO_Pin13, GPIO_LOW);
        }

        sleep(1);
    }

}
