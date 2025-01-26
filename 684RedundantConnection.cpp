class Solution {
public:
    vector<int> parent;

    
    int findParent(int u) {
        if (parent[u] == u)
            return u;
        return parent[u] = findParent(parent[u]);
    }

    
    bool find_union(int u, int v) {
        int pu = findParent(u); 
        int pv = findParent(v); 
        if (pu == pv)
            return true;
        parent[pu] = pv; 
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n + 1, -1);

        
        for (int i = 1; i <= n; i++)
            parent[i] = i;

        
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            if (find_union(u, v))
                return {u, v};
        }
        return {-1, -1};
    }
};
