// TC = O(N log N)
// SC = O(N + M)

class Solution {
public:
    // Custom comparator function to compare pairs based on the second element
    static bool cmp(pair<char, int>& a, pair<char, int>& b) {
        return a.second < b.second;
    }

    string customSortString(string order, string s) {
        vector<pair<char, int>> pii;  // Vector to store pairs of characters and their corresponding order indices
        map<char, int> mp;  // Map to store the order indices of characters in the 'order' string

        // Populate the map with the order indices of characters in the 'order' string
        for (int i = 0; i < order.length(); i++) {
            mp[order[i]] = i;
        }

        // Iterate over each character in the input string 's'
        for (auto it : s) {
            if (mp.find(it) == mp.end()) {
                // Character not found in the 'order' string, assign a high order index equal to the length of 's'
                pii.push_back({it, s.length()});
            } else {
                // Character found in the 'order' string, assign its corresponding order index
                pii.push_back({it, mp[it]});
            }
        }

        // Sort the vector of pairs based on the order indices
        sort(pii.begin(), pii.end(), cmp);

        string res = "";

        // Append the characters to the result string in the sorted order
        for (auto& it : pii) {
            res += it.first;
        }

        return res;
    }
};
