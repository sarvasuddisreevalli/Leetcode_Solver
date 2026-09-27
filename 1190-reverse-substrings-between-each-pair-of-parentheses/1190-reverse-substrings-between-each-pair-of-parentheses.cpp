class Solution {
public:
    string ans="";
    int i=0;
    string revpar(string &s) {
        string t="";
        i++;
        while(i<s.size()) {
            if(s[i]=='(') t+=revpar(s);
            else if(s[i]==')') {
                reverse(t.begin(),t.end());
                return t;
            }
            else t+=s[i];
            i++;
        }
        return t;
    }
    string reverseParentheses(string s) {
        string ans="",t="";
        while(i<s.size()) {
            if(s[i]=='(') t+=revpar(s);
            else if(s[i]==')') {
                reverse(t.begin(),t.end());
                ans+=t;
                t="";
            }
            else t+=s[i];
            i++;
        }
        return ans+t;
    }
};