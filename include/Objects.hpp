#pragma once
namespace kk{
    /**
     * Abstract class for applying different objects
     */
    class Objects{
    protected:
        char m_objsymbol; ///< ASCII symbol that represents map objects
        static constexpr char bs = '#'; ///< ASCII Symbol that represents Bush
        static constexpr char ts = 'T'; ///< ASCII Symbol that represents Tree
        static constexpr char tcs = 'X'; ///< ASCII Symbol that represents Treasure Chest
    public:
        /**
         * Default constructor
         */
        Objects();
        /**
         * Parametrized constructor
         * @param objsymbol symbol of an object
         */
        Objects(char objsymbol);
        /**
         * Virtual destructor for derived classed deletion
         */
        virtual ~Objects() = default;

        /**
         * Function for getting symbol of object
         */
        virtual char getObjectSymbol() const; 
    };

    /**
     * Bush class
     */
    class Bush : public Objects{
    public:
        /**
         * Default constructor
         */
        Bush();
    };
    /**
     * Tree class
     */
    class Tree : public Objects{
    public:
        /**
         * Default constructor
         */
        Tree();
    };
    /**
     * Treasure chest class
     */
    class TreasureChest : public Objects{
    public:
        /**
         * Default constructor
         */
        TreasureChest();
    };
}


