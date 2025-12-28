#pragma once 
#include "Mapgenerator.hpp"
#include <vector>
#include "FastNoiseLite.h"
class PerlinNoiseGenerator : public MapGenerator{
public:
    Map generate(int width, int height, int seed) override{
        Map newMap(width, height);
        FastNoiseLite noise1; 
        FastNoiseLite noise2; 
        noise1.SetNoiseType(FastNoiseLite::NoiseType_Perlin);
        noise1.SetSeed(seed);
        noise1.SetFrequency(0.027f);
        noise2.SetNoiseType(FastNoiseLite::NoiseType_Perlin);
        noise2.SetSeed(seed);
        noise2.SetFrequency(0.09f);
        for (int i =0 ; i < height; i++){
            for (int j = 0 ; j < width ; j++ ){
                int type;
                float layer1 = noise1.GetNoise((float)j, (float)i);
                float layer2 = noise2.GetNoise((float)j, (float)i);
                float combinednoise =layer1*0.85f + layer2*0.15f;
                if (combinednoise < 0.0f){
                    type = 0;
                }
                else if (combinednoise<0.15f){
                    type = 1;
                }
                else if (combinednoise <0.4f){
                    type = 2;
                } 
                else{
                    type = 3;
                }
                std::unique_ptr<Biome> new_biome = BiomeSet::set(type);
                newMap.at(j,i).setBiome(std::move(new_biome));
            }
        }
        return newMap;
    }
};