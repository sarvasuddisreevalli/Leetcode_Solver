class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        long long dp[n+1][m+1];
        for(int i=0;i<=n;i++) for(int j=0;j<=m;j++) dp[i][j]=0;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                dp[i][j]=nums1[i-1]*nums2[j-1];
                if(dp[i-1][j-1]>0) dp[i][j]+=dp[i-1][j-1];
                if(i>1) dp[i][j]=max(dp[i][j],dp[i-1][j]);
                if(j>1) dp[i][j]=max(dp[i][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};