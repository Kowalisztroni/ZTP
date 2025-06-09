/*
 * TemperatureSensor.cpp
 *
 *  Created on: Apr 23, 2025
 *      Author: bartek
 */

#include "TemperatureSensor.h"
#include <iostream>
TemperatureSensor::TemperatureSensor() : Sensor {"temperature"}
{
	// TODO Auto-generated constructor stub

}

TemperatureSensor::~TemperatureSensor()
{
	std::cout << "~TemperatureSensor" << std::endl;
}

bool TemperatureSensor::isAlert()
{
	temp+=1;
	
	return temp > 35;
}