class Solution {
    public:
        vector<int> findIndices(vector<int>& nums, int d, int v) {
            int n = nums.size();
            
            vector<pair<int,int>>mn(n,{nums[n-1],n-1}), mx(n,{nums[n-1],n-1});
            
            for(int i=n-2; i>=0; i--){
                if(nums[i] < mn[i+1].first){
                    mn[i] = {nums[i], i};
                }
                else{
                   mn[i] = mn[i+1]; 
                } 
                if(nums[i] > mx[i+1].first){
                    mx[i] = {nums[i],i};
                }
                else {
                    mx[i] = mx[i+1];
                }
            }
            
            int i = 0;
            
            for(int j=0; j<n; j++){
                if(j-i < d) continue;
                if(abs(mn[j].first-nums[i]) >= v ){
                    return {i,mn[j].second};
                }
                if(abs(mx[j].first - nums[i]) >= v){
                    return {i,mx[j].second};
                }
                i++;
            }
            return {-1,-1};
        }
    };