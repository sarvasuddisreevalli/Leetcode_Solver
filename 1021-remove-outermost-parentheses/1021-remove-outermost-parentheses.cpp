class Solution {
public:
    string removeOuterParentheses(string s) {
        string a;
        int f=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                if(f!=0) a.push_back(s[i]);
                f++;
            }
            else if(s[i]==')'){
                if(f!=1) a.push_back(s[i]);
                f--;
            }
        }
        return a;
    }
};