//TC = O(N^2)
//SC = O(N^2)

class Solution {
public:

    vector<int> delrow = {-1, 0, 1, 0}, delcol = {0, 1, 0, -1};
    int numOfZeroes = 1, n, m;
    int cnt = 0;

    // int dfs(int Srow, int Scol, vector<vector<int>> &grid, int &zero, int Erow, int Ecol, int n, int m, vector<vector<bool>> &vis){

    //     if(Srow >= n || Srow < 0 || Scol >= m || Scol < 0 || grid[Srow][Scol] == -1) return 0;

    //     if(Srow == Erow && Scol == Ecol){

    //         if(zero) return 0;

    //         return 1;
    //     }

    //     int ans = 0;
    //     vis[Srow][Scol] = true;

    //     for(int i=0; i<4; i++){

    //         int rr = Srow + delrow[i], cc = Scol + delcol[i];

    //         if(!vis[rr][cc]) ans = dfs(rr, cc, grid, zero-1, Erow, Ecol, n, m, vis);
    //     }

    //     vis[Srow][Scol] = false;

    //     return ans;
    // }

    void dfs(int row, int col, int zero, vector<vector<int>> &grid, vector<vector<bool>> &vis){

        if(row >= n || row < 0 || col >= m || col < 0 || grid[row][col] == -1 || vis[row][col]) return;

        if(grid[row][col] == 2){

            if(zero == numOfZeroes) cnt++;

            return;
        }

        vis[row][col] = true;

        // for(int i=0; i<4; i++){

        //     int rr = row + delrow[i], cc = col + delcol[i];

        //     if(!vis[rr][cc]) dfs(rr, cc, zero+1, grid, vis);
        // }

        dfs(row+1, col, zero+1, grid, vis);
        dfs(row-1, col, zero+1, grid, vis);
        dfs(row, col+1, zero+1, grid, vis);
        dfs(row, col-1, zero+1, grid, vis);


        vis[row][col] = false;

        return;

    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        
        n = grid.size(), m = grid[0].size(); int startRow, startCol, endRow, endCol;
        vector<vector<bool>> vis(n, vector<bool> (m, false));

        for(int i=0; i<n; i++){

            for(int j=0; j<m; j++){

                if(grid[i][j] == 0) numOfZeroes++;

                else if(grid[i][j] == 1){

                    startRow = i;
                    startCol = j;
                }
                else if(grid[i][j] == 2){

                    endRow = i;
                    endCol = j;
                }
            }
        }


        dfs(startRow, startCol, 0, grid, vis);

        return cnt;

        // return dfs( grid, zero, endRow, endCol, n, m, vis);
    }
};
