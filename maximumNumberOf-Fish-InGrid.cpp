//TC = O(N * M)
//SC = O(N * M)

class Solution {
public:
    int n, m, ans = 0;  // Variables for grid dimensions and maximum fish count
    vector<int> delcol = {-1, 0, 1, 0}, delrow = {0, 1, 0, -1};  // Offsets for adjacent cells
    
    void dfs(int row, int col, vector<vector<bool>>& vis, vector<vector<int>>& grid, int& cnt) {
        vis[row][col] = true;  // Mark current cell as visited
        cnt += grid[row][col];  // Add fish count to current group count
        
        // Explore adjacent cells
        for (int i = 0; i < 4; i++) {
            int rr = row + delrow[i];  // Calculate row index of adjacent cell
            int cc = col + delcol[i];  // Calculate column index of adjacent cell
            
            // Check if adjacent cell is within grid boundaries, unvisited, and has fish
            if (rr >= 0 && rr < n && cc >= 0 && cc < m && !vis[rr][cc] && grid[row][col] != 0) {
                dfs(rr, cc, vis, grid, cnt);  // Recursively explore the adjacent cell
            }
        }
    }
    
    int findMaxFish(vector<vector<int>>& grid) {
        n = grid.size();  // Store number of rows
        m = grid[0].size();  // Store number of columns
        
        vector<vector<bool>> vis(n, vector<bool>(m, false));  // Initialize visited array
        
        // Iterate through each cell in the grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] != 0) {  // If cell is unvisited and has fish
                    int cnt = 0;  // Initialize fish count
                    
                    dfs(i, j, vis, grid, cnt);  // Perform depth-first search to count fish in the group
                    
                    ans = max(ans, cnt);  // Update maximum fish count
                }
            }
        }
        
        return ans;  // Return the maximum fish count
    }
};
