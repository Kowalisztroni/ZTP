/*
 * LabView.h
 *
 *  Created on: May 5, 2025
 *      Author: bartek
 */

#ifndef LABVIEW_H_
#define LABVIEW_H_

#include "Module.h"
#include <memory>
#include <string>
#include <map>

class LabView {
	std::map<std::string, std::shared_ptr<IModule>> modules;	// all modules
	
public:
	void add_module(const std::string & module_name, std::shared_ptr<IModule> m);
	void connect (const std::string & src, const std::string & dst, int slot);
	
	void run();
};

#endif /* LABVIEW_H_ */
