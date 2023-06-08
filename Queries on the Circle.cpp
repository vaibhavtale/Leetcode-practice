// TC = O(n^2)
// SC = O(m)

class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& pts, vector<vector<int>>& qrs) {
        // Get the sizes of the input vectors
        int n = pts.size(), m = qrs.size();
        vector<int> ans;

        // Iterate over each query point
        for(int i=0; i<m; i++){
            // Extract the coordinates and radius of the query point
            int x2 = qrs[i][0], y2 = qrs[i][1], rad = qrs[i][2];
            int cnt = 0; // Counter for points within the radius

            // Iterate over each given point
            for(int j=0; j<n; j++){
                // Extract the coordinates of the given point
                int x1 = pts[j][0], y1 = pts[j][1];

                // Calculate the squared distance between the given and query points
                int dist = ((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));

                // Check if the point is within the given radius
                if(dist <= rad * rad)
                    cnt++; // Increment the counter
            }

            // Store the count for the current query point
            ans.push_back(cnt);
        }

        return ans; // Return the counts for all query points
    }
};
