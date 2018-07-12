#ifndef MYMAP_H
#define MYMAP_H

#include<vector>
#include<string>
#include<iostream>

namespace Lukasz{
    
    class Map{
    public:
        std::vector<std::string> getMap();
        bool isWall(std::pair<int, int> coords);
    };
}
#endif 
