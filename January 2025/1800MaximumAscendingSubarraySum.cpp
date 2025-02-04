class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int curr = nums[0], ans = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            curr = nums[i] > nums[i - 1] ? curr + nums[i] : nums[i];
            ans = max(ans, curr);
        }
        return ans;
    }
};

//2nd approach 
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int currentSum = nums[0], maxSum = currentSum;
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                currentSum += nums[i]; 
            } else {
                currentSum = nums[i];
            }
            maxSum = max(maxSum, currentSum); 
        
        }
        
        return maxSum;
    }
};