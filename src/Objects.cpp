#include "Objects.hpp"
namespace kk{
    Objects::Objects(){
    }
    Objects::Objects(char objsymbol):m_objsymbol(objsymbol){
    }
    char Objects::GetObjectSymbol() const{
        return m_objsymbol;
    }
    Bush::Bush():Objects('#'){
    }
    Tree::Tree():Objects('T'){
    }
    TreasureChest::TreasureChest():Objects('X'){
    }
}