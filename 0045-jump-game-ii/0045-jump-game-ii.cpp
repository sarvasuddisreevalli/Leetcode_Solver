class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int>dp(nums.size(),INT_MAX);
        dp[0]=0;
        for(int i=0;i<nums.size();i++) {
            if(dp[i]==INT_MAX) continue;
            int j=i;
            while(j<=i+nums[i] && j<nums.size()) {
                dp[j]=min(dp[j],dp[i]+1);
                j++;
            }
        }
        return dp.back();
    }
};