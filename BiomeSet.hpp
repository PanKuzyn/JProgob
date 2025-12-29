#pragma once
#include <memory>
#include "Biome.hpp"
class BiomeSet {
public:
    static std::unique_ptr<Biome> set(int type){
        switch(type){
            case 0:
                return std::make_unique<Water>();
                break;
            case 1: 
                return std::make_unique<Plains>();
                break;
            case 2: 
                return std::make_unique<Forest>();
                break;
            case 3: 
                return std::make_unique<Mountain>();
                break;
            case 4: 
                return std::make_unique<Beach>();
                break;
            default:
                return std::make_unique<Water>();
        }
    }
};