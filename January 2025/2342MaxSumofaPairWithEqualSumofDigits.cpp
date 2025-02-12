class Solution {
    public:
        int maximumSum(vector<int>& nums) {
            int mp[82];  // Stores max num for each digit sum
            memset(mp, -1, sizeof(mp));
            int ans = -1;
    
            for (int num : nums) {
                int sumDigits = 0, temp = num;
                while (temp) sumDigits += temp % 10, temp /= 10;
    
                if (mp[sumDigits] != -1)
                    ans = max(ans, num + mp[sumDigits]);
    
                mp[sumDigits] = max(mp[sumDigits], num);
            }
    
            return ans;
        }
    };

    //2nd approach
    class Solution {
        public:
            static inline int digitSum(int x){
                int sum=0;
                for(; x>0; x/=10){
                    sum+=x%10;
                }
                return sum;
            }
            static int maximumSum(vector<int>& nums) {
                int p[82][2]={{0, 0}};
            //    memset(pq, 0, sizeof(pq));
                int maxD=0, minD=INT_MAX;
                for(int x: nums){
                    int D=digitSum(x);
                    if (p[D][0]==0 && p[D][1]==0) p[D][1]=x;
                    else if (x>=p[D][1]) p[D][0]=exchange(p[D][1], x);
                    else if (x>=p[D][0]) p[D][0]=x;
                    maxD=max(maxD, D);
                    minD=min(minD, D);
                }
                
                int ans=-1;
                for(int D=minD; D<=maxD; D++){
                    if (p[D][0]==0) continue;
                    ans=max(ans, p[D][0]+p[D][1]);
                }
                return ans;
            }
        };
        auto init = []()
        { 
            ios::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
            return 'c';
        }();  