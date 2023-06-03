// Time complexity - O(N).
// Space Complexity - O(N).

class Solution {
public:
    int minimumDeletions(string s) {
        stack<char> st, st2;
        int valA = 0, valB = 0, InvalA = 0, InvalB = 0;

        // Count the number of 'b' characters in the first pass
        for (auto it : s) {
            if (it == 'b') {
                st.push('b');
            } else {
                if (st.empty()) {
                    valA++; // Increment the count of valid 'a' characters
                } else {
                    InvalA++; // Increment the count of invalid 'a' characters
                    st.pop(); // Pop a 'b' character as it balances with the current 'a'
                }
            }
        }

        // Count the number of 'a' characters in the second pass
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == 'a') {
                st2.push('a');
            } else {
                if (st2.empty()) {
                    valB++; // Increment the count of valid 'b' characters
                } else {
                    InvalB++; // Increment the count of invalid 'b' characters
                    st2.pop(); // Pop an 'a' character as it balances with the current 'b'
                }
            }
        }

        // Choose the minimum number of deletions based on 'a' and 'b' counts
        if (valA >= valB) {
            return InvalB; // If valid 'a' count is greater or equal to valid 'b' count, return count of invalid 'b' characters
        } 
            
        return InvalA; // Otherwise, return count of invalid 'a' characters
    }
};
