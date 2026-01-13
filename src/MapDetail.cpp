#include "MapDetails.hpp"
namespace kk{
    MapDetails::MapDetails(int seed):m_seed(seed){
    }
    MapDetails::MapDetails(int seed, float freq):m_seed(seed), m_frequency(freq){
    }
    void MapDetails::ApplyDetails(Map& finishedMap){
        CreateDetailLayer(finishedMap);
        BiomeDetails(finishedMap);
        ObjectPlacer(finishedMap);
    }
    void MapDetails::setSeed(int seed){
        m_seed = seed;
    }
    void MapDetails::setFrequency(float freq){
        m_frequency = freq;
    }
    void MapDetails::CreateDetailLayer(Map& layer){
        FastNoiseLite Detailsnoise;
        Detailsnoise.SetNoiseType(FastNoiseLite::NoiseType_Perlin);
        Detailsnoise.SetSeed(m_seed+seedmodifier);
        Detailsnoise.SetFrequency(m_frequency);
        for (int i=0; i < layer.getHeight();i++){
            for(int j=0; j < layer.getWidth();j++){
                float value = Detailsnoise.GetNoise((float)j, (float)i);
                layer.at(j,i).setDetailValue(value);
            }
        }
    }
    void MapDetails::BiomeDetails(Map& layer){
        for(int i =0; i <layer.getHeight(); i++){
            for(int j = 0; j < layer.getWidth(); j++){
                Tile& tile = layer.at(j,i);
                float value = tile.getDetailValue();
                if(tile  == Biome::fs){
                    if(value > dfthreshold){
                        layer.at(j,i).setTileSymbol(std::make_unique<DarkForest>());
                    }
                    else if (value < gthreshold ){
                        layer.at(j,i).setTileSymbol(std::make_unique<Glade>());
                    }
                } 
                if(tile == Biome::ws){
                    if(value < dwthreshold){
                        layer.at(j, i ).setTileSymbol(std::make_unique<DeepWater>());
                    }
                }
                if(tile == Biome::ps){
                    if(layer.AdjecentTileCheck(j,i, Biome::ws)){
                        layer.at(j,i).setTileSymbol(std::make_unique<Beach>());
                    }
                }
                if(tile == Biome::ms){
                    if(value>mpthreshold){
                        layer.at(j,i).setTileSymbol(std::make_unique<MountainPeak>());
                    }
                }
            }
        }
    }
    void MapDetails::ObjectPlacer(Map& layer){
        bool SpecialObjects = false;
        for (int i = 0; i < layer.getHeight(); i++){
            for(int j = 0; j<layer.getWidth();j++){
                Tile& tile = layer.at(j,i);
                if(tile == Biome::ps){
                    if(rand()%objectrandnum < treelimit){
                    layer.at(j,i).setObject(std::make_unique<Tree>());
                    }
                    else if (rand()%objectrandnum < bushlimit){
                        layer.at(j,i).setObject(std::make_unique<Bush>());
                    }
                }
                if(!SpecialObjects && tile == Biome::ws && tile.getDetailValue()<-0.5f){
                    layer.at(j,i).setObject(std::make_unique<TreasureChest>());
                    SpecialObjects=true;
                }
            }
        }
    }
}