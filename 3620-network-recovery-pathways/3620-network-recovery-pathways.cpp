class Solution {
public:
    bool finde(int mid,int n,vector<vector<pair<int,int>>>& edge,long long k) {
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>q;
        vector<long long>sume(n,LLONG_MAX);
        sume[0]=0;
        q.push({0,0});
        while(!q.empty()) {
            int p=q.top().second;
            long long sum=q.top().first;
            q.pop();
            if(p==n-1) return 1;
            if(sum > sume[p]) continue;
            for(auto i : edge[p]) {
                if(i.second>=mid && sum+i.second<=k && sume[i.first]>(sum+i.second)) {
                    sume[i.first]=sum+i.second;
                    q.push({sume[i.first],i.first});
                }
            }
        }
        return 0;
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n=online.size();
        vector<vector<pair<int,int>>>edge(n);
        int ans=-1;
        int l=0,r=0;
        for(auto i : edges) {
            r=max(r,i[2]);
            if(online[i[0]] && online[i[1]]) edge[i[0]].push_back({i[1],i[2]});
        }
        while(l<=r) {
            int mid=l+(r-l)/2;
            if(finde(mid,n,edge,k)==1) {
                // cout<<mid<<endl;
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        return ans;
    }
};