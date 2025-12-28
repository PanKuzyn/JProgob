#pragma once
#include "Objects.hpp"
class Bush : public Objects{
public:
    char Object_Symbol() override{
        return '#';
    }
};