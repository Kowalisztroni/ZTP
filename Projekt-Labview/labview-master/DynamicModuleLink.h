/*
 * DynamicModuleLink.h
 *
 *  Created on: May 5, 2025
 *      Author: bartek
 */

#ifndef DYNAMICMODULELINK_H_
#define DYNAMICMODULELINK_H_

#include "Module.h"
#include <memory>

class DynamicModuleLink: public IModule {
	ModuleState state = ModuleState::BLOCKED;
	std::shared_ptr<ISource> source;
	std::shared_ptr<ISink> destination;
	int slot;
	
public:
	DynamicModuleLink(std::shared_ptr<IModule> src, std::shared_ptr<IModule> dest, int dest_slot);
	ModuleState getState() const override;
	bool execute() override;
};

#endif /* DYNAMICMODULELINK_H_ */
