class Solution {
public:
    int longestAwesome(string s) {
        map<int,int>m;
        m[0]=0;
        int b=0,ans=1;
        for(int i=0;i<s.size();i++) {
            int c=(1<<(s[i]-'0'));
            b^=c;
            if(m.find(b)!=m.end()) ans=max(ans,i-m[b]+1);
            for(int j=0;j<=9;j++) {
                int d=b^(1<<j);
                if(m.find(d)!=m.end()) ans=max(ans,i-m[d]+1);
            }
            if(m.find(b)==m.end()) m[b]=i+1;
        }
        return ans;
    }
};