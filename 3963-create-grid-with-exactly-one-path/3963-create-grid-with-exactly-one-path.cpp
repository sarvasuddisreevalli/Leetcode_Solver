class Solution {
public:
    vector<string> createGrid(int m, int n) {
        string s(n,'#');
        vector<string>res(m,s);
        for(int i=0;i<n;i++) res[0][i]='.';
        for(int i=0;i<m;i++) res[i][n-1]='.';
        return res;
    }
};