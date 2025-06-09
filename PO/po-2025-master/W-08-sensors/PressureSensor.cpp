/*
 * PressureSensor.cpp
 *
 *  Created on: Apr 23, 2025
 *      Author: bartek
 */

#include "PressureSensor.h"
#include <iostream>
PressureSensor::PressureSensor() : Sensor {"pressure"}
{
	// TODO Auto-generated constructor stub

}

PressureSensor::~PressureSensor()
{
	std::cout << "~PressureSensor" << std::endl;
}

bool PressureSensor::isAlert()
{
	pressure+=1;
	
	return pressure > 38;
}