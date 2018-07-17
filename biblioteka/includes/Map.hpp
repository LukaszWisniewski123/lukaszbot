#ifndef MYMAP_H
#define MYMAP_H

#include<vector>
#include<string>
#include<iostream>

typedef std::pair<int,int> position;

namespace Lukasz{
    
    class Map{
    public:
        bool isWall(position coords);
        std::vector<std::string> findMap();
        position getMapSize();
    private:
        std::vector<std::string>m_map;
        position findMapSize(const std::string &mapSizeLine);
        position m_mapSize;
    };
}
#endif 
