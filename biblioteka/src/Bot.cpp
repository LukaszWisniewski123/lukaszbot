#include"../includes/Bot.hpp"
#include<queue>


using namespace Lukasz;

Bot::Bot(){
    Bot::m_vMap = Bot::m_mMap.getMap();
    Bot::m_myPos = Bot::findMyPos(Bot::m_vMap);
    Bot::m_enemyPos = Bot::findEnemyPos(Bot::m_vMap);
    std::pair<int, int> mapSize;
    mapSize = Bot::m_mMap.getMapSize();
    Bot::m_boolCopyMap = std::vector<std::vector<bool>>(mapSize.first, std::vector<bool>(mapSize.second));
}

std::pair<int,int> Bot::findEnemyPos(const std::vector<std::string> &vMap){
    std::pair<int, int> enemyPos;
    for(int i = 0; i < vMap.size(); ++i){
        std::string sTempString = vMap[i];
        for(int j = 0; j < sTempString.length(); ++j){
            char sign = sTempString[j];
            if(sign == '2'){
                enemyPos.first = i;
                enemyPos.second =j;
            }
        }
    }
    return enemyPos;
}

std::pair<int, int> Bot::findMyPos(const std::vector<std::string> &vMap){
    std::pair<int, int> mypos;
    for(int i = 0; i < vMap.size(); ++i){
        std::string sTempStrig = vMap[i];
        for(int j = 0; j < sTempStrig.length(); ++j){
            char sign = sTempStrig[j];
            if(sign == '1'){
                mypos.first = i;
                mypos.second =j;
            }
        }
    }
    return mypos;
}

void Bot::move(){
    Bot::BFS(Bot::m_myPos, Bot::m_enemyPos, Bot::m_vMap);
}

void Bot::BFS(std::pair<int, int> startPoint, std::pair<int,int> target, std::vector<std::string> &sMap){

}

void Bot::printBoolMap(){
    std::pair<int, int> size;
    size = m_mMap.getMapSize();
    for(int i =0; i < size.first; ++i){
        for(int j = 0; j < size.second; ++j){
            std::cerr<<Bot::m_boolCopyMap[i][j];
        }
        std::cerr<<std::endl;
    }
}
