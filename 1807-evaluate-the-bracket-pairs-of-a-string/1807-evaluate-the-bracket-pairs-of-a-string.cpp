class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string ans="";
        map<string,string>m;
        for(auto i : knowledge) {
            m[i[0]]=i[1];
        }
        int i=0;
        while(i<s.size()) {
            if(s[i]=='(') {
                int j=i+1;
                string t="";
                while(j<s.size() && s[j]!=')') t+=s[j++];
                if(m[t]!="") {
                    for(auto k : m[t]) ans+=k;
                }
                else ans+='?';
                i=j+1;
            }
            else ans+=s[i++];
        }
        return ans;
    }
};