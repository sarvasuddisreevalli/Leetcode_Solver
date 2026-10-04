class Solution {
public:
    bool checkValidString(string s) {
        if(s.back()=='(') return false;
        int open=0,star=0;
        stack<char>stk;
        for(auto i : s) {
            if(i!=')') {
                stk.push(i);
                if(i=='*') star++;
                else open++;
            }
            else{
                if(open>0) {
                    open--;
                    if(stk.top()=='(') stk.pop();
                    else {
                        int c=0;
                        while(stk.top()!='(') {
                            c++;
                            stk.pop();
                        }
                        stk.pop();
                        while(c>0) {
                            stk.push('*');
                            c--;
                        }
                    }
                }
                else if(star>0) {
                    star--;
                    stk.pop();
                }
                else return false;
            }
        }
        if(open==0) return true;
        string q="";
        while(!stk.empty()) {
            q.push_back(stk.top());
            stk.pop();
        }
        reverse(q.begin(),q.end());
        int o=0;
        for(auto i : q) {
            if(i=='(') o++;
            else if(o>0) o--;
        }
        if(o==0) return true;
        return false;
    }
};