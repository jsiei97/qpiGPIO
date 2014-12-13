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
#include "DebugDefines.h"

#include "gpio_RaspberryPi.h"
#include "SysfsGPIO.h"


int main()
{
    myOut() << "A little sysfs gpio test app";

    SysfsGPIO gpio;

    // Configure the 4 gpio:s connected to the relay board.
    if(!gpio.configureGPIO(GPIO_Pin11, GPIO_DIRECTION_OUTPUT)) { myErr() << "configure failed..."; return false; }
    if(!gpio.configureGPIO(GPIO_Pin13, GPIO_DIRECTION_OUTPUT)) { myErr() << "configure failed..."; return false; }
    if(!gpio.configureGPIO(GPIO_Pin15, GPIO_DIRECTION_OUTPUT)) { myErr() << "configure failed..."; return false; }
    if(!gpio.configureGPIO(GPIO_Pin16, GPIO_DIRECTION_OUTPUT)) { myErr() << "configure failed..."; return false; }

    //Start with all LOW
    gpio.writeGPIO(GPIO_Pin11, GPIO_LOW);
    gpio.writeGPIO(GPIO_Pin13, GPIO_LOW);
    gpio.writeGPIO(GPIO_Pin15, GPIO_LOW);
    gpio.writeGPIO(GPIO_Pin16, GPIO_LOW);

    //Loop over them...
    for( int i=0 ; i<12 ; i++ )
    {
        int j=i%4;
        myOut() << i << j;
        switch ( j )
        {
            case 0 :
                gpio.writeGPIO(GPIO_Pin16, GPIO_LOW);
                gpio.writeGPIO(GPIO_Pin11, GPIO_HIGH);
                break;
            case 1 :
                gpio.writeGPIO(GPIO_Pin11, GPIO_LOW);
                gpio.writeGPIO(GPIO_Pin13, GPIO_HIGH);
                break;
            case 2 :
                gpio.writeGPIO(GPIO_Pin13, GPIO_LOW);
                gpio.writeGPIO(GPIO_Pin15, GPIO_HIGH);
                break;
            case 3 :
                gpio.writeGPIO(GPIO_Pin15, GPIO_LOW);
                gpio.writeGPIO(GPIO_Pin16, GPIO_HIGH);
            default :
                break;
        }

        sleep(1);
    }

    //Stop with all LOW
    gpio.writeGPIO(GPIO_Pin11, GPIO_LOW);
    gpio.writeGPIO(GPIO_Pin13, GPIO_LOW);
    gpio.writeGPIO(GPIO_Pin15, GPIO_LOW);
    gpio.writeGPIO(GPIO_Pin16, GPIO_LOW);
}
