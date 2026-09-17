class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        vector<int>dp1(arr.size(),1),dp2(arr.size(),1),dp(arr.size(),1);
        for(int i=0;i<arr.size();i++){
            for(int j=i-1;j>=0 && j>=i-d;j--) {
                if(arr[j]<arr[i]) {
                    dp1[i]=max(dp1[i],1+dp1[j]);
                }
                else break;
            }
        }
        // for(auto i : dp1) cout<<i<<' ';
        // cout<<endl;
        for(int i=arr.size()-1;i>=0;i--) {
            for(int j=i+1;j<arr.size() && j<=i+d;j++) {
                if(arr[j]<arr[i]) {
                    dp2[i]=max(dp2[i],1+dp2[j]);
                }
                else break;
            }
        }
        // for(auto i : dp2) cout<<i<<' ';
        // cout<<endl;
        for(int i=0;i<arr.size();i++) dp[i]=max(dp1[i],dp2[i]);
        // for(auto i : dp) cout<<i<<' ';
        // 2
        vector<int>dp_d=dp;
        dp_d[0]=-1;
        for(int l=0;l<arr.size();l++){
            if(dp_d==dp) break;      
            dp_d=dp;
        for(int i=0;i<arr.size();i++) {
            int maxi=dp[i];
            for(int j=i-1;j>=0 && j>=i-d;j--) {
                if(arr[j]<arr[i]) {
                    maxi=max(maxi,1+dp[j]);
                }
                else break;
            }
            for(int j=i+1;j<arr.size() && j<=i+d;j++) {
                if(arr[j]<arr[i]) {
                    maxi=max(maxi,1+dp[j]);
                }
                else break;
            }
            dp[i]=max(maxi,dp[i]);
        }
        }
        // for(auto i : dp) cout<<i<<' ';
        
        int ans=*max_element(dp.begin(),dp.end());
        return ans;
    }
};