class Solution {
public:
    long long s_to_i(string s) {
        return stoll(s);
    }
    long long finde(string& s) {
        stack<string>st;
        string b="";
        while(i<s.size() && s[i]!=')') {
            if(s[i]>='0' && s[i]<='9') b+=s[i];
            else if(!b.empty()) {
                st.push(b);
                b="";
            }
            if(s[i]=='-') st.push("-");
            else if(s[i]=='+') st.push("+");
            else if(s[i]=='(') {
                i++;
                long long x=finde(s);
                st.push(to_string(x));
            }
            i++;
        }
        if(!b.empty()) st.push(b);
        if(st.empty()) return 0;
        long long ans=0;
        while(!st.empty()) {
            if(st.top()=="+" || st.top()=="-") {
                st.pop();
                continue;
            }
            long long xx=s_to_i(st.top());
            st.pop();
            if(!st.empty() && st.top()=="+") {
                st.pop();
                ans+=xx;
            }
            else if(!st.empty() && st.top()=="-") {
                st.pop();
                ans-=xx;
            }
            else ans+=xx;
        }
        return ans;
    }
    int i=0;

    int calculate(string s) {
        string a="";
        stack<string>st;
        while(i<s.size()) {
            if(s[i]>='0' && s[i]<='9') {
                a+=s[i];
            }
            else if(!a.empty()) {
                st.push(a);
                a="";
            }
            if(s[i]=='-') st.push("-");
            else if(s[i]=='+') st.push("+");
            else if(s[i]=='(') {
                i++;
                long long x=finde(s);
                st.push(to_string(x));
            }
            i++;
        }
        if(!a.empty()) st.push(a);
        if(st.empty()) return 0;
        long long ans=0;
        while(!st.empty()) {
            if(st.top()=="+" || st.top()=="-") {
                st.pop();
                continue;
            }
            long long xx=s_to_i(st.top());
            st.pop();
            if(!st.empty() && st.top()=="+") {
                st.pop();
                ans+=xx;
            }
            else if(!st.empty() && st.top()=="-") {
                st.pop();
                ans-=xx;
            }
            else ans+=xx;
        }
        return ans;
    }
};