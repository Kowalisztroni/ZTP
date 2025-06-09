#include <iostream>
#include "AlarmSystem.h"
#include "PressureSensor.h"
#include "TemperatureSensor.h"
#include "config.h"

int main(int argc, char **argv) 
{
	AlarmSystem alarm;
	
	/*
	TemperatureSensor ts;
	PressureSensor ps;

	alarm.addSensor(&ts);
	alarm.addSensor(&ps);
	*/
	
	alarm.addSensor(new PressureSensor());
	alarm.addSensor(new TemperatureSensor());
	
	for (int i=0; i<10; ++i)
		alarm.info();		

	return 0;
}
