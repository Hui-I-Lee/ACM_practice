#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K)
    {
        vector<vector<int>> result;
        
        auto comp = []( vector<int> a, vector<int> b ) { return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1]; };
        priority_queue<vector<int>, vector<vector<int>>, decltype( comp )> maxPQ(comp);
        
        for (auto point : points)  // auto point=points.begin(); point!=points.end; point++
        {
            if (maxPQ.size() < K)
            {
                maxPQ.push(point);
            }     //先放進queue
            else
            {
                vector<int> maxPoint = maxPQ.top();
                int maxDistance = maxPoint[0] * maxPoint[0] + maxPoint[1] * maxPoint[1];
                int curDistance = point[0] * point[0] + point[1] * point[1];
                if (maxDistance > curDistance)
                {
                    maxPQ.pop();
                    maxPQ.push(point);
                }
            }
        }
        
        while(maxPQ.size() != 0)
        {
            result.push_back(maxPQ.top());
            maxPQ.pop();
        }

        return result;
    }
};

bool sortFunc(const vector<int>& v1, const vector<int>& v2 ){
    if(v1[0]==v2[0]){
        return v1[1] > v2[1];
    }
    else{
        return v1[0] > v2[0];
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, x, y, k;
    vector<int> tmp;
    vector<vector<int>> points;
    vector<vector<int>> ans;
    cin >> n >> k;
    while(n--){
        cin >> x >> y;
        tmp.push_back(x);
        tmp.push_back(y);
        points.push_back(tmp);
        tmp.clear();
    }

    Solution sol;
    ans = sol.kClosest(points,k);
    sort(ans.begin(), ans.end(),sortFunc);
    for(auto it = ans.begin();it!=ans.end();it++){
        for (auto it2 = it->begin(); it2 != it->end(); it2++) {
            cout << *it2 << " ";
        }
        cout << endl;
    }
    return 0;
}

