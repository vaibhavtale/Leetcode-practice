// TC = O(N)
// SC = O(1)

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans = -1; // Variable to store the longest sequence of 1s
        int prev = 0; // Index of the starting point of the current window
        int cnt0 = 0; // Count of 0s in the current window
        int cnt1 = 0; // Count of 1s in the current window
        int n = nums.size(); // Length of the input array

        // Noob Window technique...
        int i = 0, j = 0; // Start and end indices of the window

        while (i < n && j < n) {
            if (nums[j] == 1) {
                j++;
                cnt1++; // Increment count of 1s
            } else if (nums[j] == 0) {
                if (cnt0 < k) {
                    j++;
                    cnt0++; // Increment count of 0s
                    cnt1++; // Increment count of 1s
                } else if (k == 0) {
                    i = j + 1;
                    j++;
                } else {
                    while (cnt0 >= k && i < j) {
                        if (nums[i] == 0) {
                            cnt0--; // Decrement count of 0s
                        }
                        i++;
                    }
                }
            }
            ans = max(ans, j - i); // Update the longest sequence of 1s
        }

        // Pro window technique
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0)
                cnt0++; // Increment count of 0s

            while (cnt0 > k) {
                if (nums[prev] == 0) {
                    cnt0--; // Decrement count of 0s
                }
                prev++; // Move the starting point of the window
            }

            ans = max(ans, (i - prev) + 1); // Update the longest sequence of 1s
        }

        return ans;
    }
};
