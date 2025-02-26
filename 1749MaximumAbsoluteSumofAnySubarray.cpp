class Solution {
    public:
        int maxAbsoluteSum(vector<int>& nums) {
            int sum = 0, minSum = 0, maxSum = 0;
            for (int num : nums) {
                sum += num;
                if (sum > maxSum) maxSum = sum;
                if (sum < minSum) minSum = sum;
            }
            return abs(maxSum - minSum);
        }
    };

    //prefix sum method
    class Solution {
        public:
            int maxAbsoluteSum(std::vector<int>& nums) {
                int prefixSum = 0;
                int minPrefixSum = 0;
                int maxPrefixSum = 0;
                int maxAbsoluteSum = 0;
        
                for (int i = 0; i < nums.size(); i++) {
                    prefixSum += nums[i]; // Update prefix sum
                    
                    // Update maxAbsoluteSum
                    maxAbsoluteSum = std::max(maxAbsoluteSum, std::abs(prefixSum - minPrefixSum));
                    maxAbsoluteSum = std::max(maxAbsoluteSum, std::abs(prefixSum - maxPrefixSum));
                    
                    // Update minPrefixSum and maxPrefixSum
                    minPrefixSum = std::min(minPrefixSum, prefixSum);
                    maxPrefixSum = std::max(maxPrefixSum, prefixSum);
                }
        
                return maxAbsoluteSum;
            }
        };
        