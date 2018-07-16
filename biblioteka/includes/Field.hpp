#include<iostream>

typedef std::pair<int,int> position;

namespace Lukasz{
    class Field{
    public:
        position getPatent();
        void setParent(position pos);
    private:
        position parentPos;
        position curentPos;

    };
}