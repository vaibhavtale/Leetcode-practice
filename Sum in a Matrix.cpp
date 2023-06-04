//TC = O(N * N)
//SC = O(1)

class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        
        int n = nums.size(), m = nums[0].size(), ans = 0;
        
        for(int i=0; i<n; i++){
            
            sort(nums[i].begin(), nums[i].end());
        }
        
        for(int i=0; i<m; i++){
            
            int maxi = INT_MIN;
            
            for(int j=0; j<n; j++){
                
                maxi = max(maxi, nums[j][i]);
            }
            
            ans += maxi;
        }
        
        return ans;
    }
};
