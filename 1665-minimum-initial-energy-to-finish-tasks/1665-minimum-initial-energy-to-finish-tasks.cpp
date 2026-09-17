class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        priority_queue<pair<int,int>>q1;
        for(auto i : tasks) q1.push({i[1]-i[0],-i[0]});
        int ans=0,rem=0;
        while(!q1.empty()) {
            int left=-q1.top().second;
            int right=q1.top().first+left;
            if(right>rem) {
                ans+=right-rem;
                rem=right-left;
            }
            else rem-=left;
            q1.pop();
        }
        return ans;
    }
};