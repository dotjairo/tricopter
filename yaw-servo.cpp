/*
 * yaw_servo.cpp
 *
 *  Created on: Jan 1, 2012
 *      Author: jairo
 */

#include "main.h"
#include "yaw-servo.h"
#include "wirish.h"

HardwareTimer timer2(2);

YawServo::YawServo() {
	_center = 0;
	_offset = 0;
	_duty = 0;
	_offset_min = 0;
	_offset_max = 0;
}


void YawServo::init(float center, float offset_min, float offset_max) {
    // set pin mode
	timer2.setMode(TIMER_CH4, TIMER_PWM);

	// set up timer prescale
	timer2.setPrescaleFactor(SERVO_PPM_TIMER_PRESCALE_FACTOR);

	// store variables
	_center = center;
	_offset_min = offset_min;
	_offset_max = offset_max;

	// move servo to an offest of 0 (middle)
	set_offset(0.0);
}

void YawServo::set_offset(float offset) {

	offset *= -1;
    // bound angle
	_offset = constrain(offset, _offset_min, _offset_max);

    _duty = SERVO_MIN + (int)( (_center + _offset) * SERVO_ANGLE_TO_DUTY);
    _duty = constrain(_duty, SERVO_MIN, SERVO_MAX);
    pwmWrite(YAW_SERVO_PIN, _duty);
}

float YawServo::get_offset() {
	return _offset;
}

void YawServo::manual_control()
{
	SerialUSB.println("Press \'j\' to lower speed.");
	SerialUSB.println("Press \'k\' to increase speed.");
	SerialUSB.println("Press \'z\' to zero command.");
	SerialUSB.println("Any other key zeroes command and exits");
	SerialUSB.println();

	uint8 input;
	while (1) {

		input = SerialUSB.read();
		if (input == 'j')
		{
			_offset -= 1;
		}
		else if(input == 'k')
		{
			_offset += 1;
		}
		else if(input == 'z')
		{
			_offset = 0;

		}else{
			break;
		}

		set_offset(_offset);
		SerialUSB.println(get_offset());
		delay(20);
	}

	set_offset(0.0);


}
