#include"../includes/Map.hpp"

#include<sstream>

using namespace Lukasz;

std::vector<std::string> Map::getMap(){
    std::string sTempMapSize;
    std::string sTempMap;

    std::vector<std::string> vTempMap;

    std::getline(std::cin, sTempMapSize);

    Map::m_mapSize = Map::findMapSize(sTempMapSize);

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

std::pair<int, int> Map::findMapSize(std::string &mapSizeLine){
    int size[2];
    std::pair<int, int> psize;
    std::string sSize;
    std::istringstream isStream;
    isStream.str(mapSizeLine);
    

    int i = 0;

    while(std::getline(isStream, sSize,' ')){
        if(i >1) break;
        if(!sSize.empty()){
            size[i] = std::stoi(sSize);
            i++;
        }
        
    }
    psize.first = size[0];
    psize.second = size[1];
    return psize;
}

std::pair<int ,int> Map::getMapSize(){
    return Map::m_mapSize;
}
