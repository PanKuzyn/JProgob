#pragma once
#include "Objects.hpp"
#include "Map.hpp"
#include "FastNoiseLite.h"
class MapDetails{
private:
    static void CreateDetailLayer(Map& layer, int seed){
        FastNoiseLite Detailsnoise;
        Detailsnoise.SetNoiseType(FastNoiseLite::NoiseType_Perlin);
        Detailsnoise.SetSeed(seed*2);
        Detailsnoise.SetFrequency(0.2f);
        for (int i=0; i < layer.getHeight();i++){
            for(int j=0; j < layer.getWidth();j++){
                float value = Detailsnoise.GetNoise((float)j, (float)i);
                layer.at(j,i).setDetailValue(value);
            }
        }
    }
    static void BiomeDetails(Map& layer){
        for(int i =0; i <layer.getHeight(); i++){
            for(int j = 0; j < layer.getWidth(); j++){
                Tile& tile = layer.at(j,i);
                float value = tile.getDetailValue();
                char currentBiome = tile.getBiome();
                if(currentBiome  == 'Y'){
                    if(value > 0.3f){
                        layer.at(j,i).setBiome(std::make_unique<DarkForest>());
                    }
                    else if (value < -0.6f ){
                        layer.at(j,i).setBiome(std::make_unique<Glade>());
                    }
                } 
                if(currentBiome == '~'){
                    if(value < -0.2f){
                        layer.at(j, i ).setBiome(std::make_unique<DeepWater>());
                    }
                }
                if(currentBiome == '_'){
                    if(layer.AdjecentTileCheck(j,i, '~')){
                        layer.at(j,i).setBiome(std::make_unique<Beach>());
                    }
                }
                if(currentBiome == '^'){
                    if(value>0.8f){
                        layer.at(j,i).setBiome(std::make_unique<MountainPeaks>());
                    }
                }

            }
        }
    }
    static void ObjectPlacer(Map& layer){
        bool SpecialObjects = false;
        for (int i = 0; i < layer.getHeight(); i++){
           for(int j = 0; j<layer.getWidth();j++){
                Tile& tile = layer.at(j,i);
                char currentBiome = tile.getBiome(); 
                if(currentBiome == '_'){
                    if(rand()%400 < 5){
                    layer.at(j,i).setObject(std::make_unique<Tree>());
                    }
                    else if (rand()%400 < 10){
                        layer.at(j,i).setObject(std::make_unique<Bush>());
                    }
                }
                if(!SpecialObjects && currentBiome=='~' && tile.getDetailValue()<-0.5f){
                    layer.at(j,i).setObject(std::make_unique<TreasureChest>());
                    SpecialObjects=true;
                }
           }
        }
    }
public:
    static void ApplyDetails(Map& finishedMap, int seed){
        CreateDetailLayer(finishedMap, seed);
        BiomeDetails(finishedMap);
        ObjectPlacer(finishedMap);
    }
    
};