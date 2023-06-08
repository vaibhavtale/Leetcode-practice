// TC = O(n * m)
// SC = O(n + m)

class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        // Get the number of rows and columns in the grid
        int n = grid.size();
        int m = grid[0].size();

        // Create vectors to store the count of ones and zeros for each row and column
        vector<pair<int, int>> rows(n, {0, 0});
        vector<pair<int, int>> cols(m, {0, 0});

        // Count the number of ones and zeros in each row and column
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    // Increment the count of ones for the current row and column
                    rows[i].first += 1;
                    cols[j].first += 1;
                } else {
                    // Increment the count of zeros for the current row and column
                    rows[i].second += 1;
                    cols[j].second += 1;
                }
            }
        }

        // Compute the difference between the count of ones and zeros for each element in the grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // Calculate the difference by subtracting the count of zeros from the count of ones
                grid[i][j] = rows[i].first + cols[j].first - rows[i].second - cols[j].second;
            }
        }

        return grid;
    }
};
