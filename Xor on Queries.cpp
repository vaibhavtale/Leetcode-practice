// TC = O(N)
// SC = O(N)

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        
        vector<int> preXor; // Stores the prefix XOR values
        vector<int> ans; // Stores the results

        int currXor = 0; // Current XOR value

        // Calculate prefix XOR values
        for(int i = 0; i < arr.size(); i++){
            currXor ^= arr[i]; // XOR the current element with the previous XOR value
            preXor.push_back(currXor); // Store the prefix XOR value
        }

        // Process queries
        for(int i = 0; i < queries.size(); i++){

            if(queries[i][0] == 0)
                ans.push_back(preXor[queries[i][1]]); // Query range starts from 0, so use the prefix XOR directly

            else if(queries[i][0] == queries[i][1])
                ans.push_back(arr[queries[i][0]]); // Single element query, return the element itself

            else{
                // Range query from queries[i][0] to queries[i][1]

                ans.push_back(preXor[queries[i][1]] ^ preXor[queries[i][0] - 1]);
                // XOR of the XOR values from queries[i][0] to queries[i][1] is calculated by XORing the prefix XOR values at indices
                // queries[i][1] and queries[i][0] - 1
            }
        }

        return ans; // Return the final results
    }
};
