#ifndef ABSTRACTTRANSFORM_H_
#define ABSTRACTTRANSFORM_H_

#include "Module.h"
#include <map>

class AbstractTransform: public ITransform {
protected:	
	ModuleState state = ModuleState::BLOCKED;

	std::map<int, Signal> inputs;
	int slots;
	
	Signal output;

public:
	explicit AbstractTransform(int slot_count);
	
	virtual ModuleState getState() const override;
	virtual void setInput(const Signal & s, int slot) override;
	virtual Signal getResult() override;
};

#endif /* ABSTRACTTRANSFORM_H_ */
