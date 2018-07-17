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
    bool targeIsFind = false;
    position myNewPos;
    const position mapSize = m_mMap.getMapSize();
    std::queue<position> posQueue;
    std::vector<std::vector<position> > vParent(mapSize.first, std::vector<position>(mapSize.second));
    
    posQueue.push(startPoint);

    while(!posQueue.empty()){
        myNewPos = posQueue.front();
        posQueue.pop();

        position up = std::make_pair(myNewPos.first -1, myNewPos.second);
        position right = std::make_pair(myNewPos.first, myNewPos.second + 1);
        position down = std::make_pair(myNewPos.first +1, myNewPos.second);
        position left = std::make_pair(myNewPos.first, myNewPos.second -1 );

        if(!m_mMap.isWall(left) && !fieldWasVisit(left)){
            vParent[left.first][left.second] = myNewPos;
            posQueue.push(left);
            setOnBoolMap(left);
        }
        if(!m_mMap.isWall(down) && !fieldWasVisit(down)){
            vParent[down.first][down.second] = myNewPos;
            posQueue.push(down);
            setOnBoolMap(down);
        }
        if(!m_mMap.isWall(right) && !fieldWasVisit(right)){
            vParent[right.first][right.second] = myNewPos;
            posQueue.push(right);
            setOnBoolMap(right);
        }
        if(!m_mMap.isWall(up) && !fieldWasVisit(up)){
            vParent[right.first][right.second] = myNewPos;
            posQueue.push(up);
            setOnBoolMap(up);
        }
        setOnBoolMap(myNewPos);
        
        printBoolMap();
        std::cerr<<"============================"<<std::endl;

        if(isTheSamePos(myNewPos, target)){
            targeIsFind = true;
            break;
        }
    }
    if(targeIsFind){
        position parent;
        position child;
        while(!isTheSamePos(myNewPos, m_myPos)){
            parent = vParent[myNewPos.first][myNewPos.second];
            child = myNewPos;
            myNewPos = parent;
        }
        std::cerr<<"myNewPos: " <<myNewPos.first << " x " <<myNewPos.second <<std::endl;
        std::cerr<<"parent: " <<parent.first << " x " <<parent.second <<std::endl;
        std::cerr<<"child: " <<child.first << " x " <<child.second <<std::endl;

        position up = std::make_pair(myNewPos.first -1, myNewPos.second);
        position right = std::make_pair(myNewPos.first, myNewPos.second + 1);
        position down = std::make_pair(myNewPos.first +1, myNewPos.second);
        position left = std::make_pair(myNewPos.first, myNewPos.second -1 );

        std::cerr<<"up: " <<up.first << " x " <<up.second <<std::endl;
        std::cerr<<"right: " <<right.first << " x " <<right.second <<std::endl;
        std::cerr<<"down: " <<down.first << " x " <<down.second <<std::endl;
        std::cerr<<"left: " <<left.first << " x " <<left.second <<std::endl;

        if(isTheSamePos(child, up)){
            std::cout<<"1"<<std::endl;
        }
        else if(isTheSamePos(child, right)){
            std::cout<<"2"<<std::endl;
        }
    }
};

void Bot::move(){
    BFS(Bot::m_myPos, Bot::m_enemyPos, Bot::m_vMap);
}