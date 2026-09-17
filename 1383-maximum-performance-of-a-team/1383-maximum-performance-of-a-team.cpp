class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        long long ans=0,maxi=0;
        vector<pair<int,int>>a;
        for(int i=0;i<n;i++) a.push_back({efficiency[i],speed[i]});
        sort(a.rbegin(),a.rend());
        priority_queue<int,vector<int>,greater<int>>q;
        for(auto i : a) {
            if(q.size()<k) {
                ans+=i.second;
                q.push(i.second);
                maxi=max(1LL*maxi,1LL*ans*i.first);
                // maxi=max(1LL*maxi,(1LL*(ans%1000000007)*(i.first%1000000007))%1000000007);
            }
            else if(q.top()<i.second) {
                ans-=q.top();
                q.pop();
                ans+=i.second;
                q.push(i.second);
                maxi=max(1LL*maxi,1LL*ans*i.first);
            }
        }
        return maxi%1000000007;
    }
};