#include"../includes/Map.hpp"

#include<sstream>

using namespace Lukasz;

std::vector<std::string> Map::findMap(){
    std::string sTempMapSize;
    std::string sTempMap;

    std::vector<std::string> vTempMap;

    std::getline(std::cin, sTempMapSize);

    Map::m_mapSize = Map::findMapSize(sTempMapSize);

    while(std::getline(std::cin, sTempMap)){
        vTempMap.push_back(sTempMap);
    }
    Map::m_map = vTempMap;
    return vTempMap;
}

bool Map::isWall(position coords){

    std::string sTempMap = m_map[coords.first];
    if(sTempMap[coords.second] == '#'){
        return true;
    }
    else{
        return false;
    }
}

position Map::findMapSize(const std::string &mapSizeLine){
    int size[2];
    position psize;
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
