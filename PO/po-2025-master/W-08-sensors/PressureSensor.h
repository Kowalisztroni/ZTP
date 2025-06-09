/*
 * PressureSensor.h
 *
 *  Created on: Apr 23, 2025
 *      Author: bartek
 */

#ifndef PRESSURESENSOR_H_
#define PRESSURESENSOR_H_

#include "Sensor.h"

class PressureSensor: public Sensor {
	int pressure = 30;
public:
	PressureSensor();
	~PressureSensor();
	bool isAlert() ;

};

#endif /* PRESSURESENSOR_H_ */
