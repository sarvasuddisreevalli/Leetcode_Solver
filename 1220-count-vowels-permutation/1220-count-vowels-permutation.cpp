class Solution {
public:
#define MOD 1000000007;
    int countVowelPermutation(int n) {
        vector<vector<long long>>dp;
        dp.push_back({1,1,1,1,1});
        while(dp.size()<n) {
            vector<long long>t(5);
            t[0]=(dp[dp.size()-1][1]+dp[dp.size()-1][2]+dp[dp.size()-1][4])%MOD;
            t[1]=(dp[dp.size()-1][0]+dp[dp.size()-1][2])%MOD;
            t[2]=(dp[dp.size()-1][1]+dp[dp.size()-1][3])%MOD;
            t[3]=(dp[dp.size()-1][2])%MOD;
            t[4]=(dp[dp.size()-1][2]+dp[dp.size()-1][3])%MOD;
            dp.push_back(t);
        }
        int sum=0;
        for(auto i : dp.back()) {
            // cout<<i<<' ';
            sum+=i%MOD;
            sum%=MOD;
        }
        return sum;
    }
};