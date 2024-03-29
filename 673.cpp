#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size(), maxi = 1;
        vector<int> dp(n, 1);
        vector<int> cnt(n, 1);
        for(int i = 1; i< n; i++){
            for(int j = 0; j<i; j++){
                if(nums[i]>nums[j]){
                    if(dp[j]+1>dp[i]){
                        dp[i] = dp[j]+1;
                        cnt[i] = cnt[j];
                    } else if(dp[j]+1==dp[i]){
                        cnt[i]+=cnt[j];
                    }
                }
            }
            maxi = max(maxi, dp[i]);
        }
        int res = 0;
        for (int i = 0; i < n; i++){
            if (dp[i]==maxi){
                res+=cnt[i];
            }
        }
        return res;
        
    }
};