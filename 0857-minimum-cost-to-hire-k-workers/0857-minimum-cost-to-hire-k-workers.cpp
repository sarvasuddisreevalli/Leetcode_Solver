class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector<pair<double,int>>a;
        for(int i=0;i<wage.size();i++) a.push_back({(double)wage[i]/quality[i],quality[i]});
        sort(a.begin(),a.end());
        priority_queue<int>q;
        double ans=1e18;
        long long sum=0;
        for(int i=0;i<a.size();i++) {
            sum+=a[i].second;
            q.push(a[i].second);

            if(q.size()>k) {
                sum-=q.top();
                q.pop();
            }
            if(q.size()==k) ans=min(ans,sum*a[i].first);
        } 
        return ans;
    }
};