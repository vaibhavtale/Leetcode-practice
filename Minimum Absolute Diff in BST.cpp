// TC = O(N)
// SC = O(1)

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
    int ans = INT_MAX; // Variable to store the minimum difference

    // Inorder traversal of the binary tree to find the minimum difference
    void inorder(TreeNode* root, int &prev){
        if (!root) return; // Base case: If root is null, return

        // Recursive inorder traversal
        inorder(root->left, prev); // Traverse left subtree
        ans = min(ans, abs(prev - root->val)); // Update the minimum difference
        prev = root->val; // Update the previous value with the current node value
        inorder(root->right, prev); // Traverse right subtree
        return;
    }

    int getMinimumDifference(TreeNode* root) {
        // Base Case: If root is null, return 0
        if (!root) return 0;

        // Brute Force Approach:
        // int ans = INT_MAX;
        // inorder(root);
        // for (int i = 1; i < v.size(); i++)
        //     ans = min(ans, abs(v[i] - v[i-1]));

        // Optimal Approach:
        int inf = INT_MAX; // Initialize a variable with maximum value
        inorder(root, inf); // Call the inorder traversal function
        return ans; // Return the minimum difference
    }
};
