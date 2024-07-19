// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    stack<int> s;
    s.push(node);
    while (!s.empty())
    {
        int v = s.top();
        s.pop();
        // pop 了node 之後要把和node相鄰的節點push進來
        if (!visited[v]) {
            visited[v] = true; //表示那個節點訪問過了
            for(int j=0 ; j < adj[v].size() ; j++) {
                
                if (!visited[adj[v][j]]) {
                    s.push(adj[v][j]);
                }
            }
        }
    }
}

int mincosttomakelib(int n, int m, int c_lib, int c_road,vector<vector<int>> cities){
    vector<vector<int> > graph(n+1);
    
    //make graph
    for(int i=0;i<cities.size();i++)
    {
        graph[cities[i][0]].push_back(cities[i][1]);
        graph[cities[i][1]].push_back(cities[i][0]);
    }
    
    vector<bool> visited(n + 1, false); //use to triage
    int components = 0; //表示總共有幾個聯通圖極為所需lib數量
    
    //////
    // Find all connected components
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i, graph, visited);
            components++;
        }
    }
    
    int total_cost = components * c_lib + (n - components) * c_road;
    
    ////
    return total_cost;
}

int main() {
    int n = 3;  // 城市數量
    int m = 3;  // 可以建造的道路數量
    int c_lib = 2;  // 建造圖書館的成本
    int c_road = 1;  // 建造道路的成本
    vector<vector<int> > cities = {{1, 2}, {3, 1}, {2, 3}};
    
    int result = mincosttomakelib(n, m, c_lib, c_road, cities);
    cout << result << endl;
    
    return 0;
}
