class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        vector<vector<int>>ans=grid;
        for(int i=1;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                int mini=INT_MAX;
                for(int k=0;k<j;k++) mini=min(mini,ans[i-1][k]);
                for(int k=j+1;k<grid[0].size();k++) mini=min(mini,ans[i-1][k]);
                if(mini<INT_MAX) ans[i][j]+=mini;
            }
        }
        return *min_element(ans.back().begin(),ans.back().end());
    }
};