class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& arr, int threshold) {
        vector<pair<int, int>> valueIndexPairs;
        int size = arr.size();

        for (int i = 0; i < size; ++i) {
            valueIndexPairs.push_back({arr[i], i});
        }

        sort(valueIndexPairs.begin(), valueIndexPairs.end());

        vector<vector<pair<int, int>>> groupedPairs;
        groupedPairs.push_back({valueIndexPairs[0]});

        for (int i = 1; i < size; ++i) {
            if (valueIndexPairs[i].first - valueIndexPairs[i - 1].first <= threshold) {
                groupedPairs.back().push_back(valueIndexPairs[i]);
            } else {
                groupedPairs.push_back({valueIndexPairs[i]});
            }
        }

        for (const auto& group : groupedPairs) {
            vector<int> indices;
            for (const auto& [value, index] : group) {
                indices.push_back(index);
            }

            sort(indices.begin(), indices.end());

            for (size_t i = 0; i < indices.size(); ++i) {
                arr[indices[i]] = group[i].first;
            }
        }

        return arr;
    }
};


//2nd approach 
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> ans(n,0);
        priority_queue<int,vector<int>,greater<int>> pq;
        vector<vector<int>> arr(n);
        for(int i=0;i<n;i++){
            arr[i] = {nums[i],i};
        }
        sort(arr.begin(),arr.end());
        pq.push(arr[0][1]);
        int i=0,j=1;
        while(i<n && j<n){
            if(arr[j][0]-arr[j-1][0] > limit){
                // Up to here, we made one group so arrange these in ans array
                while(!pq.empty()){
                    ans[pq.top()] = arr[i][0];
                    pq.pop();
                    i++;
                }
            }
            pq.push(arr[j][1]);
            j++;
        }

        while(!pq.empty()){
            ans[pq.top()] = arr[i][0];
            pq.pop();
            i++;
        }

        return ans;

    }
};