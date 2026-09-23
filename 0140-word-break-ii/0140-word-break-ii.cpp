class Solution {
public:
    void finde(string &s,set<string>&se_s, vector<string>&ans, set<string>&se_ans,int i, string &t, string &temp) {
        while(!t.empty() && t[0]==' ') t.erase(t.begin());
        // basecase
        if(i==s.size()) {
            if(temp.empty() && se_ans.count(t)==0) {
                se_ans.insert(t);
                ans.push_back(t);
            }
            return;
        }
        temp+=s[i];
        string ta=t+' ',ti="";
        ta+=temp;
        if(se_s.count(temp)>0) finde(s,se_s,ans,se_ans,i+1,ta,ti);
        finde(s,se_s,ans,se_ans,i+1,t,temp);
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        set<string>se_s,se_ans;
        for(auto i : wordDict) se_s.insert(i);
        vector<string>ans;
        string t="",temp="";
        finde(s,se_s,ans,se_ans,0,t,temp);
        return ans;
    }
};