#include<stack>
#include<iostream>
#include<vector>
namespace Lukasz{
    class Bot{
    public:
        Bot();
        void getEnemyPos();
        void getMyPos();
    private:
        void DFS(std::stack<int> stack);
        std::vector<std::vector<int>> v(4, std::vector<int>(4));
    };
}