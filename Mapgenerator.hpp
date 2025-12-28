#pragma once 
#include "Map.hpp"
class MapGenerator{
public:
    virtual ~MapGenerator(){};
    virtual Map generate(int width, int height, int seed)  = 0;
};