class Solution {
public:
    void solve(vector<vector<int>>& grid,int u,int v,int cnt) {
        if(t.size()==cnt+1) {
            // for(auto i : t) cout<<i.first<<','<<i.second<<' ';
            // cout<<endl;
            if(grid[u][v]==4) m[t]++;
            return;
        }
        if(u<grid.size()-1 && grid[u+1][v]==0) {
            grid[u+1][v]=3;
            t.push_back({u+1,v});
            solve(grid,u+1,v,cnt);
            grid[u+1][v]=0;
            t.pop_back();
        }
        if(v<grid[0].size()-1 && grid[u][v+1]==0) {
            grid[u][v+1]=3;
            t.push_back({u,v+1});
            solve(grid,u,v+1,cnt);
            grid[u][v+1]=0;
            t.pop_back();
        }
        if(u>0 && grid[u-1][v]==0) {
            grid[u-1][v]=3;
            t.push_back({u-1,v});
            solve(grid,u-1,v,cnt);
            grid[u-1][v]=0;
            t.pop_back();
        }
        if(v>0 && grid[u][v-1]==0) {
            grid[u][v-1]=3;
            t.push_back({u,v-1});
            solve(grid,u,v-1,cnt);
            grid[u][v-1]=0;
            t.pop_back();
        }
        //for reaching end
        if(u<grid.size()-1 && grid[u+1][v]==2) {
            grid[u+1][v]=4;
            t.push_back({u+1,v});
            solve(grid,u+1,v,cnt);
            grid[u+1][v]=2;
            t.pop_back();
        }
        if(v<grid[0].size()-1 && grid[u][v+1]==2) {
            grid[u][v+1]=4;
            t.push_back({u,v+1});
            solve(grid,u,v+1,cnt);
            grid[u][v+1]=2;
            t.pop_back();
        }
        if(u>0 && grid[u-1][v]==2) {
            grid[u-1][v]=4;
            t.push_back({u-1,v});
            solve(grid,u-1,v,cnt);
            grid[u-1][v]=2;
            t.pop_back();
        }
        if(v>0 && grid[u][v-1]==2) {
            grid[u][v-1]=4;
            t.push_back({u,v-1});
            solve(grid,u,v-1,cnt);
            grid[u][v-1]=2;
            t.pop_back();
        }
    }
    vector<pair<int,int>>t;
    map<vector<pair<int,int>>,int>m;

    int uniquePathsIII(vector<vector<int>>& grid) {
        int i=0,j=0,cnt=0;
        for(int l=0;l<grid.size();l++) {
            for(int k=0;k<grid[0].size();k++) {
                if(grid[l][k]==0) cnt++;
                else if(grid[l][k]==1) {
                    i=l;
                    j=k;
                }
            }
        }
        solve(grid,i,j,cnt);
        return m.size();
    }
};