#ifndef DWARF_H__
#define DWARF_H__

#include <string>
#include "Unit.h"

class Dwarf : public Unit {

public:
    explicit Dwarf (const std::string & name);

    int getAttackStr() const;
};


#endif