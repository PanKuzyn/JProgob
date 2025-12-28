#pragma once
#include "Tile.hpp"
#include <vector>
class Map {
private:
    int m_width;
    int m_height;
    std::vector<std::vector<Tile>> Map_tiles;
public:
    Map(){
        m_height = 0;
        m_width = 0;
    }
    Map(int x, int y) : m_width(x), m_height(y){
        Map_tiles.reserve(y);
        for (int i = 0 ; i < y; i++){
            std::vector<Tile> new_row;
            Map_tiles.reserve(x);
            for (int j=0; j<x; j++){
                auto default_biome = std::make_unique<Water>();
                new_row.emplace_back(std::move(default_biome));
            } 
            Map_tiles.emplace_back(std::move(new_row));
        }
    }
    bool AdjecentTileCheck(int x, int y, char correctType){
        int dx[] = {0, 1, -1, 0};
        int dy[] = {-1, 0, 0, 1};
        for(int i = 0; i<4; i++){
            Tile* neighbour = MapBoundryCheck(x+dx[i], y+dy[i]);
            if(neighbour != nullptr){
                if(neighbour->getBiome() == correctType){
                    return true;
                }
            }
        }
        return false;
    }
    Tile* MapBoundryCheck(int x, int y){
        if( x < 0 || x >= m_width || y < 0 || y>=m_height){
            return nullptr;
        }
        else{
            return &at(x,y);
        }
    }
    const Tile& at(int x, int y) const{
        return Map_tiles[y][x];
    }
    Tile& at(int x, int y){
        return Map_tiles[y][x];
    }
    void setHeight(int height){
        m_height = height;
    }
    int getHeight() const{
        return m_height;
    }
    void setWidth(int width){
        m_width = width;
    }
    int getWidth() const{
        return m_width;
    }
};