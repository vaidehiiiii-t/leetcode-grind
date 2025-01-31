class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        if (grid.empty())
            return 0;

        int n = grid.size();
        vector<vector<int>> labels(n,vector<int>(n, 0));
        unordered_map<int, int> islandSizes;
        int label = 1;
        int maxSize = 0;

        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1 && labels[i][j] == 0) {
                    int size = 0;
                    vector<pair<int, int>> stack;
                    stack.push_back({i, j});
                    labels[i][j] = label;

                    while (!stack.empty()) {
                        auto [x, y] = stack.back();
                        stack.pop_back();
                        size++;

                        for (auto [dx, dy] : dirs) {
                            int nx = x + dx, ny = y + dy;
                            if (nx >= 0 && nx < n && ny >= 0 && ny < n &&
                                grid[nx][ny] == 1 && labels[nx][ny] == 0) {
                                labels[nx][ny] = label;
                                stack.push_back({nx, ny});
                            }
                        }
                    }

                    islandSizes[label] = size;
                    maxSize = max(maxSize, size);
                    label++;
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    unordered_set<int> neighborLabels;
                    int total = 1;

                    for (auto [dx, dy] : dirs) {
                        int nx = i + dx, ny = j + dy;
                        if (nx >= 0 && nx < n && ny >= 0 && ny < n &&
                            grid[nx][ny] == 1) {
                            neighborLabels.insert(labels[nx][ny]);
                        }
                    }

                    for (int lbl : neighborLabels) {
                        total += islandSizes[lbl];
                    }

                    maxSize = max(maxSize, total);
                }
            }
        }

        return maxSize;
    }
};

//DFS approach
class Solution {
public:
    unordered_map<int, int> unmap;

    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& visited, int key) {
        int n = grid.size();
        if (i < 0 || j < 0 || i >= n || j >= n || visited[i][j] || grid[i][j] == 0) {
            return 0;
        }
        visited[i][j] = true;
        int count = 1 + dfs(i + 1, j, grid, visited, key)
                    + dfs(i - 1, j, grid, visited, key)
                    + dfs(i, j + 1, grid, visited, key)
                    + dfs(i, j - 1, grid, visited, key);
        grid[i][j] = key;
        return count;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int key = 2;
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && grid[i][j] == 1) {
                    int count = dfs(i, j, grid, visited, key);
                    unmap[key] = count;
                    key++;
                }
            }
        }

        int result = -1;
        vector<vector<bool>> visited2(n, vector<bool>(n, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    int a = (i + 1 < n) ? grid[i + 1][j] : 0;
                    int b = (i - 1 >= 0) ? grid[i - 1][j] : 0;
                    int c = (j + 1 < n) ? grid[i][j + 1] : 0;
                    int d = (j - 1 >= 0) ? grid[i][j - 1] : 0;
                    set<int> st;
                    st.insert(a);
                    st.insert(b);
                    st.insert(c);
                    st.insert(d);
                    int res = 1;
                    for (auto it = st.begin(); it != st.end(); it++) {
                        res += unmap[*it];
                    }
                    result = max(result, res);
                }
            }
        }

        if (result == -1) {
            return n * n;
        }
        return result;
    }
};