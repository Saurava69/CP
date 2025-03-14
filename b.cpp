#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
class Solution {
    public:
        // Function to get elements of a diagonal starting at (row, col)
        vector<int> getDiagonal(vector<vector<int>>& grid, int row, int col) {
            vector<int> diagonal;
            int n = grid.size();
            while (row < n && col < n) {
                diagonal.push_back(grid[row][col]);
                row++;
                col++;
            }
            return diagonal;
        }
        
        // Function to put sorted elements back into the diagonal
        void setDiagonal(vector<vector<int>>& grid, vector<int>& diagonal, int row, int col) {
            for (int num : diagonal) {
                grid[row][col] = num;
                row++;
                col++;
            }
        }
        
        vector<vector<int>> sortTheMatrix(vector<vector<int>>& grid) {
            int n = grid.size();
            
            // Sort bottom-left triangle (including middle diagonal)
            for (int row = 0; row < n; row++) {
                vector<int> diagonal = getDiagonal(grid, row, 0);
                sort(diagonal.begin(), diagonal.end(), greater<int>()); // Sort in non-increasing order
                setDiagonal(grid, diagonal, row, 0);
            }
            
            // Sort top-right triangle (excluding middle diagonal)
            for (int col = 1; col < n; col++) {
                vector<int> diagonal = getDiagonal(grid, 0, col);
                sort(diagonal.begin(), diagonal.end()); // Sort in non-decreasing order
                setDiagonal(grid, diagonal, 0, col);
            }
            
            return grid;
        }
    };
int main()
{
    fast_io;
    
   Solution a;
   
}