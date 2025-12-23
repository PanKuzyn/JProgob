#pragma once
#include "Biome.hpp"
class Plains : public Biome{
    public:
        char Biome_Symbol() override{
            return '_';
        }

};
