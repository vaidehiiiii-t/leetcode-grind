class Solution 
{
    vector<int> rank ,  parent;

    int findYourParent(int node)
    {
        if(node == parent[node]) return node;
        return parent[node] = findYourParent(parent[node]);
    }

    void unionByRank(int u , int v)
    {
        int pu = findYourParent(u);
        int pv = findYourParent(v);
        if(pu == pv) return;
        else if(rank[pu] < rank[pv])
        {
            parent[pu] = pv;
        }
        else if(rank[pv] < rank[pu])
        {
            parent[pv] = pu;
        }
        else
        {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
    
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) 
    {
        int size = accounts.size();
        rank.resize(size , 0);
        parent.resize(size);
        for(int i = 0 ; i < size ; i++) parent[i] = i;
        unordered_map<string , int> emailToIndex;
        for(int i = 0 ; i < size ; i++)
        {
            for(int j = 1 ; j < accounts[i].size() ; j++)
            {
                string email = accounts[i][j];
                if(emailToIndex.find(email) == emailToIndex.end())
                {
                    emailToIndex[email] = i;
                }
                else
                {
                    unionByRank(i , emailToIndex[email]);
                }
            }
        }

        unordered_map<int , vector<string>> indexToEmails;
        for(auto it = emailToIndex.begin() ; it != emailToIndex.end() ; it++)
        {
            int id = it->second;
            string email = it->first;
            int root = findYourParent(id);
            indexToEmails[root].push_back(email);
        }
        vector<vector<string>> res;
        for(auto it = indexToEmails.begin() ; it != indexToEmails.end() ;it++)
        {
            sort(it->second.begin() , it->second.end());
            vector<string> temp = {accounts[it->first][0]};
            temp.insert(temp.end() , it->second.begin() , it->second.end());
            res.push_back(temp);
        }
        return res;
    }
};