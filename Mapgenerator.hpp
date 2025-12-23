#pragma once 
#include "Map.hpp"
#include "VoronoiPoint.hpp"
#include "BiomeSet.hpp"
#include <random>
#include <vector>
#include <cmath>
class MapGenerator{
public:
    int nob = 4;
    Map generate(int width, int height, int seed){
        Map newMap(width, height);
        std::mt19937 rnd(seed);
        std::vector<VoronoiPoint> Startingpoints;
        for (int i =0; i<20; i++){
            VoronoiPoint p;
            p.x = rnd()%width;
            p.y = rnd()%height;
            p.biometype = rnd()%nob;
            Startingpoints.push_back(p);
        }
        for (int i =0 ; i < height; i++){
            for (int j = 0 ; j < width ; j++ ){
                double distance = 100000;
                int type = -1;
                for (const auto &p : Startingpoints){
                    double newdistance = std::sqrt(std::pow((i - p.y), 2) + std::pow((j - p.x), 2));
                    if (newdistance < distance){
                        distance = newdistance;
                        type = p.biometype;
                    }
                }
                std::unique_ptr<Biome> new_biome = BiomeSet::set(type);
                newMap.at(j,i).setBiome(std::move(new_biome));
            }
        }
        return newMap;
    }
};