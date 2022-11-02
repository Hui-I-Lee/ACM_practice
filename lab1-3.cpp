#include <iostream>
#include <vector>
using namespace std;


class Solution
{
public:
    int rowplace;
    int columnplace;
    Solution():rowplace(0) { columnplace=0;}
    bool searchMatrix(vector<vector<int> > &matrix, int target)
    {
        if (matrix.empty() || matrix[0].empty()) return false;
        int left = 0, right = matrix.size();  //row num
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (matrix[mid][0] == target)
            {
                rowplace=mid;
                return true;
            }
            if (matrix[mid][0] <= target) left = mid + 1;
            else right = mid;
        }
        int tmp = (right > 0) ? (right - 1) : right;
        rowplace=tmp;
        left = 0;
        right = matrix[tmp].size();
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (matrix[tmp][mid] == target)
            {
                columnplace=mid;
                return true;
            }
            if (matrix[tmp][mid] < target) left = mid + 1;
            else right = mid;
        }
        return false;
    }
};


int main()
{
    int m,n,k;
    cin>>m>>n>>k;
    vector<vector<int> > matrix(m,vector<int>(n));
    //vector<int> krr;
    int g;
    Solution sol;
    
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            
            cin>>matrix[i][j];
        }
    }
    
    
    bool exit;
    for(int i=0;i<k;i++)
    {
        cin>>g;
        exit = sol.searchMatrix(matrix, g);
        if(exit == false)
        {
            cout<<"-1"<<endl;
        }
        else
        {
            cout<<sol.rowplace<<" "<<sol.columnplace<<endl;
        }
    }
    return 0;
}

