#ifndef MYMAP_H
#define MYMAP_H

#include<vector>
#include<string>
#include<iostream>

namespace Lukasz{
    
    class Map{
    public:
        void getMap();
        bool isWall(std::pair<int, int> cords);
    private:
        std::vector<std::string> vMap;
        void getMapSize(std::string &tempMapSize);
        int iMapSize[2];
    };
}
#endif 