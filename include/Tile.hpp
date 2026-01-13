#pragma once
#include <string>
#include <memory>
#include "Biome.hpp"
#include "Objects.hpp"
namespace kk{
    /**
     * Tile class for managing single map tile behaviour
     */
    class Tile{
    private: 
        std::unique_ptr<Biome> m_biometype; ///< Pointer to biome type of Tile 
        std::unique_ptr<Objects> m_object; ///<Ponter to object that can be placed on Tile 
        float m_detailvalue; ///< Value for object placing 
    public: 
        /**
         * Default constructor
         */
        Tile();

        /**
         * Parametrized constructor 
         * @param biometype smart pointer to Biome class object
         */
        Tile(std::unique_ptr<Biome> biometype);

        /**
         * Function to set symbol of Tile 
         * @param newbiome smart pointer to new biome
         */
        void setTileSymbol(std::unique_ptr<Biome> newbiome);

        /**
         * Function to get symbol of Tile
         * @return ASCII symbol of biome
         */
        char GetTileSymbol() const;

        /**
         * Function to get color of Tile
         * @return ANSII color code of biome 
         */
        std::string GetTileColor() const;

        /**
         * Function to set object to a Tile 
         * @param newobject smart pointer to Object class object
         */
        void setObject(std::unique_ptr<Objects> newobject);

        /**
         * function to get object symbol
         * @return ASCII symbol of an object
         */
        char GetObject() const;

        /**
         * Function to chech wheter there is an object on a tile 
         * @return true if m_object is not empty
         */
        bool hasObject() const;

        /**
         * Function to set detail value of a Tile
         * @param value float value between -1.0f : 1.0f
         */
        void setDetailValue(float value);
        
        /**
         * Function to get detail value
         * @return stored detail value
         */
        float GetDetailValue();

        /**
         * operator ==
         * @param symbol to compare with Tile symbol
         * @return true if symbols are equal
         */
        bool operator==(char symbol)const;

    };
}