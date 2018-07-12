#include"../biblioteka/includes/Map.hpp"
#include<sstream>
using namespace Lukasz;

void Map::getMap(){
    std::string sTempMapSize;
    std::string sTempMap;
    std::getline(std::cin, sTempMapSize);
    while(std::getline(std::cin, sTempMap)){
        Map::vMap.push_back(sTempMap);
    }
}

bool Map::isWall(std::pair<int, int> cords){
    std::string sTemp = Map::vMap[cords.first];

    if(sTemp[cords.second] == '#'){
        return true;
    }
    else{
        return false;
    }
}
