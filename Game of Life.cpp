// TC = O(n * m)
// SC = O(n * m)


class Solution {
public:

    int n, m; // Variables to store the dimensions of the board

    // Function to count the number of live neighbors around a given cell
    int Count(int row, int col, vector<vector<int>> &board){

        int cnt = 0;

        for(int i=-1; i<=1; i++){

            for(int j=-1; j<=1; j++){

                int rr = row + i, cc = col + j;

                // Skip the current cell itself
                if(rr == row && cc == col){}
                
                // Check if the neighboring cell is within the board boundaries and is alive
                else if(rr >= 0 && rr < n && cc >= 0 && cc < m && board[rr][cc] == 1) 
                    cnt++;
                
            }
        }

        return cnt;
    }

    // Function to update the board based on the rules of the game
    void gameOfLife(vector<vector<int>>& board) {
        
        n = board.size(), m = board[0].size(); // Store the dimensions of the board
        vector<vector<int>> mat(n, vector<int> (m, 0)); // Create a new matrix to store the updated board

        for(int i=0; i<n; i++){

            for(int j=0; j<m; j++){

                int cnt = Count(i, j, board); // Count the live neighbors of the current cell

                if(board[i][j] == 0){ // If the current cell is dead

                    if(cnt == 3) // If the number of live neighbors is exactly 3, the cell becomes alive
                        mat[i][j] = 1;
                }
                else{ // If the current cell is alive

                    if(cnt < 2 || cnt > 3) // If the number of live neighbors is less than 2 or greater than 3, the cell dies
                        mat[i][j] = 0;
                    else // Otherwise, the cell remains alive
                        mat[i][j] = 1;
                }
            }
        }

        board = mat; // Update the original board with the new board
    }
};

        board = mat;
    }
};
