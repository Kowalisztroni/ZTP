#ifndef HELLOSOURCE_H_
#define HELLOSOURCE_H_

#include "AbstractSource.h"
#include "Module.h"

class HelloSource: public AbstractSource {
	
public:	
	bool execute() override;
};

#endif /* HELLOSOURCE_H_ */
