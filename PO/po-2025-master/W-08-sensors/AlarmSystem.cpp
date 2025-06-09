#include "AlarmSystem.h"
#include <iostream>

AlarmSystem::AlarmSystem() {
	// TODO Auto-generated constructor stub

}

AlarmSystem::~AlarmSystem() {
	for (auto s: sensors)
		delete s;
}

void AlarmSystem::addSensor(Sensor * sensor)
{
	sensors.push_back(sensor);	
}

void AlarmSystem::info()
{
	for (auto s: sensors)
	{
		std::cout << s->getId() << " " << std::boolalpha << s->isAlert() << std::endl;
	}	
}