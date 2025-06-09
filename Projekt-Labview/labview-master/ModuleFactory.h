/*
 * ModuleFactory.h
 *
 *  Created on: May 5, 2025
 *      Author: bartek
 */

#ifndef MODULEFACTORY_H_
#define MODULEFACTORY_H_

#include "Module.h"
#include <memory>
#include <string>

class ModuleFactory {
public:
	static std::shared_ptr<IModule> getInstance(const std::string & classname);
};

#endif /* MODULEFACTORY_H_ */
