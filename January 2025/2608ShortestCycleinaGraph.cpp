class Solution 
{
    int global_counter = 0;
    void bfs(unordered_map<int,vector<int>>& mp , int node , vector<int>& visited)
    {
        queue<pair<int,int>> q;
        q.push({node , -1});
        visited[node] = 1;
        global_counter++;
        while(!q.empty())
        {
            auto top = q.front();
            int curr = top.first;
            int parent = top.second;
            q.pop();
            
            for(auto it : mp[curr])
            {
                if(!visited[it])
                {
                    q.push({it , curr});
                    visited[it]++;
                    global_counter++;
                }
                else if(it != parent) return ;
            }
        }
        return;
    }

public:
    int findShortestCycle(int n, vector<vector<int>>& edges) 
    {
        int ans = INT_MAX;
        unordered_map<int,vector<int>> mp;
        for(auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }   
        int shortest_cycle = INT_MAX;
        
        for(int i = 0 ; i  < n ;i++)
        {
            vector<int>dist(n , INT_MAX);
            vector<int> visited(n , 0);
            dist[i] = 0;
            queue<pair<int,int>>q;
            q.push({i , -1});
            visited[i] = 1;
            while(!q.empty())
            {
                auto top = q.front();
                q.pop();
                int curr = top.first;
                int parent = top.second;
                for(auto it : mp[curr])
                {
                    if(!visited[it])
                    {
                        q.push({it , curr});
                        visited[it] = 1;
                        dist[it] = dist[curr] + 1;
                    }
                    else if(it != parent)
                    {
                        shortest_cycle = min(shortest_cycle , dist[curr] + dist[it] + 1);
                    }
                }
            }
            
        }


        return shortest_cycle == INT_MAX ? -1 : shortest_cycle;
    }
};