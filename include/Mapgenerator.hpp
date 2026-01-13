#pragma once 
#include "Map.hpp"
#include <memory>
#include <vector>
#include "FastNoiseLite.h"
#include <cmath>
#include <random>
namespace kk{
    /**
     * Abstract class that allows to choose which generation method will be used during runtime
     */
    class MapGenerator{
    public:
        /**
         * Virtual destructor for managing inheriting classes destruction
         */
        virtual ~MapGenerator() = default;

        /**
         * Virtual method generating Map object 
         * @param width Map width (number of columns)
         * @param height Map height (number of rows)
         * @param seed Map seed (guarantees same outcome for same seed)
         * @return Map generated object filed with biomes
         */
        virtual Map generate(int width, int height, int seed)  = 0;
    };
    /**
     * Map Generator based on Perlin noise
     * Uses two unique layers unified into one with different significance
     */
    class PerlinNoiseGenerator : public MapGenerator{
    private:
        FastNoiseLite m_noise1; ///< Main layer for map layout look 
        FastNoiseLite m_noise2; ///< Additional layer for adding small details to the map 
        const float m_layer1freq = 0.027f; ///< First layer frequency I found to be working good 
        const float m_layer2freq = 0.09f; ///< Second layer frequency I found to be adding nice details 
    public:
        /**
         * Deafualt constructor 
         */
        PerlinNoiseGenerator();

        /**
         * Parametrized constructor for allowing to change layer frequencies
         * @param freq1 Main layer frequency
         * @param freq2 Detail layer frequency
         */
        PerlinNoiseGenerator(float freq1, float freq2);

        /**
         * Generates Map using Perlin noise 
         * Biomes are assigned depending on value of noise 
         * @param width Map width (number of columns)
         * @param height Map height (number of rows)
         * @param seed Map seed (guarantees same outcome for same seed)
         * @return Map generated object filed with biomes
         */
        Map generate(int width, int height, int seed) override;
    };
    /**
     * Structure for storing starting point of Voronoi cell 
     */
    struct VoronoiPoint{
        int x; ///< horizontal coordinate of a point
        int y; ///< vertical coordinate of a point
        int biometype; ///<type of biome assigned to a point
    };
    /**
     * Map generator based on Voronoi diagram
     * Generates number of starting points and assigns same biometype to the nearest Tiles 
     */
    class VoronoiGenerator : public MapGenerator{
    private:
        int m_numberofbiomes = Biome::getNob(); ///< Number of biomes that can be assigned to starting points 
        int m_numberofstartingpoints = 25; ///< Number of generated starting points 
        /**
         * Function for stating points generation 
         * @param width Map width (number of columns)
         * @param height Map height (number of rows)
         * @param nob Number of biomes that can be assigned to starting points
         * @param seed Map seed (guarantees same outcome for same seed)
         * @return std::vector<VoronoiPoint> List of generated points 
         */
        std::vector<VoronoiPoint> m_generatestartingpoints(int width, int height, int nob, int seed);
    public:
        /**
         * Default constructor
         */
        VoronoiGenerator();
        /**
         * Parametrized constructor allowing to change looks of the map
         * @param nob number of biomes
         * @param nosp number of starting points
         */
        VoronoiGenerator(int nob, int nosp);
        /**
         * Generates Map using Voronoi diagram 
         * Biomes are assigned based on distance to the starting point
         * @param width Map width (number of columns)
         * @param height Map height (number of rows)
         * @param seed Map seed (guarantees same outcome for same seed)
         * @return Map generated object filed with biomes
         */
        Map generate(int width, int height, int seed) override;
    };
}