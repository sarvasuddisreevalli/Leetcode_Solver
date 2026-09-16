class Solution {
public:
    char processStr(string s, long long k) {
        long long len=0;
        for(auto i : s) {
            if(i>='a' && i<='z') len++;
            else if(i=='*' && len>0) len--;
            else if(i=='#') len*=2;
        }
        // cout<<len<<endl;
        if(k>=len) return '.';
        else {
            for(int i=s.size()-1;i>=0;i--) {
                if(s[i]>='a' && s[i]<='z') {
                    len--;
                    if(len==k) return s[i];
                }
                else if(s[i]=='%') k=len-k-1;
                else if(s[i]=='#') {
                    len/=2;
                    if(k>=len) k-=len;
                }
                else if(s[i]=='*') len++;
            }
        }
        return '.';
    }
};