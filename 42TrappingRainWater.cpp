class Solution {
public:
    int trap(vector<int>& a) {
        int n = a.size();
        vector<int> left(n), right(n);
        left[0] = a[0];right[n-1] = a[n-1];
        for(int i=1;i<n;i++){
            left[i] = max(left[i-1],a[i]);
        }

        for(int i=n-2;i>=0;i--){
            right[i] = max(right[i+1],a[i]);
        }

        int ans = 0;

        for(int i=0;i<n;i++){
            if(left[i] == a[i] || right[i] == a[i]) continue;
            ans = ans + (min(left[i],right[i])-a[i]);
        }

        return ans;
    }
};