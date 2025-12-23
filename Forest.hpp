#pragma once
#include "Biome.hpp"
class Forest : public Biome{
    public:
        char Biome_Symbol() override{
            return 'Y';
        }

};