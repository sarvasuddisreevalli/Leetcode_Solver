class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n=people.size();
        for(int i=0;i<n;i++) swap(people[i][0],people[i][1]);
        sort(people.begin(),people.end());
        vector<vector<int>>ans;
        ans.push_back({people[0][1],people[0][0]});
        for(int i=1;i<n;i++) {
            swap(people[i][0],people[i][1]);
            ans.push_back(people[i]);
            int cnt=0;
            int j=0;
            while(j<ans.size()-1) {
                if(ans[j][0]>=people[i][0]) cnt++;
                if(cnt>people[i][1]) break;
                j++;
            }
            for(int l=ans.size()-1;l>j;l--) ans[l]=ans[l-1];
            ans[j]=people[i];
        }
        return ans;
    }
};