#ifndef  __GPIO_RASPBERRYPI_H
#define  __GPIO_RASPBERRYPI_H

/**
 * The main gpio header on the Raspberry PI, rev2
 */
typedef enum GPIO_PinName {
    GPIO_Pin03 =  2,
    GPIO_Pin05 =  3,
    GPIO_Pin07 =  4,
    GPIO_Pin08 = 14,
    GPIO_Pin10 = 15,
    GPIO_Pin11 = 17,
    GPIO_Pin12 = 18,
    GPIO_Pin13 = 27,
    GPIO_Pin15 = 22,
    GPIO_Pin16 = 23,
    GPIO_Pin18 = 24,
    GPIO_Pin19 = 10,
    GPIO_Pin21 =  9,
    GPIO_Pin22 = 25,
    GPIO_Pin23 = 11,
    GPIO_Pin24 =  8,
    GPIO_Pin26 =  7,
    //Pin 27 to 40 is only for model B+
    GPIO_Pin29 =  5,
    GPIO_Pin31 =  6,
    GPIO_Pin32 = 12,
    GPIO_Pin33 = 13,
    GPIO_Pin35 = 19,
    GPIO_Pin36 = 16,
    GPIO_Pin37 = 26,
    GPIO_Pin38 = 20,
    GPIO_Pin40 = 21
} GPIO_Pin;

#endif  // __GPIO_RASPBERRYPI_H
