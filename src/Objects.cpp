#include "Objects.hpp"
namespace kk{
    Objects::Objects(){}

    Objects::Objects(char objsymbol):m_objsymbol(objsymbol){}

    char Objects::getObjectSymbol() const{
        return m_objsymbol;
    }

    Bush::Bush():Objects(bs){
    }

    Tree::Tree():Objects(ts){
    }
    
    TreasureChest::TreasureChest():Objects(tcs){
    }
}