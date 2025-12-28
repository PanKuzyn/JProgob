#pragma once
#include "Objects.hpp"
class Sand : public Objects{
public:
    char Object_Symbol() override{
        return '.';
    }
};