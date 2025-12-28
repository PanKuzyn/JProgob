#pragma once
#include <memory>
#include "Plains.hpp"
#include "Water.hpp"
#include "Mountain.hpp"
#include "Forest.hpp"
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
            default:
                return std::make_unique<Water>();
        }
    }
};