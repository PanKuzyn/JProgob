#pragma once
#include "BiomeSet.hpp"
#include "Tree.hpp"
#include <memory>
class Tile{
private: 
    std::unique_ptr<Biome> m_biometype;
    std::unique_ptr<Objects> m_object;
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
    void setObject(std::unique_ptr<Objects> newobject){
        m_object = std::move(newobject);
    }
    char getObject() const{
        return m_object -> Object_Symbol();
    }
    bool hasObject() const{
        return m_object != nullptr;
    }
    Biome* getBiomeP(){
        return m_biometype.get();
    }
};