/*
 * AbstractSink.cpp
 *
 *  Created on: May 4, 2025
 *      Author: bartek
 */

#include "AbstractSink.h"
#include <vector>
#include <ranges>

AbstractSink::AbstractSink(int slot_count) { slots = slot_count; }

ModuleState AbstractSink::getState() const 
{
	if (state == ModuleState::DONE or state == ModuleState::ERROR)
		return state;
	
//	bool rv = true;
//    auto required_inputs = std::ranges::iota_view{0, slots};
//
//    bool rv = std::all_of ( 
//		required_inputs.begin(), 
//		required_inputs.end(), 
//		[&](int key) { return inputs.contains(key); }
//	); 
//	if ( not rv )
//		return ModuleState::BLOCKED;
	
	// do we have all inputs ?
	for (int slot=0; slot<slots; ++slot)
		if (not inputs.contains(slot))
			return ModuleState::BLOCKED;
	
	return ModuleState::READY;
}


void AbstractSink::setInput(const Signal & s, int slot)
{
		inputs[slot] = s;
}