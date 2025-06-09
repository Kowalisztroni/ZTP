#ifndef MODULE_H_
#define MODULE_H_

#include "Signal.h"

enum class ModuleState { 
	BLOCKED, 	// module is waiting for data
	READY, 		// module is ready to be executed
	ERROR, 		// module was executed, but there was some error
	DONE 		// module was successfully executed 
};



class IModule 
{
public:
	virtual ModuleState getState() const = 0;	
	virtual bool execute() = 0;
	virtual ~IModule() = default;
};

class ISource : public IModule
{
public:
	virtual Signal getResult() = 0;
	virtual ~ISource() = default;	
};

class ISink : public IModule {
public:
	virtual void setInput(const Signal & s, int slot) = 0;
	virtual ~ISink() = default;	
};

class ITransform: public ISource, public ISink {
public:
	virtual ~ITransform() = default;
};


#endif /* MODULE_H_ */
