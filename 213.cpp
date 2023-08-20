class Solution {
public:
    int robRange(int start, int end, vector<int>& nums) {
        int n = end - start + 1;
        vector<int> dp(n);
        
        dp[0] = nums[start];
        dp[1] = max(nums[start], nums[start + 1]);
        
        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[start + i]);
        }
        
        return dp[n - 1];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        if (n == 2) {
            return max(nums[0], nums[1]);
        }
        
        return max(robRange(0, n - 2, nums), robRange(1, n - 1, nums));
    }
};
