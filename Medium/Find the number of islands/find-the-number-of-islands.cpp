//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void helper(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y, int rows, int cols){
        int x_dir[] = {-1,0,1};
        int y_dir[] = {-1,0,1};
        for(int i = 0; i<3; i++){
            for(int j = 0; j<3; j++){
                int new_x = x + x_dir[i];
                int new_y = y + y_dir[j];
                if(new_x < 0 || new_x >= rows || new_y <0 || new_y >=cols){
                    continue;
                }
                if(!visited[new_x][new_y] && grid[new_x][new_y] == '1'){
                    visited[new_x][new_y] = true;
                    helper(grid, visited, new_x, new_y, rows, cols);
                }
            }
        }
        
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int count = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        for(int i = 0; i<rows; i++){
            for(int j = 0; j<cols; j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    count++;
                    visited[i][j] = true;
                    helper(grid, visited,i,j, rows, cols);
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends