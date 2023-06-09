// TC = O(NlogN + E) --> NlogN for sorting & E is num of edges
// SC = O(N+E)

class Solution {
public:

    // Depth-first search function to find ancestors
    void dfs(int src, vector<bool> &vis, vector<vector<int>> &adj, int par, vector<vector<int>> &ans){

        // If the current node has already been visited, return
        if(vis[src]) return;

        // Mark the current node as visited
        vis[src] = true;

        // Traverse through the adjacent nodes
        for(auto it:adj[src]){

            // If the adjacent node has not been visited
            if(!vis[it]){

                // Add the adjacent node to the ancestors of the parent node
                ans[par].push_back(it);

                // Recursively call the dfs function for the adjacent node
                dfs(it, vis, adj, par, ans);
            }
        }

        return;
    }

    // Function to find ancestors of each node
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        
        int len = edges.size();
        vector<vector<int>> ans(n);

        // If there are no edges or the number of nodes is less than 2, return the empty ancestors array
        if(edges.empty() || n < 2) return ans;

        vector<vector<int>> adj(n);

        // Create the adjacency list for each edge
        for(int i=0; i<len; i++){

            adj[edges[i][1]].push_back(edges[i][0]);
        }

        // Traverse through each node to find its ancestors
        for(int i=0; i<n; i++){

            // Initialize the visited array for each node
            vector<bool> vis(n, false);

            // Call the dfs function to find ancestors of the current node
            dfs(i, vis, adj, i, ans);
        }

        // Sort the ancestor list for each node in ascending order
        for(auto &vect:ans){

            sort(vect.begin(), vect.end());
        }

        return ans;
    }
};
