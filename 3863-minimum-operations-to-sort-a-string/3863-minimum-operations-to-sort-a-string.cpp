class Solution {
public:
    bool is(string s,int start,int end) {
        string a=s.substr(start,end-start),b=a;
        sort(a.begin(),a.end());
        if(a!=b) return 0;
        return 1;
    }
    int minOperations(string s) {
        int cnt=0;
        string s1=s;
        sort(s1.begin(),s1.end());
        if(s.size()<=2) {
            if(s1==s) return 0;
            return -1;
        }
        int cnt1=0,cnt2=0;
        string s2=s;
        if(is(s,1,s.size())==0) {
            sort(s.begin()+1,s.end());
            cnt1++;
        }
        if(is(s,0,s.size()-1)==0) {
            sort(s.begin(),s.end()-1);
            cnt1++;
        }
        while(s!=s1) {
            if(s!=s1) {
                sort(s.begin(),s.end()-1);
                cnt1++;
            }
            if(s!=s1) {
                sort(s.begin()+1,s.end());
                cnt1++;
            }
        }
        //
        if(is(s2,0,s2.size()-1)==0) {
            sort(s2.begin(),s2.end()-1);
            cnt2++;
        }
        if(is(s2,1,s2.size())==0) {
            sort(s2.begin()+1,s2.end());
            cnt2++;
        }
        while(s2!=s1) {
            if(s2!=s1) {
                sort(s2.begin(),s2.end()-1);
                cnt2++;
            }
            if(s2!=s1) {
                sort(s2.begin()+1,s2.end());
                cnt2++;
            }
        }
        return min(cnt1,cnt2);
    }
};