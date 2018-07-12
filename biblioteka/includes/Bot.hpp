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
        std::vector<std::string> m_vMap;
        std::pair<int, int> m_myPos;
        std::pair<int, int> m_enemyPos;

        void BFS(std::pair<int, int> startPoint, std::pair<int,int> target, std::vector<std::string> &sMap);
        std::pair<int,int> findEnemyPos(std::vector<std::string> &vMap);
        std::pair<int,int> findMyPos(std::vector<std::string> &vMap);
    };
}
#endif
