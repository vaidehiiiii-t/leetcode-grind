class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size(), i=0, ans=0;
        int inc=1, dec=1;
        if (n==1) return 1;
        for(i=1 ;i<n; i++){
            if (nums[i]>nums[i-1]) inc++, dec=1;
            else if (nums[i]<nums[i-1]) inc=1, dec++;
            else inc=dec=1;
            ans=max({ans, dec, inc});
        } 
        return ans;   
    }
};

//2nd approach
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size(), ans=1, inc=1, dec=1;
        for(int i=1; i<n; i++){
            bool A=nums[i]>nums[i-1], B=nums[i]<nums[i-1];
            inc=A*inc+1;
            dec=B*dec+1;
            ans=max(ans, max(inc , dec));
        }
        return ans;
    }
};