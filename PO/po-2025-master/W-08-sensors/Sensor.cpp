
#include "Sensor.h"
#include <iostream>

Sensor::Sensor(const std::string & sensor_id) : id {sensor_id}
{
	
}

Sensor::~Sensor()
{
	std::cout << "~Sensor" << std::endl;
}