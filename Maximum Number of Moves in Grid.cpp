// TC = O(N * M)
// SC = O(N * M)

class Solution {
public:
    int n, m;
    
    // Function to recursively calculate the maximum number of moves from a given cell
    int solve(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        int cnt = 0;

        // If the result for the current cell is already calculated, return it
        if (dp[row][col] != -1)
            return dp[row][col];

        // Explore all possible neighboring cells
        for (int i = -1; i <= 1; i++) {
            int rr = row + i, cc = col + 1;

            // Check if the neighboring cell is within the grid boundaries and has a higher value
            if (rr >= 0 && rr < n && cc >= 0 && cc < m && grid[rr][cc] > grid[row][col])
                cnt = max(cnt, 1 + solve(rr, cc, grid, dp));
        }

        // Store the maximum number of moves starting from the current cell
        return dp[row][col] = cnt;
    }
    
    // Main function to find the maximum number of moves
    int maxMoves(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        // Initialize the DP table with -1
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int ans = 0;

        // Iterate over each row and find the maximum number of moves starting from that row
        for (int i = 0; i < n; i++)
            ans = max(solve(i, 0, grid, dp), ans);

        return ans;
    }
};
