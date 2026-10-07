class Solution {
public:
    int maxi=0;
    map<int,vector<string>>m;
    void finde(string &s, int i,string &t,int bf) {
        if(i==s.size()) {
            if(bf==0) {
                if(t.size()>maxi) {
                    m.clear();
                    maxi=t.size();
                    m[maxi].push_back(t);
                }
                else if(t.size()==maxi) m[maxi].push_back(t);
            }
            return;
        }
        else if(t.size()+(s.size()-i) < maxi) return;
        t+=s[i];
        if(s[i]=='(') finde(s,i+1,t,bf+1);
        else if(s[i]!=')') finde(s,i+1,t,bf);
        else if(bf>0 && s[i]==')') finde(s,i+1,t,bf-1);
        t.pop_back();
        finde(s,i+1,t,bf);
    }
    vector<string> removeInvalidParentheses(string s) {
        maxi=0;
        m.clear();
        string t="";
        finde(s,0,t,0);
        if(m[maxi].empty()) return {""};
        vector<string>ans;
        set<string>se(m[maxi].begin(),m[maxi].end());
        for(auto i : se) ans.push_back(i);
        return ans;
    }
};