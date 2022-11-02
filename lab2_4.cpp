#include <bits/stdc++.h>
using namespace std;
  
#define UNASSIGNED 0
//#define N 9

bool isSafe(int grid[N][N], int row, int col, int num);

bool FindUnassignedLocation(int grid[N][N],
                            int& row, int& col)
{
    for (row = 0; row < N; row++)
    {
        for (col = 0; col < N; col++)
        {
            if (grid[row][col] == 0)
            {
                return true;
            }
        }
    }
    return false;
}

bool SolveSudoku(int grid[N][N])
{
    int row, col;
  
    // If there is no unassigned location => done
    if (!FindUnassignedLocation(grid, row, col))
    {
        return true;
    }
   
    //already make sure that is unassigned so then we have to give it number
    for (int num = 1; num <= 9; num++)
    {
        // if looks promising
        if (isSafe(grid, row, col, num))
        {
            // make tentative assignment
            grid[row][col] = num;
  
            // return, if success, yay!
            if (SolveSudoku(grid))
                return true;
  
            // failure, unmake & try again
            grid[row][col] = UNASSIGNED;
        }
    }
    // this triggers backtracking
    return false;
}
  /*to choose the number*/
// true => already used
bool UsedInRow(int grid[N][N], int row, int num)
{
    for (int col = 0; col < N; col++)
    {
        if (grid[row][col] == num)
        {
            return true;
            
        }
    }
    return false;
}
  //true => already used
bool UsedInCol(int grid[N][N], int col, int num)
{
    for (int row = 0; row < N; row++)
    {
        if (grid[row][col] == num)
        {
            return true;
            
        }
    }
    return false;
}
  
bool UsedInBox(int grid[N][N], int boxStartRow,
               int boxStartCol, int num)
{
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            if (grid[row + boxStartRow][col + boxStartCol]== num)
                return true;
        }
    }
    return false;
}

bool isSafe(int grid[N][N], int row, int col, int num)
{
    return !UsedInRow(grid, row, num)
           && !UsedInCol(grid, col, num)
           && !UsedInBox(grid, row - row % 3,
                         col - col % 3, num)
           && grid[row][col] == UNASSIGNED;
}
  

void printGrid(int grid[N][N])
{
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
        {
            cout << grid[row][col] << " ";
            
        }
        cout << endl;
    }
}
  
// Driver Code
int main()
{
    // 0 means unassigned cells
   /* int grid[N][N] = {{0 ,0 ,0 ,0 ,0 ,4 ,0 ,2 ,8},
                      {4 ,0 ,6 ,0 ,0 ,0 ,0 ,0 ,5},
                      {1 ,0 ,0 ,0 ,3 ,0 ,6 ,0 ,0},
                      {0 ,0 ,0 ,3 ,0 ,1 ,0 ,0 ,0},
                      {0 ,8 ,7 ,0 ,0 ,0 ,1 ,4 ,0},
                      {0 ,0 ,0 ,7 ,0 ,9 ,0 ,0 ,0},
                      {0 ,0 ,2 ,0 ,1 ,0 ,0 ,0 ,3},
                      {9 ,0 ,0 ,0 ,0 ,0 ,5 ,0 ,7},
                      {6 ,7 ,0 ,4 ,0 ,0 ,0 ,0 ,0 }};*/
    vector<int> temp;
    
    if (SolveSudoku(grid) == true)
        printGrid(grid);
    else
        cout << "No solution exists";
  
    return 0;
}
  
