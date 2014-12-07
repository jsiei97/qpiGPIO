


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
