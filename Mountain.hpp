#pragma once
#include "Biome.hpp"
class Mountain : public Biome{
    public:
        char Biome_Symbol() override{
            return '^';
        }
};