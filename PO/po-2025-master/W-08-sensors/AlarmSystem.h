#ifndef ALARMSYSTEM_H_
#define ALARMSYSTEM_H_

#include "Sensor.h"
#include <vector>

class AlarmSystem {
	std::vector<Sensor *> sensors;
public:
	AlarmSystem();
	~AlarmSystem();
	
	void addSensor(Sensor * sensor);
	void info();
	

};

#endif /* ALARMSYSTEM_H_ */
