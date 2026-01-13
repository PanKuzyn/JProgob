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
        Detailsnoise.SetSeed(m_seed+3);
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
                float value = tile.GetDetailValue();
                if(tile  == 'Y'){
                    if(value > 0.3f){
                        layer.at(j,i).setTileSymbol(std::make_unique<DarkForest>());
                    }
                    else if (value < -0.6f ){
                        layer.at(j,i).setTileSymbol(std::make_unique<Glade>());
                    }
                } 
                if(tile == '~'){
                    if(value < -0.2f){
                        layer.at(j, i ).setTileSymbol(std::make_unique<DeepWater>());
                    }
                }
                if(tile == '_'){
                    if(layer.AdjecentTileCheck(j,i, '~')){
                        layer.at(j,i).setTileSymbol(std::make_unique<Beach>());
                    }
                }
                if(tile == '^'){
                    if(value>0.8f){
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
                if(tile == '_'){
                    if(rand()%400 < 5){
                    layer.at(j,i).setObject(std::make_unique<Tree>());
                    }
                    else if (rand()%400 < 10){
                        layer.at(j,i).setObject(std::make_unique<Bush>());
                    }
                }
                if(!SpecialObjects && tile=='~' && tile.GetDetailValue()<-0.5f){
                    layer.at(j,i).setObject(std::make_unique<TreasureChest>());
                    SpecialObjects=true;
                }
        }
        }
    }
        

}