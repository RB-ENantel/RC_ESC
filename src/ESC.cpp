/*
 * Electronic Speed Controller (ESC) - Library
 *
 *
 */

#include "ESC.h"

// < Constructor >
/*
 * Sets the proper pin to output.
 */
ESC::ESC(byte ESC_pin, int outputMin, int outputMax, int armVal)
{
	oPin = ESC_pin;
	oMin = outputMin;
	oMax = outputMax;
	oArm = armVal;
}

// < Destructor >
ESC::~ESC()
{
	// Nothing to destruct
}

/*
 * Calibrate the maximum and minimum PWM signal the ESC is expecting
 * depends on the outputMin, outputMax values from the constructor
 */
void ESC::calib(void)
{
	myESC.attach(oPin);  			// attaches the ESC on pin oPin to the ESC object
	myESC.writeMicroseconds(oMax);
		delay(calibrationDelay);
	myESC.writeMicroseconds(oMin);
		delay(calibrationDelay);
	arm();
}

/*
 * Sent a signal to Arm the ESC
 * depends on the Arming value from the constructor
 */
void ESC::arm(void)
{
	myESC.attach(oPin);  			// attaches the ESC on pin oPin to the ESC object
	myESC.writeMicroseconds (oArm);
}

/*
 * Sent a signal to stop the ESC
 * depends on the ESC stop pulse value
 */
void ESC::stop(void)
{
	myESC.writeMicroseconds (stopPulse);
}

/*
 * Sent a signal to set the ESC speed
 * depends on the calibration minimum and maximum values
 */
void ESC::speed(int outputESC)
{
	oESC = constrain(outputESC, oMin, oMax);
	myESC.writeMicroseconds(oESC);
}

/*
 * Set the current calibration delay in miliseconds
 *
 */
void ESC::setCalibrationDelay(uint32_t calibration_delay)
{
	calibrationDelay = calibration_delay;
}

/*
 * Set the current Stop pulse in microseconds
 *
 */
void ESC::setStopPulse(uint32_t stop_pulse)
{
	stopPulse = stop_pulse;
}
