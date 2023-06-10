// TC = O(N! * 2^N)
// SC = O(N! + 2^N)

class Solution {
public:
    set<string> st, st2; // Set to store unique permutations and subsequences
    int n; // Length of input string

    // Function to generate all permutations of the string
    void perm(string &s, int ind) {
        if(ind == n) {
            st.insert(s); // Store the permutation
            return;
        }

        for(int i = ind; i < n; i++) {
            swap(s[i], s[ind]); // Swap characters
            perm(s, ind + 1); // Generate permutations for the remaining string
            swap(s[i], s[ind]); // Revert the swap
        }

        return;
    }

    int numTilePossibilities(string str) {
        n = str.length();
        perm(str, 0); // Generate all permutations

        // Generate all subsequences for each permutation
        for(auto &s : st) {
            string res = "";

            for(int i = 0; i < s.length(); i++) {
                res += s[i];
                st2.insert(res); // Store the subsequence
            }
        }

        return st2.size(); // Return the count of unique subsequences
    }
};
