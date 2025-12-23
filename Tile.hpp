#pragma once
#include "Water.hpp"
#include <memory>
class Tile{
private: 
    std::unique_ptr<Biome> m_biometype ;
public: 
    Tile() : m_biometype(std::make_unique<Water>()){
    }
    Tile(std::unique_ptr<Biome> biometype) : m_biometype(std::move(biometype)){
    }
void setBiome(std::unique_ptr<Biome> newbiome){
    m_biometype = std::move(newbiome);
}
char getBiome() const {
    return m_biometype -> Biome_Symbol();
}
};