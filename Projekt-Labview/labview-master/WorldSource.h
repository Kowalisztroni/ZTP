/*
 * WorldSource.h
 *
 *  Created on: May 4, 2025
 *      Author: bartek
 */

#ifndef WORLDSOURCE_H_
#define WORLDSOURCE_H_

#include "AbstractSource.h"

class WorldSource: public AbstractSource {
public:
	bool execute() override;
};

#endif /* WORLDSOURCE_H_ */
