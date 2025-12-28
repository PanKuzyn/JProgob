#include <iostream>
#include "VoronoiGenerator.hpp"
#include "PerlinNoiseGenerator.hpp"
#include "Object_placer.hpp"

MapGenerator* choosegenerator(int number){
    if(number == 1){
        return new PerlinNoiseGenerator();
    }
    else {
        return new VoronoiGenerator();
    }

}
int main(){
    int width =100;
    int height =50;
    int generator = 0 ;
    int seednumber = 3;
    // int width =0;
    // int height =0;
    // int generator = 0 ;
    // int seednumber = 0;
    // std::cout<<"Map width =  " <<std::endl;
    // std::cin >> width;
    // std::cout<<"Map height =  " <<std::endl;
    // std::cin >> height;
    // std:: cout << "Enter seed number: "<<std::endl;
    // std:: cin >> seednumber;
    std:: cout << "What type of generator would you like 1-Perlin, 2-Voronoi: "<<std::endl;
    std:: cin >> generator;
    // if(width <=0 || height <=0 || (generator != 1 && generator !=2)){
    //     std::cerr<<"Map height or width needs to be graeter than ZERO!"<<std::endl;
    //     return 1;
    // }
    // std:: cout << "Plains: _ , Water: ~ , Forest: Y , Mountain: ^  "<<std::endl;
    MapGenerator *gen = choosegenerator(generator);
    Map Mapa_test = gen -> generate(width, height, seednumber);
    Object_placer::placeObject(Mapa_test);
    for(int i=0; i < height; i++){
        for(int j =0; j < width; j++){
            auto& tile = Mapa_test.at(j, i);
            std::cout << (tile.hasObject() ? tile.getObject() : tile.getBiome());
        }
        std::cout << "\n";
    }
    delete gen;
    // system("pause");
    return 0;
}