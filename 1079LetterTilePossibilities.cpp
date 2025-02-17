class Solution {
    public:
        // choose n chars with freq info to permute
        int Perm(int n, vector<int>& freq, int fz){
            if (n==1) // base case
               return fz-count(freq.begin(), freq.end(), 0);
            int ans=0;
            for (int i=0; i<fz; i++) {
                if (freq[i]>0) {
                    freq[i]--; 
                    ans+= Perm(n-1, freq, fz);// recursion
                    freq[i]++; // backtracking
                }
            }
            return ans;
        }
        int numTilePossibilities(string& tiles) {
            int sz=0, tz=tiles.size();
            vector<int> freq(26, 0);
            for (char c: tiles)
                if (++freq[c-'A']==1) sz++;
            sort(freq.begin(), freq.end(), greater<int>());
            freq.resize(sz);
        
            int cnt=0;
            for (int len=1; len<=tz; len++) 
                cnt+= Perm(len, freq, sz);
    
            return cnt;
        }
    };

    //2nd approach

    class Solution { 
        public:
            int numTilePossibilities(std::string tiles) {
                int n = tiles.length();
                std::vector<int> counts(26, 0);
                std::vector<int> fac(n + 1, 1);
                for (int i = 1; i <= n; i++) {
                    fac[i] = i * fac[i - 1];
                }
                for (char c : tiles) {
                    counts[c - 'A']++;
                }
                std::vector<int> lengthcounts(n + 1, 0);
                lengthcounts[0] = 1;
                for (int i = 0; i < 26; i++) {
                    if (counts[i] > 0) {
                        std::vector<int> temp(n + 1, 0);
                        for (int j = 0; j <= n && lengthcounts[j] > 0; j++) {
                            for (int k = 1; k <= counts[i]; k++) {
                                int totallength = j + k;
                                temp[totallength] += lengthcounts[j] * fac[totallength] / (fac[k] * fac[j]);
                            }
                        }
                        for (int j = 0; j <= n; j++) {
                            lengthcounts[j] += temp[j];
                        }
                    }
                }
                int ans = 0;
                for (int i = 1; i <= n; i++) {
                    ans += lengthcounts[i];
                }
                return ans;
            }
        };