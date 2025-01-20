class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int rows = mat.size(), cols = mat[0].size();
        unordered_map<int, pair<int, int>> positionMap;
        vector<int> rowCount(rows, cols), colCount(cols, rows);

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                positionMap[mat[r][c]] = {r, c};
            }
        }

        for (int idx = 0; idx < arr.size(); ++idx) {
            int val = arr[idx];
            auto [row, col] = positionMap[val];

            if (--rowCount[row] == 0 || --colCount[col] == 0) {
                return idx;
            }
        }

        return -1;
    }
};


//different approach

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int, int> mp;
        for(int i = 0; i < arr.size(); i++) mp[arr[i]] = i;
        int n = mat.size(), m = mat[0].size(), ans = INT_MAX;
        for(int i = 0; i < n; i++){
            int temp = INT_MIN;
            for(int j = 0; j < m; j++){
                temp = max(temp, mp[mat[i][j]]);
            }
            ans = min(temp, ans);
        }
        for(int i = 0; i < m; i++){
            int temp = INT_MIN;
            for(int j = 0; j < n; j++){
                temp = max(temp, mp[mat[j][i]]);
            }
            ans = min(temp, ans);
        }
        return ans;
    }
};