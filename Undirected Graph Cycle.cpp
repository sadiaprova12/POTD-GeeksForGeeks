class Solution {
    public:
        vector<int> parent, rank;
    
        int find(int u) {
            if (u != parent[u])
                parent[u] = find(parent[u]); // Path compression
            return parent[u];
        }
    
        void unionSet(int u, int v) {
            int pu = find(u);
            int pv = find(v);
    
            if (pu == pv) return; // Already in same set
    
            // Union by rank
            if (rank[pu] < rank[pv]) {
                parent[pu] = pv;
            } else if (rank[pu] > rank[pv]) {
                parent[pv] = pu;
            } else {
                parent[pv] = pu;
                rank[pu]++;
            }
        }
    
        bool isCycle(int V, vector<vector<int>>& edges) {
            parent.resize(V);
            rank.resize(V, 0);
            for (int i = 0; i < V; i++) parent[i] = i;
    
            for (auto& edge : edges) {
                int u = edge[0];
                int v = edge[1];
    
                int pu = find(u);
                int pv = find(v);
    
                if (pu == pv) return true; // Cycle found
    
                unionSet(u, v);
            }
    
            return false; // No cycle
        }
    };