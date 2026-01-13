#pragma once
#include <memory>
#include <string>

namespace kk
{   
    /**
     *Base class for all other inheriting biome classes
     */
    class Biome{
    private:
        static const int m_nob = 4; ///< number of basic biomes needs to be equal to all derived classes of biome
    protected:
        char m_symbol; ///< ASCII Symbol that represents biome
        std::string m_color; ///< ANSII Color code of biome
    public:
        static constexpr char ws = '~'; ///< ASCII Symbol that represents Water
        static constexpr char ms = '^'; ///< ASCII Symbol that represents Mountain
        static constexpr char fs = 'Y'; ///< ASCII Symbol that represents Forest
        static constexpr char ps = '_'; ///< ASCII Symbol that represents Plains
        static constexpr char bs = '.'; ///< ASCII Symbol that represents Beach
        static constexpr char gs = ','; ///< ASCII Symbol that represents Glade 
        static constexpr const char* wc = "\x1b[38;5;45m"; ///< ANSII color code for water
        static constexpr const char* dwc = "\x1b[38;5;4m"; ///< ANSII color code for Deep Water
        static constexpr const char* mc = "\x1b[38;5;235m"; ///< ANSII color code for Mountain
        static constexpr const char* mpc = "\x1b[38;5;255m"; ///< ANSII color code for Mountain Peak
        static constexpr const char* fc = "\x1b[38;5;10m"; ///< ANSII color code for Forest
        static constexpr const char* dfc = "\x1b[38;5;22m"; ///< ANSII color code for Dark Forest
        static constexpr const char* pc = "\x1b[38;5;10m"; ///< ANSII color code for Plains
        static constexpr const char* bc = "\x1b[38;5;220m"; ///< ANSII color code for Beach
        static constexpr const char* gc = "\x1b[38;5;155m"; ///< ANSII color code for Glade
        /**
         * Default constructor
         */
        Biome();
        /**
         *Parametrized constructor for biome class
         * @param symbol ASCII symbol 
         * @param color ANSII color code
         */
        Biome(char symbol, std::string color);
        /**
         *Virtual destructor for derived classed deletion
         */
        virtual ~Biome() = default;
        /**
         *Function for getting symbolof a biome
         * @return ASCII biome symbol
         */
        virtual char getBiomeSymbol() const; 
        /**
        * Function for getting color of a biome
        * @return ANSII code for biome color
        */
        virtual std::string getBiomeColor() const;
        /**
         * Function for getting number of basic biomes
         * @return number of basic biomes
         */
        static int getNob();
        /**
         * Function for creating biomes based on identifier
         * @param type biome identifier
         * @return smart pointer to new biome object
         */
        static std::unique_ptr<Biome> setBiome(int type); 
    };
    /**
     * Basic biome Water class  
     */ 
    class Water : public Biome{
    public:
        /**
         * Deafault constructor  
         */
        Water();
        /**
         * Parametrized Constructor  
         * @param symbol ASCII symbol 
         * @param color ANSII color code
         */
        Water(char symbol, std::string color);
        
    };
    /**
     * DeepWater biome class derived from Water  
     */ 
    class DeepWater : public Water{
    public:
        /**
         * Deafault constructor  
         */
        DeepWater();
    };
    /**
     * Basic biome Plains class  
     */ 
    class Plains : public Biome{
    public:
        /**
         * Deafault constructor  
         */
        Plains();
        /**
         * Parametrized Constructor  
         * @param symbol ASCII symbol 
         * @param color ANSII color code
         */
        Plains(char symbol, std::string color);
        
    };
    /**
     * Beach biome class derived from Plains 
     */
    class Beach : public Plains{
    public:
        /**
         * Deafault constructor  
         */
        Beach();
    };
    /**
     * Basic biome Forest class  
     */ 
    class Forest : public Biome{
    public:
        /**
         * Deafault constructor  
         */
        Forest();
        /**
         * Parametrized Constructor  
         * @param symbol ASCII symbol 
         * @param color ANSII color code
         */
        Forest(char symbol, std::string color);
        
    };
    /**
     * DarkForest biome class derived from Forest
     */
    class DarkForest : public Forest{
    public:
        /**
         * Deafault constructor  
         */
        DarkForest();
    };
    /**
     * Glade biome class derived from Forest  
     */
    class Glade : public Forest{
    public:
        /**
         * Deafault constructor  
         */
        Glade();
    };
    /**
     * Basic biome Mountain class  
     */ 
    class Mountain : public Biome{
    public:
        Mountain();
        /**
         * Parametrized Constructor  
         * @param symbol ASCII symbol 
         * @param color ANSII color code
         */
        Mountain(char symbol, std::string color);
    };
    /**
     * MountainPeak biome class derived from Mountain  
     */
    class MountainPeak : public Mountain{
    public:
        /**
         * Deafault constructor  
         */
        MountainPeak();
    };
}