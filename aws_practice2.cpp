#include <iostream>
#include <list>
using namespace std;

//lists=[[1,4,5],[1,3,4],[2,6]] output:[1,1,2,3,4,4,5,6]

list<int> mergeksortlist(list<list<int>> lists)
{
    if (lists.empty()) {
        return {};
    }

    list<int> result;
    result = lists.front();
    auto it = ++lists.begin(); // 获取迭代器指向第二个列表
    for (; it != lists.end(); ++it) {
        result.merge(*it); // 将当前列表 *it 合并到 result 中
    }
    return result;
}

int main() {
    //list<list<int>> lists = {{1,4,5},{1,3,4},{2,6}};
    list<list<int>> lists ={{}};
    list<int> result;
    
    result=mergeksortlist(lists);
    for(auto i:result)
    {
        cout<<i<<" ";
    }
    

    return 0;
}
