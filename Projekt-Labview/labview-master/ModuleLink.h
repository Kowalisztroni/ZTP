/*
 * ModuleLink.h
 *
 *  Created on: May 4, 2025
 *      Author: bartek
 */

#ifndef MODULELINK_H_
#define MODULELINK_H_

#include "Module.h"
#include <memory>

class ModuleLink: public IModule {
	ModuleState state = ModuleState::BLOCKED;
	std::shared_ptr<ISource> source;
	std::shared_ptr<ISink> destination;
	int slot;
	
public:
	ModuleLink(std::shared_ptr<ISource> src, std::shared_ptr<ISink> dest, int dest_slot);
	ModuleState getState() const override;
	bool execute() override;
};

#endif /* MODULELINK_H_ */
