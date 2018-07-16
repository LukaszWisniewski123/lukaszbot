#include"../includes/Bot.hpp"
#include<queue>
#include<utility>
using namespace Lukasz;

Bot::Bot(){
    m_vMap = Bot::m_mMap.findMap();
    m_myPos = findMyPos(Bot::m_vMap);
    m_enemyPos = findEnemyPos(Bot::m_vMap);
    std::pair<int, int> mapSize;
    mapSize = m_mMap.getMapSize();
    m_boolCopyMap = std::vector<std::vector<bool>>(mapSize.first, std::vector<bool>(mapSize.second));
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

void Bot::setOnBoolMap(const std::pair<int, int> pos, bool var=true){
    Bot::m_boolCopyMap[pos.first][pos.second] = var;
}

bool Bot::fieldWasVisit(const std::pair<int,int> coords){
    if(Bot::m_boolCopyMap[coords.first][coords.second] == true){
        return true;
    }
    else{
        return false;
    }
}

bool Bot::isTheSamePos(const std::pair<int,int>pos1, const std::pair<int, int> pos2){
    if(pos1.first == pos2.first && pos1.second == pos2.second){
        return true;
    }
    else{
        return false;
    }
}
/*tymczasowao jest voidem, ale pewnie będe zwracał chara*/

void Bot::BFS(std::pair<int, int> startPoint, std::pair<int,int> target, std::vector<std::string> &sMap){
    
    std::cerr<<"target: " <<target.first << " x " << target.second <<std::endl;

typedef std::pair<int, int> position;

    position myNewPos;

    std::queue<position> posQueue;

    posQueue.push(startPoint);

    int i = 1;
    int krok =1;
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
        
        std::cerr<<"====== "<< krok<<" ======"<<std::endl;
        printBoolMap();
        std::cerr<<"==============="<<std::endl;
        std::cerr<<"queue.size(): " << posQueue.size()<<" myNewPos: " <<myNewPos.first << " x " <<myNewPos.second<<std::endl;

        if(isTheSamePos(myNewPos, target)){
            std::cerr<<"================================="<<std::endl;
            std::cerr<<"znalazłem!:) i: " << i <<std::endl;
            std::cerr<<"================================="<<std::endl;
            i++;
        }
        krok++;
    }
};

void Bot::move(){
    BFS(Bot::m_myPos, Bot::m_enemyPos, Bot::m_vMap);
    std::cout<<"4"<<std::endl;
}