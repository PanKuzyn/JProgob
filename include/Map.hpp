#pragma once
#include "Tile.hpp"
#include <vector>
namespace kk{
    /**
     * Class for storing and managing 2D map of Tiles
     */
    class Map {
    private:
        int m_width; ///< Map width (number of columns in a vector)
        int m_height; ///< Map height (number of rows in a vector)
        std::vector<std::vector<Tile>> m_maptiles; ///< 2D vector of Tiles

        /**
         * Function for checking wheter coordinates of tiles are inside it's boundry
         * @param x horizontal coordinate
         * @param y vertical coordinate
         * @return Tile* if coordinates are good and nullptr when outside boundry
         */
        Tile* MapBoundryCheck(int x, int y);
    public:
        /**
         * default constructor that creates 0x0 size map 
         */
        Map();

        /**
         * Parametrized constructor that creates 2D map vector of given width and height and fills each tile by default with Water biome
         * @param x width of a map
         * @param y height of a map
         */
        Map(int width, int height);

        /**
         * Function for checking neighbouring tiles biome types, checks in 4 directions  
         * @param x horizontal coordinate
         * @param y vertical coordinate
         * @param correctType searched biome ASCII symbol
         * @return true if there is at least one neighbour with requested symbol, false if none of the neighbours has requested symbol
         */
        bool AdjecentTileCheck(int x, int y, char correctType);

        /**
         * Function only for reading tile at given coordinates
         * @param x horizontal coordinate
         * @param y vertical coordinate
         * @return const Tile& reference to tile  
         */
        const Tile& at(int x, int y) const;

        /**
         * Function to control tile at given coordinates
         * @param x horizontal coordinate
         * @param y vertical coordinate
         * @return Tile& reference to tile  
         */
        Tile& at(int x, int y);

        /**
         * Function to set height of a Map and check if it is not too big 
         * @param height height of Map
         */
        void setHeight(int height);

        /**
         * Function to get height of Map
         * @return height of map 
         */
        int getHeight() const;

        /**
         * Function to set width of Map and check if it is not too big 
         * @param width width of Map
         */
        void setWidth(int width);

        /**
         * Function to get width of Map
         * @return width of map
         */
        int getWidth() const;
    };
}