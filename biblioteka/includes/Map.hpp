#ifndef MYMAP_H
#define MYMAP_H

#include<vector>
#include<string>
#include<iostream>

namespace Lukasz{
    
    class Map{
    public:
        bool isWall(std::pair<int, int> coords);
        std::vector<std::string> getMap();
        std::pair<int, int> getMapSize();
    private:
        std::pair<int, int> findMapSize(std::string &mapSizeLine);
        std::pair<int, int> m_mapSize;
    };
}
#endif 
