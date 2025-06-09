/*
 * NormalCoutSink.h
 *
 *  Created on: Apr 30, 2025
 *      Author: bartek
 */

#ifndef NORMALCOUTSINK_H_
#define NORMALCOUTSINK_H_

#include "AbstractSink.h"
#include <vector>

class NormalCoutSink: public AbstractSink {
	
public:
	using AbstractSink::AbstractSink;
	
	bool execute() override;

};

#endif /* NORMALCOUTSINK_H_ */
