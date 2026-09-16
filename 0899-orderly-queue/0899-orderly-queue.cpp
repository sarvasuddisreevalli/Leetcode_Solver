class Solution {
public:
    string orderlyQueue(string s, int k) {
        string ans=s;
        if(k>=2) sort(ans.begin(),ans.end());
        else {
            for(int i=1;i<s.size();i++) {
                ans = min(ans,s.substr(i)+s.substr(0,i));
            }
        }
        return ans;
    }
};