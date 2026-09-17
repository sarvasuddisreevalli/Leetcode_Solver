class Solution {
public:
    int maxSatisfaction(vector<int>& sat) {
        sort(sat.begin(),sat.end());
        vector<long long>dp(sat.size()),ans(sat.size());
        dp[sat.size()-1]=sat.back();
        ans[sat.size()-1]=sat.back();
        for(int i=sat.size()-2;i>=0;i--) {
            dp[i]=dp[i+1]+sat[i];
            ans[i]=dp[i]+ans[i+1];
        }
        ans.push_back(0);
        return *max_element(ans.begin(),ans.end());
    }
};