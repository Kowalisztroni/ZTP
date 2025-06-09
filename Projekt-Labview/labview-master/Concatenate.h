/*
 * Concatenate.h
 *
 *  Created on: May 4, 2025
 *      Author: bartek
 */

#ifndef CONCATENATE_H_
#define CONCATENATE_H_

#include "AbstractTransform.h"

class Concatenate: public AbstractTransform {
public:
	using AbstractTransform::AbstractTransform;
	
	bool execute() override;
};

#endif /* CONCATENATE_H_ */
