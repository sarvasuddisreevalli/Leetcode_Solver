class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        long long MOD=1000000007;
        int n=board.size(),m=board[0].size();
        vector<vector<int>>len(n,vector<int>(m,0));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(board[i][j]=='X' || board[i][j]=='E') continue; 
                int maxi=-1;
                if(i>0 && j>0) maxi=max(maxi,len[i-1][j-1]);
                if(i>0) maxi=max(maxi,len[i-1][j]);
                if(j>0) maxi=max(maxi,len[i][j-1]);
                if(maxi==-1) {
                    if(i<=1 && j<=1) len[i][j]=(board[i][j]-'0');
                    else return {0,0};
                }
                else if(board[i][j]=='S') len[i][j]=maxi;
                else len[i][j]=(board[i][j]-'0')+maxi;
            }
        }
        vector<vector<long long>>ans(n,vector<long long>(m,0));
        ans[0][0]=1;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(board[i][j]=='X' || board[i][j]=='E') continue; 
                int maxi=len[i][j];
                if(maxi==-1) continue;
                if(board[i][j]!='S') maxi-=(board[i][j]-'0');
                if(i>0 && j>0 && len[i-1][j-1]==maxi) ans[i][j]=(ans[i][j]+ans[i-1][j-1])%MOD;
                if(i>0 && len[i-1][j]==maxi) ans[i][j]=(ans[i][j]+ans[i-1][j])%MOD;
                if(j>0 && len[i][j-1]==maxi) ans[i][j]=(ans[i][j]+ans[i][j-1])%MOD;
            }
        }
        if(ans[n-1][m-1]==0) return {0,0};
        return {len[n-1][m-1],(int)ans[n-1][m-1]};
    }
};