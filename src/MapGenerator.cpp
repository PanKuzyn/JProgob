#include "Mapgenerator.hpp"
namespace kk{
    PerlinNoiseGenerator::PerlinNoiseGenerator(){
            m_noise1.SetNoiseType(FastNoiseLite::NoiseType_Perlin);
            m_noise1.SetFrequency(m_layer1freq);
            m_noise2.SetNoiseType(FastNoiseLite::NoiseType_Perlin);
            m_noise2.SetFrequency(m_layer2freq);
    }
    PerlinNoiseGenerator::PerlinNoiseGenerator(float freq1, float freq2):m_layer1freq(freq1), m_layer2freq(freq2){
            m_noise1.SetNoiseType(FastNoiseLite::NoiseType_Perlin);
            m_noise1.SetFrequency(m_layer1freq);
            m_noise2.SetNoiseType(FastNoiseLite::NoiseType_Perlin);
            m_noise2.SetFrequency(m_layer2freq);
    }
    Map PerlinNoiseGenerator::generate(int width, int height, int seed){
        Map newMap(width, height);
        m_noise1.SetSeed(seed);
        m_noise2.SetSeed(seed+seedmodifier);
        for (int i =0 ; i < height; i++){
            for (int j = 0 ; j < width ; j++ ){
                int type;
                float layer1 = m_noise1.GetNoise((float)j, (float)i);
                float layer2 = m_noise2.GetNoise((float)j, (float)i);
                float combinednoise =layer1*noisemult1 + layer2*noisemult2;
                if (combinednoise < wthreshold){
                    type = 0;
                }
                else if (combinednoise < pthreshold){
                    type = 1;
                }
                else if (combinednoise < fthreshold){
                    type = 2;
                } 
                else{
                    type = 3;
                }
                std::unique_ptr<Biome> new_biome = Biome::setBiome(type);
                newMap.at(j,i).setTileSymbol(std::move(new_biome));
            }
        }
        return newMap;
    }

    VoronoiGenerator::VoronoiGenerator(){
    }
    VoronoiGenerator::VoronoiGenerator(int nob, int nosp):m_numberofbiomes(nob), m_numberofstartingpoints(nosp){
    }
    std::vector<VoronoiPoint> VoronoiGenerator::m_generatestartingpoints(int width, int height, int nob, int seed){
        std::mt19937 rnd(seed);
        std::vector<VoronoiPoint> startingpoints;
        startingpoints.reserve(25);
        for (int i =0; i<m_numberofstartingpoints; i++){
            VoronoiPoint p;
            p.x = rnd()%width;
            p.y = rnd()%height;
            p.biometype = rnd()%nob;
            startingpoints.push_back(p);
        }
        return startingpoints;
    }
    Map VoronoiGenerator::generate(int width, int height, int seed){
        Map newMap(width, height);
        std::vector<VoronoiPoint> startingpoints = m_generatestartingpoints(width,height,m_numberofbiomes,seed);
        for (int i =0 ; i < height; i++){
            for (int j = 0 ; j < width ; j++ ){
                double distance = 100000;
                int type = 0;
                for (const auto &p : startingpoints){
                    double newdistance = std::sqrt(std::pow((i - p.y), 2) + std::pow((j - p.x), 2));
                    if (newdistance < distance){
                        distance = newdistance;
                        type = p.biometype;
                    }
                }
                std::unique_ptr<Biome> new_biome = Biome::setBiome(type);
                newMap.at(j,i).setTileSymbol(std::move(new_biome));
            }
        }
        return newMap;
    }
}