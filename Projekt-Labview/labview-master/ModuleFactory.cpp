/*
 * ModuleFactory.cpp
 *
 *  Created on: May 5, 2025
 *      Author: bartek
 */

#include "ModuleFactory.h"
#include "Concatenate.h"
#include "HelloSource.h"
#include "WorldSource.h"
#include "NormalCoutSink.h"
#include <memory>
#include <iostream>

std::shared_ptr<IModule> ModuleFactory::getInstance(const std::string & classname)
{
	if (classname == "HelloSource")
		return std::make_shared<HelloSource>();
	
	if (classname == "WorldSource")
		return std::make_shared<WorldSource>();
	
	// mimo iż klasy w hierarchii to czyste interfejsy - tu mamy "diamond problem" przy upcastingu
	// obchodzimy wskazując "ścieżkę" castowania - obojętne, czy wskażemy ISource czy ISink
	if (classname == "Concatenate")
		return std::static_pointer_cast<ISource>(std::make_shared<Concatenate>(2));

	if (classname == "NormalCoutSink")
		return std::make_shared<NormalCoutSink>(1);

	std::cout << "Unable to build: " << classname << std::endl;
	return nullptr;
}
