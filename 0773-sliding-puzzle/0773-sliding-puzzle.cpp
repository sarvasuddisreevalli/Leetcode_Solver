class Solution {
public:
    void solve(vector<vector<int>>& board,int u,int v,int cnt) {
        //base cases
        if(cnt>=ans) return;
        if(board==a) {
            ans=cnt;
            return;
        }
        if (m.count(board) && m[board]<=cnt) return;
        m[board]=cnt;
        if(u==1) {
            swap(board[u][v],board[u-1][v]);
            solve(board,u-1,v,cnt+1);
            swap(board[u][v],board[u-1][v]);
        }
        if(u==0) {
            swap(board[u][v],board[u+1][v]);
            solve(board,u+1,v,cnt+1);
            swap(board[u][v],board[u+1][v]);
        }
        if(v>0) {
            swap(board[u][v],board[u][v-1]);
            solve(board,u,v-1,cnt+1);
            swap(board[u][v],board[u][v-1]);
        }
        if(v<2) {
            swap(board[u][v],board[u][v+1]);
            solve(board,u,v+1,cnt+1);
            swap(board[u][v],board[u][v+1]);
        }
    }
    int ans=INT_MAX;
    map<vector<vector<int>>,int>m;
    vector<vector<int>>a={{1,2,3},{4,5,0}};
    int slidingPuzzle(vector<vector<int>>& board) {
        int u=0,v=0;
        for(int i=0;i<2;i++) {
            for(int j=0;j<3;j++) {
                if(board[i][j]==0) {
                    u=i;
                    v=j;
                    break;
                }
            }
        }
        solve(board,u,v,0);
        if(ans==INT_MAX) return -1;
        return ans;
    }
};