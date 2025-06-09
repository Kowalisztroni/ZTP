/*
 * AbstractSink.h
 *
 *  Created on: May 4, 2025
 *      Author: bartek
 */

#ifndef ABSTRACTSINK_H_
#define ABSTRACTSINK_H_

#include <map>

#include "Module.h"


class AbstractSink: public ISink 
{
protected:
	std::map<int, Signal> inputs;
	int slots;
	
	ModuleState state = ModuleState::BLOCKED;
	
public:
	explicit AbstractSink(int slot_count);
	
	virtual ModuleState getState() const override;
	virtual void setInput(const Signal & s, int slot) override;

};

#endif /* ABSTRACTSINK_H_ */
