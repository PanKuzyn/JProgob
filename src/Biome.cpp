#include "Biome.hpp"

namespace kk
{   
    Biome::Biome(){
    }
    Biome::Biome(char symbol, std::string color): m_symbol(symbol), m_color(color){
    }
    char Biome::GetBiomeSymbol() const{
        return m_symbol;
    }
    std::string Biome::GetBiomeColor() const{
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
    Water::Water(char symbol, std::string color) : Biome(symbol, color){
    }
    Water::Water() : Biome('~', "\x1b[38;5;45m") {
    }
    DeepWater:: DeepWater() : Water('~', "\x1b[38;5;4m"){
    }
    Plains::Plains(char symbol, std::string color) : Biome(symbol, color){  
    }
    Plains::Plains() : Biome('_', "\x1b[38;5;10m") {
    }
    Beach::Beach() : Plains('.',"\x1b[38;5;220m"){
    }
    Forest::Forest(char symbol, std::string color) : Biome(symbol, color){  
    }
    Forest::Forest() : Biome('Y', "\x1b[38;5;10m") {
    }
    DarkForest::DarkForest() : Forest('Y', "\x1b[38;5;22m") {
    }
    Glade::Glade() : Forest(',', "\x1b[38;5;155m"){
    }
    Mountain::Mountain(char symbol, std::string color) : Biome(symbol, color){  
    }
    Mountain::Mountain() : Biome('^', "\x1b[38;5;235m") {
    }
    MountainPeak::MountainPeak() : Mountain('^',"\x1b[38;5;255m") {
    }
}