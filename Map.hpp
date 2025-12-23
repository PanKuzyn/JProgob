#pragma once
#include "Tile.hpp"
#include <vector>
#include <iostream>

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
    Map(int c, int r) : m_width(c), m_height(r){
        Map_tiles.reserve(r);
        for (int i = 0 ; i < r; i++){
            std::vector<Tile> new_row;
            Map_tiles.reserve(c);
            for (int j=0; j<c; j++){
                auto default_biome = std::make_unique<Water>();
                new_row.emplace_back(std::move(default_biome));
            } 
            Map_tiles.emplace_back(std::move(new_row));
        }
    }
    const Tile& at(int x, int y) const{
    return Map_tiles[y][x];
    }
    Tile& at(int x, int y){
    return Map_tiles[y][x];
    }
};