
#ifndef TEMPERATURESENSOR_H_
#define TEMPERATURESENSOR_H_

#include "Sensor.h"

class TemperatureSensor: public Sensor {
	int temp = 30;
public:
	TemperatureSensor();
	~TemperatureSensor();
	
	bool isAlert() ;
};

#endif /* TEMPERATURESENSOR_H_ */
