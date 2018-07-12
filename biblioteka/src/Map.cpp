#include"../biblioteka/includes/Map.hpp"

#include<sstream>

using namespace Lukasz;

std::vector<std::string> Map::getMap(){
    std::string sTempMapSize;
    std::string sTempMap;

    std::vector<std::string> vTempMap;

    std::getline(std::cin, sTempMapSize);

    while(std::getline(std::cin, sTempMap)){
        vTempMap.push_back(sTempMap);
    }
    return vTempMap;
}

bool Map::isWall(std::pair<int, int> coords){
    std::vector<std::string> vTempMap = Map::getMap();
    std::string sTempMap = vTempMap[coords.first];

    if(sTempMap[coords.second] == '#'){
        return true;
    }
    else{
        return false;
    }
}
