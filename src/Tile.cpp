#include "Tile.hpp"
#include "Objects.hpp"

namespace kk{
    Tile::Tile(){
        m_biometype=std::make_unique<Water>();
        float m_detailvalue =0.0f;
    }
    Tile::Tile(std::unique_ptr<Biome> biometype) : m_biometype(std::move(biometype)), m_detailvalue(0.0f){     
    }
    void Tile::setTileSymbol(std::unique_ptr<Biome> newbiome){
        m_biometype = std::move(newbiome);
    }
    char Tile::GetTileSymbol() const {
        return m_biometype -> GetBiomeSymbol();
    } 
    std::string Tile::GetTileColor() const {
        return m_biometype -> GetBiomeColor();
    }
    void Tile::setObject(std::unique_ptr<Objects> newobject){
        m_object = std::move(newobject);
    }
    char Tile::GetObject() const{
        return m_object -> GetObjectSymbol();
    }
    bool Tile::hasObject() const{
        return m_object != nullptr;
    }
    void Tile::setDetailValue(float value){
        m_detailvalue = value; 
    }
    float Tile::GetDetailValue(){
        return m_detailvalue;
    }
    bool Tile::operator==(char symbol)const{
        return this->GetTileSymbol() == symbol;
    }



}