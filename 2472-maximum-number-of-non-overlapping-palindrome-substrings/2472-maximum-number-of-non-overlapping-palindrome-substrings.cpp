class Solution {
public:
    bool ispalindrome(string s) {
        string s1=s;
        reverse(s1.begin(),s1.end());
        return s==s1;
    }
    int maxPalindromes(string s, int k) {
        int cnt=0;
        int i=0;
        while(i+k<=s.size()) {
            string p=s.substr(i,k),p1=p;
            reverse(p1.begin(),p1.end());
            if(p==p1) {
                i+=k;
                cnt++;
            }
            else if(i+k<s.size() && p+s[i+k]==s[i+k]+p1) {
                i+=k+1;
                cnt++;
            }
            else i++;
        }
        return cnt;
    }
};