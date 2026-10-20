class Solution {
public:
    void Aback(string s,int i) {
        if(i==s.size()) {
            ans.push_back(s);
            return;
        }
        if(s[i]>=97 && s[i]<=122) {
            Aback(s,i+1);
            s[i]-=32;
            Aback(s,i+1);
        }
        else {
            Aback(s,i+1);
        }
    }
    vector<string>ans;
    vector<string> letterCasePermutation(string s) {
        transform(s.begin(), s.end(), s.begin(),::tolower);
        ans.push_back(s);
        Aback(s,0);
        vector<string>res;
        sort(ans.begin(),ans.end());
        for(auto i : ans){
            if(res.empty() || res[res.size()-1]!=i) res.push_back(i);
        }
        return res;
    }
};