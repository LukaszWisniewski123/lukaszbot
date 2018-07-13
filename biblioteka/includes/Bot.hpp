#ifndef MYBOT_H
#define MYBOT_H

#include"Map.hpp"
#include<stack>

namespace Lukasz{
    class Bot{
    public:
        Bot();
        void move();        
    private:
        Map m_mMap;
        
        std::vector<std::vector<bool>> m_boolCopyMap;
        std::vector<std::string> m_vMap;
        std::pair<int, int> m_myPos;
        std::pair<int, int> m_enemyPos;
        std::pair<int,int> findEnemyPos(const std::vector<std::string> &vMap);
        std::pair<int,int> findMyPos(const std::vector<std::string> &vMap);
        
        bool fieldWasVisit(const std::pair<int,int> coords);

        void BFS(std::pair<int, int> startPoint, std::pair<int,int> target, std::vector<std::string> &sMap);
        void printBoolMap();
        void setOnBoolMap(const std::pair<int,int> pos, bool var);
        bool isTheSamePos(const std::pair<int, int> pos1, const std::pair<int,int> pos2);
    };
}
#endif
