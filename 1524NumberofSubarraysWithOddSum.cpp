class Solution {
    public:
        static int numOfSubarrays(vector<int>& arr) {
            const int mod=1e9+7;
            bool sum_is_odd=0;
            int cnt[2]={1, 0};// cnt[0] for even, cnt[1] for odd
            long long ans=0;
            for(int x : arr){
                sum_is_odd^=(x&1); 
                ans+=cnt[1-sum_is_odd];
                cnt[sum_is_odd]++;
            }
            return ans%mod;
        }
    };
    
    auto init = []() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        return 'c';
    }();


    //Approach for Counting Subarrays with Odd Sum

    class Solution {
        public:
            int numOfSubarrays(vector<int>& arr) {
                const int MOD=1e9+7;
                long long o=0,e=1,s=0,r=0;
                for(int a:arr){
                    s+=a;
                    if(s%2==0){
                        r=(r+o)%MOD;
                        e++;
                    }else{
                        r=(r+e)%MOD;
                        o++;
                    }
                }return r;
            }
        };

        //Dynamic Programming (DP) approach to solve the problem.
        class Solution {
            public:
                int numOfSubarrays(vector<int>& arr) {
                    const int MOD = 1e9 + 7;
                    long long dp_odd = 0, dp_even = 1, result = 0;
            
                    for (int a : arr) {
                        if (a % 2 == 0) {
                            dp_odd = dp_odd;
                            
                            dp_even = (dp_even + 1) % MOD;
                        } else {
                            long long temp = dp_odd;
                            dp_odd = dp_even;
                            dp_even = (temp + 1) % MOD;
                        }
                        result = (result + dp_odd) % MOD;
                    }
                    return result;
                }
            };