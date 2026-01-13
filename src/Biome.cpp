#include "Biome.hpp"

namespace kk
{   
    Biome::Biome(){}

    Biome::Biome(char symbol, std::string color): m_symbol(symbol), m_color(color){}

    char Biome::getBiomeSymbol() const{
        return m_symbol;
    }

    std::string Biome::getBiomeColor() const{
        return m_color;
    }

    int Biome::getNob(){
        return m_nob;
    }

    std::unique_ptr<Biome> Biome::setBiome(int type){
        switch(type){
                case 0:
                    return std::make_unique<Water>();
                case 1: 
                    return std::make_unique<Plains>();
                case 2: 
                    return std::make_unique<Forest>();
                case 3: 
                    return std::make_unique<Mountain>();
                default:
                    return std::make_unique<Water>();
            }
    }

    Water::Water(char symbol, std::string color) : Biome(symbol, color){}

    Water::Water() : Biome(ws, wc) {}

    DeepWater:: DeepWater() : Water(ws, dwc){}

    Plains::Plains(char symbol, std::string color) : Biome(symbol, color){}

    Plains::Plains() : Biome(ps, pc) {}

    Beach::Beach() : Plains(bs, bc){}

    Forest::Forest(char symbol, std::string color) : Biome(symbol, color){}

    Forest::Forest() : Biome(fs, fc){}

    DarkForest::DarkForest() : Forest(fs, dfc){}

    Glade::Glade() : Forest(gs, gc){}

    Mountain::Mountain(char symbol, std::string color) : Biome(symbol, color){}

    Mountain::Mountain() : Biome(ms, mc){}

    MountainPeak::MountainPeak() : Mountain(ms, mpc){}
}