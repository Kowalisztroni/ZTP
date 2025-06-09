#ifndef ABSTRACTSOURCE_H_
#define ABSTRACTSOURCE_H_

#include "Module.h"

class AbstractSource: public ISource 
{
protected:
	Signal output;
	ModuleState state = ModuleState::READY;
	
public:

	virtual ModuleState getState() const override;
	virtual Signal getResult() override;
};

#endif /* ABSTRACTSOURCE_H_ */
