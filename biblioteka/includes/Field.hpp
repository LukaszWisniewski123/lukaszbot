#ifndef MYFIELD_H
#define MYFIELD_H

#include <iostream>

typedef std::pair<int, int> position;

namespace Lukasz{
    class Field{
    public:
        Field(position myPos, position parentPos);
        position getParent();
    private:
        position m_myPos;
        position m_parentPos;
    };
}

#endif