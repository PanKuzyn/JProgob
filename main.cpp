#include <iostream>
#include "MapGenerator.hpp"
#include "MapDetails.hpp"
#include <memory>

std::unique_ptr<kk::MapGenerator> choosegenerator(int number){
    if(number == 1){
        return std::make_unique<kk::PerlinNoiseGenerator>();
    }
    else {
        return std::make_unique<kk::VoronoiGenerator>();
    }
}

int main(){
    int width =100;
    int height =50;
    int seednumber = 3;
    int generator = 0;
    // int width =0;
    // int height =0;
    // int seednumber = 0;
    // std::cout<<"Map width =  " <<std::endl;
    // std::cin >> width;
    // std::cout<<"Map height =  " <<std::endl;
    // std::cin >> height;
    // std:: cout << "Enter seed number: "<<std::endl;
    // std:: cin >> seednumber;
    // if(width <=0 || height <=0 || (generator != 1 && generator !=2)){
    //     std::cerr<<"Map height or width needs to be graeter than ZERO!"<<std::endl;
    //     return 1;
    // }
    std:: cout << "What type of generator would you like 1-Perlin, 2-Voronoi: "<<std::endl;
    std:: cin >> generator;
    std:: cout << "Plains: _ ; Water: ~ ; Forest: Y ; Mountain: ^ ; Glade: , ; Beach: . "<<std::endl;
    std::unique_ptr<kk::MapGenerator> gen = choosegenerator(generator);
    kk::Map Mapa_test = gen -> generate(width, height, seednumber);
    kk::MapDetails AddDetails(seednumber);
    AddDetails.ApplyDetails(Mapa_test);
    for(int i=0; i < height; i++){
        for(int j =0; j < width; j++){
            auto& tile = Mapa_test.at(j, i);
            if (tile.hasObject()){
            std::cout << tile.getObject();
            }
            else{
            std::cout << tile.getTileColor() << tile.getTileSymbol() <<"\x1b[0m";
            }
        }
        std::cout << "\n";
    }
    
    // system("pause");
    return 0;
}