class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";
        int bf=0;
        for(auto i : s) {
            if(i=='(' && bf==0) bf++;
            else if(i==')' && bf==1) {
                bf=0;
            }
            else {
                if(i==')') bf--;
                else bf++;
                ans+=i;
            }
        }
        return ans;
    }
};