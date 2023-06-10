// TC = O(N log N)
// SC = O(N)

#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Comparison function for sorting words based on length and original order
    static bool cmp(pair<string, int> &a, pair<string, int> &b) {
        // If the lengths of the words are the same, compare their original order
        if (a.first.length() == b.first.length())
            return a.second < b.second;

        // Sort words based on length
        return a.first.length() < b.first.length();
    }

    string arrangeWords(string text) {
        vector<pair<string, int>> words;
        int n = text.length();
        int cnt = 0;
        
        // Convert the first character to lowercase
        text[0] += 32;
        string str = "";

        // Split the text into words
        for (int i = 0; i < n; i++) {
            // If a space is encountered, add the word to the vector with its original order
            if (text[i] == ' ') {
                words.push_back({str, cnt});
                cnt++;
                str = "";
            } else {
                // Build the current word
                str += text[i];
            }
        }
        // Add the last word to the vector with its original order
        words.push_back({str, cnt});

        // Sort the words based on length and original order
        sort(words.begin(), words.end(), cmp);

        string result = "";

        // Concatenate the sorted words into a single string
        for (auto i = 0; i < words.size() - 1; i++) {
            result += words[i].first;
            result += ' ';
        }
        // Add the last word to the result string
        result += words.back().first;

        // Convert the first character to uppercase
        result[0] -= 32;

        return result;
    }
};
