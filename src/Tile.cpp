#include "Tile.hpp"
#include "Objects.hpp"

namespace kk{
    Tile::Tile(){}

    Tile::Tile(std::unique_ptr<Biome> biometype) : m_biometype(std::move(biometype)){}

    void Tile::setTileSymbol(std::unique_ptr<Biome> newbiome){
        m_biometype = std::move(newbiome);
    }

    char Tile::getTileSymbol() const {
        return m_biometype -> getBiomeSymbol();
    }
    
    std::string Tile::getTileColor() const {
        return m_biometype -> getBiomeColor();
    }

    void Tile::setObject(std::unique_ptr<Objects> newobject){
        m_object = std::move(newobject);
    }
    
    char Tile::getObject() const{
        return m_object -> getObjectSymbol();
    }

    bool Tile::hasObject() const{
        return m_object != nullptr;
    }

    void Tile::setDetailValue(float value){
        m_detailvalue = value; 
    }

    float Tile::getDetailValue() const{
        return m_detailvalue;
    }
    
    bool Tile::operator==(char symbol)const{
        return this->getTileSymbol() == symbol;
    }
}