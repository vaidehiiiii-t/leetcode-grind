class Solution {
    public:
        int findPairs(vector<int>& nums, int k) 
        {
            unordered_map<int,int> mp;
            int count = 0;
            for(auto it : nums) mp[it]++;
            if(k == 0)
            {
                for(auto it = mp.begin(); it != mp.end() ; it++)
                {
                    if(it->second > 1)
                    {
                        count++;
                    }
                }
                return count;
            }
            for(auto it = mp.begin(); it != mp.end() ; it++)
            {
                if(mp.find(it->first + k) != mp.end())
                {
                    count++;
                }
                
            }
            return count;
        }
    };