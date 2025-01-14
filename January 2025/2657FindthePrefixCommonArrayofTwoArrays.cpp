class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> freq(n + 1, 0);
        vector<int> ans;
        int common = 0;
        
        for (int i = 0; i < n; i++) {
            if (++freq[A[i]] == 2) common++;
            if (++freq[B[i]] == 2) common++;
            ans.push_back(common);
        }
        return ans;
    }
};


//2nd approach
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<bool> seen(51, false);
        vector<int> ans;
        int common = 0;

        for (int i = 0; i < n; ++i) {
            if (seen[A[i]]) {
                ++common;
            } else {
                seen[A[i]] = true;
            }

            if (seen[B[i]]) {
                ++common;
            } else {
                seen[B[i]] = true;
            }

            ans.push_back(common);
        }

        return ans;
    }
};


//hash table
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int, pair<bool, bool>> M;
        vector<int> ANS(A.size());
        int c = 0;
        for (int i = 0; i < A.size(); i++) {
            if (M.find(A[i]) == M.end()) {
                M[A[i]].first = true;
            } else {
                if (!M[A[i]].first && M[A[i]].second) {
                    c++;
                    M[A[i]].first = true;
                }
            }
            if (M.find(B[i]) == M.end()) {
                M[B[i]].second = true;
            } else {
                if (!M[B[i]].second && M[B[i]].first) {
                    c++;
                    M[B[i]].second = true;
                }
            }
            ANS[i] = c;
        }
        return ANS;
    }
};