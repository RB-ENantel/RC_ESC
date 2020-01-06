/*
 * Electronic Speed Controller (ESC) - Library
 *
 *
*/

#ifndef ESC_Library
#define ESC_Library

#if (ARDUINO >= 100)
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include <Servo.h>				// Including the Servo library

class ESC
{
	public:
		ESC(byte ESC_pin, int outputMin = 1000, int outputMax = 2000, int armVal = 500);
		~ESC();
		void calib(void);
		void arm(void);
		void stop(void);
		void speed(int ESC_val);
		void setCalibrationDelay(uint32_t calibration_delay);
		void setStopPulse(uint32_t stop_pulse);

	private:
	// < Local attributes >
		// Hardware
		byte oPin;			// ESC output Pin

		// Calibration
		int oMin = 1000; 
		int oMax = 2000;
		int oESC = 1000;
		int oArm = 500;
		uint32_t calibrationDelay = 8000;	// Calibration delay (milisecond)
		uint32_t stopPulse = 500;	// Stop pulse (microseconds)
		Servo myESC;		// create servo object to control an ESC
};

#endif

/* Electronic Speed Controller (ESC) - Library */
