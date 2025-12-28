#pragma once
#include "Biome.hpp"
class Water : public Biome{
public:
    char Biome_Symbol() override{
        return '~';
    }
};