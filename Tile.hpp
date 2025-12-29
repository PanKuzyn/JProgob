#pragma once
#include "BiomeSet.hpp"
#include "Biome.hpp"
#include "Objects.hpp"
#include <memory>
class Tile{
private: 
    std::unique_ptr<Biome> m_biometype;
    std::unique_ptr<Objects> m_object;
    float m_DetailValue;
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
    std::string getColor() const {
        return m_biometype -> Biome_Color();
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
    void setDetailValue(float value){
        m_DetailValue = value; 
    }
    float getDetailValue(){
        return m_DetailValue;
    }
};