// TC = O(N^2)
// SC = O(N)

// This class represents a solution to sort the diagonals of a matrix in ascending order

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        
        map<int,vector<int>> mp; // Create a map to store the elements of each diagonal

        int n = mat.size(); // Number of rows in the matrix
        int m = mat[0].size(); // Number of columns in the matrix

        // Iterate over the first row of the matrix
        for(int i = 0; i < m; i++){

            int row = 0; // Start at the first row
            int col = i; // Start at the current column
            int diff = row - col; // Calculate the difference between the row and column indices

            // Traverse along the diagonal starting from the current position
            while(row < n && col < m){

                mp[diff].push_back(mat[row][col]); // Add the current element to the diagonal map
                row++; // Move to the next row
                col++; // Move to the next column
            }
        }

        // Iterate over the first column of the matrix (excluding the first element)
        for(int i = 1; i < n; i++){

            int row = i; // Start at the current row
            int col = 0; // Start at the first column
            int diff = row - col; // Calculate the difference between the row and column indices

            // Traverse along the diagonal starting from the current position
            while(row < n && col < m){

                mp[diff].push_back(mat[row][col]); // Add the current element to the diagonal map
                row++; // Move to the next row
                col++; // Move to the next column
            }
        }

        // Sort each diagonal in descending order
        for(auto &it: mp) {
            sort(it.second.begin(), it.second.end(), greater<>());
        }

        // Iterate over the matrix and update each element with the sorted diagonal elements
        for(int i = 0; i < n; i++){

            for(int j = 0; j < m; j++){

                int diff = i - j; // Calculate the difference between the row and column indices

                mat[i][j] = mp[diff].back(); // Update the current element with the last element of the corresponding diagonal
                mp[diff].pop_back(); // Remove the last element from the diagonal

            }
        }

        return mat; // Return the sorted matrix
    }
};
