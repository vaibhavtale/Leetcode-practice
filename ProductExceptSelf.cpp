// TC = O(N)
// SC = O(N)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> prefix(n, 0); // Prefix product array
        vector<int> sufix(n, 0); // Suffix product array
        vector<int> ans(n, 0); // Result array

        int pre = 1; // Initialize prefix product
        int suf = 1; // Initialize suffix product

        // Calculate prefix product array
        for(int i = 0; i < n; i++){
            pre *= nums[i]; // Multiply the current number with the previous prefix product
            prefix[i] = pre; // Store the prefix product
        }

        // Calculate suffix product array
        for(int i = n - 1; i >= 0; i--){
            suf *= nums[i]; // Multiply the current number with the previous suffix product
            sufix[i] = suf; // Store the suffix product
        }

        // Calculate product except self
        for(int i = 0; i < n; i++){
            int product = 1; // Initialize product

            if(i > 0)
                product *= prefix[i-1]; // Multiply product with prefix product except the current number

            if(i < n-1)
                product *= sufix[i+1]; // Multiply product with suffix product except the current number

            ans[i] = product; // Store the final product in the result array
        }

        return ans; // Return the final result
    }
};
