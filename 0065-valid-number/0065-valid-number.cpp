class Solution {
public:
    bool isNumber(string s) {
        if(s[0]=='+'|| s[0]=='-') s.erase(s.begin());
        if(s.empty()) return 0;
        int i=0;
        int dot=0;
        while(i<s.size()) {
            if(s[i]=='e' || s[i]=='E') {
                i++;
                break;
            }
            else if(s[i]=='.') {
                if(dot) return 0;
                if((i>0 && (s[i-1]>='0' && s[i-1]<='9')) || (i<s.size()-1 && (s[i+1]>='0' && s[i+1]<='9'))) i++;
                else return 0;
                dot++;
            }
            else if(s[i]>='0' && s[i]<='9') i++;
            else return 0;
        } 
        if(i<s.size() && (s[i]=='+'|| s[i]=='-')) {
            if(i>0 && (s[i-1]=='e' || s[i-1]=='E')) {
                if(((i>=2 && s[i-2]>='0' && s[i-2]<='9') || (i>=3 && s[i-3]>='0' && s[i-3]<='9' && s[i-2]=='.')) && (i<s.size()-1 && s[i+1]>='0' && s[i+1]<='9'));
                
                else return 0;
            }
            i++;
        }
        else if(i>0 && (s[i-1]=='e' || s[i-1]=='E')) {
            if(((i>=2 && s[i-2]>='0' && s[i-2]<='9') || (i>=3 && s[i-3]>='0' && s[i-3]<='9' && s[i-2]=='.')) && (i<s.size() && s[i]>='0' && s[i]<='9'));
            else return 0;
        }
        while(i<s.size()) {
            if(s[i]>='0' && s[i]<='9') i++;
            else return 0;
        }
        if(!s.empty()) return 1;
        return 0;
    }
};