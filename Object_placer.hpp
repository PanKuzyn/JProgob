#pragma once
#include "Tree.hpp"
#include "Bush.hpp"
#include "Rock.hpp"
#include "Map.hpp"
#include <random>
class Object_placer{
public:
    static void placeObject(Map& map){
        for (int i = 0; i <map.getHeight(); i++){
            for (int j = 0; j <  map.getWidth(); j++){
                Biome* currentbiome = map.at(j,i).getBiomeP();
                if (currentbiome -> Biome_Symbol() == 'Y'){
                    if(std::rand() % 150 < 20){
                        map.at(j, i ).setObject(std::make_unique<Tree>());
                    }
                }
                if (currentbiome -> Biome_Symbol() == '_'){
                    if(map.AdjecentTileCheck(j, i, '~')){
                        map.at(j, i ).setObject(std::make_unique<Sand>());
                    }
                    else if(std::rand() % 250 < 10){
                        map.at(j, i ).setObject(std::make_unique<Bush>());
                    }
                }

            }
        }
    }
};