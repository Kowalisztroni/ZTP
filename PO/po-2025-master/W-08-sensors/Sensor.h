#ifndef SENSOR_H_
#define SENSOR_H_

#include <string>
class Sensor {
	std::string id;
public:
	explicit Sensor (const std::string & sensor_id);
	virtual ~Sensor();
	virtual bool isAlert() = 0;
	std::string getId() const { return id; }
};

#endif /* SENSOR_H_ */
