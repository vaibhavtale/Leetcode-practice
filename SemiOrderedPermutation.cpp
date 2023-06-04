// TC = O(N)
// SC = O(1)

class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        
        int cnt = 0;
        
        // Check if the first element is not 1
        if (nums[0] != 1) {
            // Find the position of 1 and move it to the beginning
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == 1) {
                    int ind = i;
                    while (ind) {
                        swap(nums[ind], nums[ind-1]);
                        ind--;
                        cnt++;
                    }
                }
            }
        }
        
        // Check if the last element is not equal to the size of the array
        if (nums[nums.size() - 1] != nums.size()) {
            // Find the position of the largest element and move it to the end
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == nums.size()) {
                    int ind = i;
                    while (ind < nums.size() - 1) {
                        swap(nums[ind], nums[ind+1]);
                        ind++;
                        cnt++;
                    }
                }
            }
        }
        
        return cnt;
    }
};
