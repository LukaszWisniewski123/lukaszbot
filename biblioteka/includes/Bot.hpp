#include<stack>
#include<iostream>
namespace Lukasz{
    class Bot{
    public:
        Bot();
        void getEnemyPos();
        void getMyPos();
    private:
        void DFS(std::stack<int> stack);
    };
}