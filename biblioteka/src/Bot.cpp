#include"../includes/Bot.hpp"

#include<queue>
#include<utility>

using namespace Lukasz;


Bot::Bot(){
    m_vMap = Bot::m_mMap.findMap();
    m_myPos = findMyPos(Bot::m_vMap);
    m_enemyPos = findEnemyPos(Bot::m_vMap);
    position mapSize;
    mapSize = m_mMap.getMapSize();
    m_boolCopyMap = std::vector<std::vector<bool>>(mapSize.first, std::vector<bool>(mapSize.second));
}
    
position Bot::findEnemyPos(const std::vector<std::string> &vMap){
    position enemyPos;
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

position Bot::findMyPos(const std::vector<std::string> &vMap){
    position mypos;
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

void Bot::printBoolMap(){
    position size;
    size = m_mMap.getMapSize();
    for(int i =0; i < size.first; ++i){
        for(int j = 0; j < size.second; ++j){
            std::cerr<<Bot::m_boolCopyMap[i][j];
        }
        std::cerr<<std::endl;
    }
}

void Bot::setOnBoolMap(const position pos, bool var=true){
    Bot::m_boolCopyMap[pos.first][pos.second] = var;
}

bool Bot::fieldWasVisit(const position coords){
    if(Bot::m_boolCopyMap[coords.first][coords.second] == true){
        return true;
    }
    else{
        return false;
    }
}

bool Bot::isTheSamePos(const std::pair<int,int>pos1, const position pos2){
    if(pos1.first == pos2.first && pos1.second == pos2.second){
        return true;
    }
    else{
        return false;
    }
}

void Bot::BFS(position startPoint, position target, std::vector<std::string> &sMap){
    
    position myNewPos;

    std::queue<position> posQueue;

    posQueue.push(startPoint);

    while(!posQueue.empty() && !isTheSamePos(myNewPos, target)){
        myNewPos = posQueue.front();
        posQueue.pop();

        position up = std::make_pair(myNewPos.first -1, myNewPos.second);
        position right = std::make_pair(myNewPos.first, myNewPos.second + 1);
        position down = std::make_pair(myNewPos.first +1, myNewPos.second);
        position left = std::make_pair(myNewPos.first, myNewPos.second -1 );

        if(!m_mMap.isWall(left) && !fieldWasVisit(left)){
            posQueue.push(left);
            setOnBoolMap(left);
        }
        if(!m_mMap.isWall(down) && !fieldWasVisit(down)){
            posQueue.push(down);
            setOnBoolMap(down);
        }
        if(!m_mMap.isWall(right) && !fieldWasVisit(right)){
            posQueue.push(right);
            setOnBoolMap(right);
        }
        if(!m_mMap.isWall(up) && !fieldWasVisit(up)){
            posQueue.push(up);
            setOnBoolMap(up);
        }
        setOnBoolMap(myNewPos);
    }
};

void Bot::move(){
    BFS(Bot::m_myPos, Bot::m_enemyPos, Bot::m_vMap);
    std::cout<<"4"<<std::endl;
}