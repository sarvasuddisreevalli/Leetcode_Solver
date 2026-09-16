class Solution {
public:
    bool check(int i,int j,int n,vector<string>&ans) {
        int i1=i,j1=j;
        for(int s=0;s<=i;s++) if(ans[s][j]=='Q') return 0;
        for(int s=0;s<=j;s++) if(ans[i][s]=='Q') return 0;
        while(j<n && i>=0) {
            if(ans[i][j]=='Q') return 0;
            i--;
            j++;
        }
        while(j1>=0 && i1>=0) {
            if(ans[i1][j1]=='Q') return 0;
            j1--;
            i1--;
        }
        return 1;
    }

    bool done(vector<string>&ans,int n) {
        for(auto i : ans) for(auto j : i) if(j=='Q') n--;
        if(n==0) return 1;
        return 0;
    }

    void possible_places(vector<string>&ans,int n,int i,int j) {
        if(i==n) {
            if(done(ans,n)==1) a++;
            return;
        }
        else if(j==n) possible_places(ans,n,i+1,0);
        else {
            if(check(i,j,n,ans)==1) {
                ans[i][j]='Q';
                possible_places(ans,n,i,j+1);
                ans[i][j]='.';
            }
            possible_places(ans,n,i,j+1);
        }
    }
    int a=0;
    int totalNQueens(int n) {
        vector<string>ans;
        string t="";
        for(int i=0;i<n;i++) t.push_back('.');
        for(int i=0;i<n;i++) ans.push_back(t);
        possible_places(ans,n,0,0);
        return a;
    }
};