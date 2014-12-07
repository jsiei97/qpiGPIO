/**
 * @file SysfsGPIO.h
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

#ifndef  __SYSFSGPIO_H
#define  __SYSFSGPIO_H

#include <QString>

#include "gpio_RaspberryPi.h"

static const QString GPIO_DIRECTION_INPUT("in");   ///< sysfs gpio config direction string, in
static const QString GPIO_DIRECTION_OUTPUT("out"); ///< sysfs gpio config direction string, out

typedef enum GPIO_StateName
{
    GPIO_LOW  = 0,
    GPIO_HIGH = 1,
    GPIO_UNDEF
} GPIO_State;

class SysfsGPIO
{
    private:
    public:
        bool configureGPIO(GPIO_Pin gpionr, QString direction);
        //GPIO_State readGPIO(GPIO_Pin gpionr);
        bool writeGPIO(GPIO_Pin gpionr, GPIO_State value);
};

#endif // __SYSFSGPIO_H
