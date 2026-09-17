class Solution {
public:
    string longestPrefix(string s) {
        string ans="",a="";
        deque<char>d1,d2;
        int i=0,j=s.size()-1;
        while(i<s.size()-1) {
            a+=s[i];
            d1.push_back(s[i++]);
            d2.push_front(s[j--]);
            if(d1==d2 && a>ans) ans=a;
        }
        return ans;
    }
};