// TC = O(N)
// SC = O(1)

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        // If k is 0, no averaging is needed, return the original array
        if(k == 0) return nums;

        long long n = nums.size();  // Size of the input array
        long long div = (k * 2) + 1;  // Divisor for averaging
        vector<int> ans(n, -1);  // Initialize the answer vector with -1
        long long sum = 0;  // Variable to store the sum of elements
        long long st = 0, en = div;  // Start and end indices for averaging

        // If the size of the input array is smaller than the divisor, return the initialized answer vector
        if(n < div) return ans;

        // Calculate the sum of the first div elements
        for(int i = 0; i < div; i++) {
            sum += nums[i];
        }

        // Calculate the average of the middle element in the first window
        ans[k] = sum / div;

        // Slide the window and calculate averages for the rest of the elements
        while(en < n) {
            sum += nums[en];  // Add the next element
            sum -= nums[st++];  // Remove the first element of the window

            // Calculate the average and store it in the middle of the current window
            ans[(st + en) / 2] = sum / div;

            en++;  // Move the window to the right
        }

        return ans;  // Return the answer vector
    }
};
