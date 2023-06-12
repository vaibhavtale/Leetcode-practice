// TC = O(N)
// SC = O(N)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    map<int, int> mp; // Map to store the sum frequencies
    int freqSum = 0; // Variable to store the maximum frequency of sum
    
    int fun(TreeNode* root) {
        if (!root) return 0; // Base case: null node, return 0
        
        int left = fun(root->left); // Recursive call on the left subtree
        int right = fun(root->right); // Recursive call on the right subtree
        
        int sum = root->val + left + right; // Compute the sum of the current subtree
        
        mp[sum]++; // Increment the frequency of the sum in the map
        
        freqSum = max(freqSum, mp[sum]); // Update the maximum frequency
        
        return sum; // Return the sum of the current subtree
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> ans; // Vector to store the frequent tree sums
        
        fun(root); // Call the helper function to compute the sums and frequencies
        
        for (auto it : mp) {
            if (it.second == freqSum) { // Check if the frequency matches the maximum frequency
                ans.push_back(it.first); // Add the sum to the result vector
            }
        }
        
        return ans; // Return the vector of frequent tree sums
    }
};
