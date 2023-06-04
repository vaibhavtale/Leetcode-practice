//TC = O(N^2)
//SC = O(N^2)

class DisjointSet {
    vector<int> parent, rank;

public:
    DisjointSet(int num) {
        // Initialize parent and rank arrays
        parent.resize(num + 1);
        rank.resize(num + 1, 0);

        // Set each node as its own parent initially
        for (int i = 0; i < parent.size(); i++) {
            parent[i] = i;
        }
    }

    int findpar(int node) {
        // Find the parent of the node using path compression
        if (parent[node] == node)
            return node;

        return parent[node] = findpar(parent[node]);
    }

    void UnionByRank(int u, int v) {
        // Find the ultimate parent of each node
        int ultp_u = findpar(u);
        int ultp_v = findpar(v);

        if (ultp_u == ultp_v)
            return;

        // Union the sets based on rank (tree height)
        if (rank[ultp_u] < rank[ultp_v]) {
            parent[ultp_u] = ultp_v;
            rank[ultp_v]++;
        } else {
            parent[ultp_v] = ultp_u;
            rank[ultp_u]++;
        }
    }
};

class Solution {
public:
    void dfs(int num, vector<bool>& vis, vector<vector<int>>& wt) {
        vis[num] = true;

        // Traverse the adjacent nodes
        for (int i = 0; i < wt[num].size(); i++) {
            if (wt[num][i] == 1 && !vis[i]) {
                dfs(i, vis, wt);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int province = 0;

        // Depth-first search to find connected components
        vector<bool> vis(n, false);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
//                 province++;
//                 dfs(i, vis, isConnected);
            }
        }

        // Disjoint set to find connected components
        DisjointSet des(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && des.findpar(i + 1) != des.findpar(j + 1)) {
                    des.UnionByRank(i + 1, j + 1);
                }
            }
        }

        // Count the number of unique parent nodes in the disjoint set
        for (int i = 1; i <= n; i++) {
            if (des.findpar(i) == i)
                province++;
        }

        return province;
    }
};
