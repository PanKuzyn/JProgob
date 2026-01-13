#include "Map.hpp"
#include <iostream>
namespace kk{
    Map::Map(){
        m_height = 0;
        m_width = 0;
    }
    Map::Map(int width, int height): m_width(width), m_height(height){
        m_maptiles.reserve(height);
        for (int i = 0 ; i < height; i++){
            std::vector<Tile> new_row;
            new_row.reserve(width);
            for (int j=0; j<width; j++){
                auto default_biome = std::make_unique<Water>();
                new_row.emplace_back(std::move(default_biome));
            } 
            m_maptiles.emplace_back(std::move(new_row));
        }
    }
    Tile* Map::MapBoundryCheck(int x, int y){
        if( x < 0 || x >= m_width || y < 0 || y>=m_height){
            return nullptr;
        }
        else{
            return &at(x,y);
        }
    }
    bool Map::AdjecentTileCheck(int x, int y, char correctType){
        int dx[] = {0, 1, -1, 0};
        int dy[] = {-1, 0, 0, 1};
        for(int i = 0; i<4; i++){
            const Tile* neighbour = MapBoundryCheck(x+dx[i], y+dy[i]);
            if(neighbour != nullptr){
                if(*neighbour == correctType){
                    return true;
                }
            }
        }
        return false;
    }
    const Tile& Map::at(int x, int y) const{
        return m_maptiles[y][x];
    }  
    Tile& Map::at(int x, int y){
        return m_maptiles[y][x];
    }
    void Map::setHeight(int height){
        if(height < limit){
        m_height = height;
        }
        else {
            std::cout << "Map too big, will not fit in terminal";
        }
    }
    int Map::getHeight() const{
        return m_height;
    }
    void Map::setWidth(int width){
        if(width < limit){
            m_width = width;
        }
        else {
            std::cout << "Map too big, will not fit in terminal";
        }
    }
    int Map::getWidth() const{
        return m_width;
    }
}