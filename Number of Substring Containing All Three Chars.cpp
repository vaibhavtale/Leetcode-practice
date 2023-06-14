// TC = O(N)
// SC = O(1)

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int left = 0, right = 0, count = 0;
        map<char, int> mp; // Map to store the frequency of characters 'a', 'b', and 'c'

        mp['a'] = 0, mp['b'] = 0, mp['c'] = 0; // Initialize the frequency counts to 0

        while (right < n) {
            mp[s[right]]++; // Increment the frequency of the current character

            // Check if all three characters 'a', 'b', and 'c' are present in the substring
            while (mp['a'] && mp['b'] && mp['c']) {
                count += (n - right); // Increment the count by the number of valid substrings ending at the current position
                
                mp[s[left]]--; // Decrement the frequency of the leftmost character in the substring
                left++; // Move the left pointer to the right to exclude the leftmost character from the substring
            }

            right++; // Move the right pointer to the right to expand the substring
        }

        return count; // Return the total count of valid substrings
    }
};
