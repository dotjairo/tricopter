#ifndef _MAIN_H_
#define _MAIN_H_

#include "MyPID.h"


#define DEBUG_LEVEL DEBUG_NONE
/*
 * Rotor definitions on tricopter
 * Note that motor 3 is the tail rotor
 *
 *    ( 1 )         ( 2 )   Front
 *        \        /
 *         +------+
 *            |
 *            |
 *          ( 3 )           Tail
 *
 */

#define MAX_ROLL 50
#define MAX_PITCH 50


#define YAW_CENTER 25.0
#define YAW_OFFSET_MIN -10.0
#define YAW_OFFSET_MAX 10
//#define YAW_OFFSET_MAX 30.0

#define MIN_THROTTLE 0.08
#define MAX_THROTTLE 0.8



//#define COPTER_DEBUG

/* Timer 1, Ch 1 */
#define ROTOR1_PIN 27
/* Timer 1, Ch 2 */
#define ROTOR2_PIN 26
/* Timer 1, Ch 3 */
#define ROTOR3_PIN 25
/* Timer 2, Channel 4 pin */
#define YAW_SERVO_PIN 8

/* Timer 4, Ch 1 */
#define PPM_PIN 16

/* 3_RX  (pin 0 on Maple Mini) */
#define IMU_RX_PIN BOARD_USART3_RX_PIN

///*
// * The PPM signal frequency: 50 Hz.
// * The max count in the timer's register
// * is 65536 (16-bit register).
// * The MCU's clock is 72 MHz.
// * Therefore the prescale factor is:
// * 1/(50 Hz) * (72 MHz) / (65536) = 21.97
// */
#define SERVO_PPM_TIMER_PRESCALE_FACTOR 22


/* min: 1ms
 *   (1 ms * 72 Mhz)/ (PRESCALE_FACTOR) =  24000
 *  https://www.google.com/search?q=((1 millisecond)*(72 MHz))/3
 */
#define SERVO_PPM_MIN 3273

/* max: 2ms =  48000 */
#define SERVO_PPM_MAX 6545

/*
 * For the Turnigy Plush 18A, which accept
 * a PPM signal at 400 Hz:
 *
 * The max count in the timer's register
 * is 65536 (16-bit register).
 * The MCU's clock is 72 MHz.
 * Therefore the prescale factor is:
 * 1/(400 Hz) * (72 MHz) / (65536) = 2.75
 */
#define ESC_PPM_TIMER_PRESCALE_FACTOR 3

/* min: 1ms
 *   (1 ms * 72 Mhz)/ (PRESCALE_FACTOR) =  24000
 *  https://www.google.com/search?q=((1 millisecond)*(72 MHz))/3
 */
#define ESC_PPM_MIN 24000

/* max: 2ms =  48000 */
#define ESC_PPM_MAX 48000

#define MAIN_LOOP_F_HZ 400

#endif
