#pragma once
#include "Objects.hpp"
class Tree : public Objects{
public:
    char Object_Symbol() override{
        return '+';
    }
};