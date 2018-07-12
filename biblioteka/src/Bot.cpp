#include"../includes/Bot.hpp"

#include<queue>


using namespace Lukasz;

Bot::Bot(){
    Bot::m_vMap = Bot::m_mMap.getMap();
    Bot::m_myPos = Bot::findMyPos(Bot::m_vMap);
    Bot::m_enemyPos = Bot::findEnemyPos(Bot::m_vMap);
}

std::pair<int,int> Bot::findEnemyPos(std::vector<std::string> &vMap){
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

std::pair<int, int> Bot::findMyPos(std::vector<std::string> &vMap){
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
