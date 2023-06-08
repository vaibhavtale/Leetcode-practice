// TC = O(N)
// SC = O(N)

class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rect) {
        
        map<double, int> mp; // Create a map to store the division results and their frequencies
        
        int n = rect.size(); // Get the number of rectangles
        
        for(int i=0; i<n; i++){ // Iterate through each rectangle
            
            double div = (double)(rect[i][0]) / (double)(rect[i][1]); // Calculate the division result
            
            mp[div]++; // Increment the frequency of the division result in the map
        }
        
        long long pairs = 0; // Initialize the count of interchangeable pairs
        
        for(auto it:mp){ // Iterate through each division result and its frequency
            
            pairs = pairs + (long long)(((long long)(it.second) - 1) * it.second); // Calculate the number of interchangeable pairs
        }
        
        return pairs/2; // Return the total count of interchangeable pairs divided by 2
    }
};
