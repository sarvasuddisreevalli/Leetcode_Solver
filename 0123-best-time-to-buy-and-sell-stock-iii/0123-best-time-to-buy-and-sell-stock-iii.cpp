class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int>p(prices.size(),0);
        int mini=prices[0];
        for(int i=1;i<prices.size();i++) {
            p[i]=p[i-1];
            if(prices[i]>mini) p[i]=max(p[i-1],prices[i]-mini);
            else mini=prices[i];
        }
        vector<int>s(prices.size(),0);
        int maxi=prices.back();
        for(int i=prices.size()-2;i>=0;i--) {
            s[i]=s[i+1];
            if(prices[i]<maxi) s[i]=max(s[i+1],maxi-prices[i]);
            else maxi=prices[i];
        }
        int ans=0;
        for(int i=0;i<prices.size();i++) ans=max(ans,p[i]+s[i]);
        return ans;
    }
};