// TC = O(n * m)
// SC = O(n * m)

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        
        map<int, pair<int,int>> mp;
        int n = mat.size(), m = mat[0].size();

        vector<int> Rows(n, 0), Cols(m, 0);

        // Create a mapping of each element in mat to its corresponding row and column indices
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                mp[mat[i][j]] = {i, j};
            }
        }

        // Check each element in arr for completeness
        for(int i=0; i<arr.size(); i++){
            int row = mp[arr[i]].first, col = mp[arr[i]].second;

            // Increase the count of elements in the corresponding row and column
            Rows[row] += 1;
            Cols[col] += 1;

            // If a row or column is complete, return the current index
            if(Rows[row] == m || Cols[col] == n) {
                return i;
            }
        }

        // If no completeness is found, return -1
        return -1;
    }
};
