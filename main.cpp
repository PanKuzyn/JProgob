#include <iostream>
#include "Mapgenerator.hpp"

int main(){
    int width =0;
    int height =0;
   
    int seednumber = 0;
    std::cout<<"Map width =  " <<std::endl;
    std::cin >> width;
    std::cout<<"Map height =  " <<std::endl;
    std::cin >> height;
    std:: cout << "Enter seed number: "<<std::endl;
    std:: cin >> seednumber;
    if(width <=0 || height <=0 ){
        std::cerr<<"Map height or width needs to be graeter than ZERO!"<<std::endl;
        return 1;
    }
    MapGenerator gen;
    Map Mapa_test = gen.generate(width, height, seednumber);
        for(int y=0; y < height; y++){
            for(int x =0; x < width; x++){
                std::cout << Mapa_test.at(x, y).getBiome();
            }
             std::cout << "\n";
        }
    return 0;
}