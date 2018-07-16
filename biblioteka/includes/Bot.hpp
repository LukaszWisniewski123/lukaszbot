#ifndef MYBOT_H
#define MYBOT_H

#include"Map.hpp"
#include<stack>

namespace Lukasz{
    typedef std::pair<int, int> position;
    
    class Bot{
    public:
        Bot();
        void move();        
    private:
        Map m_mMap;
        
        std::vector<std::vector<bool>> m_boolCopyMap;
        std::vector<std::string> m_vMap;
        position m_myPos;
        position m_enemyPos;
        position findEnemyPos(const std::vector<std::string> &vMap);
        position findMyPos(const std::vector<std::string> &vMap);
        
        bool fieldWasVisit(const position coords);

        void BFS(position startPoint, position target, std::vector<std::string> &sMap);
        void printBoolMap();
        void setOnBoolMap(const position pos, bool var);
        bool isTheSamePos(const position pos1, const position pos2);
    };
}
#endif
