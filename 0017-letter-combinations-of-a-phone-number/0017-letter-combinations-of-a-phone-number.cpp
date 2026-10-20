class Solution {
public:
    void fun(string digits,int i) {
        if(t.size()==digits.size() && t.size()>0) {
            ans.push_back(t);
            return;
        }
        if(i>=digits.size()) return;
        else {
            if(digits[i]=='2'){
                t.push_back('a');
                fun(digits,i+1);
                t.pop_back();
                t.push_back('b');
                fun(digits,i+1);
                t.pop_back();
                t.push_back('c');
                fun(digits,i+1);
                t.pop_back();
            }
            else if(digits[i]=='3'){
                t.push_back('d');
                fun(digits,i+1);
                t.pop_back();
                t.push_back('e');
                fun(digits,i+1);
                t.pop_back();
                t.push_back('f');
                fun(digits,i+1);
                t.pop_back();
            }
            else if(digits[i]=='4'){
                t.push_back('g');
                fun(digits,i+1);
                t.pop_back();
                t.push_back('h');
                fun(digits,i+1);
                t.pop_back();
                t.push_back('i');
                fun(digits,i+1);
                t.pop_back();
            }
            else if(digits[i]=='5'){
                t.push_back('j');
                fun(digits,i+1);
                t.pop_back();
                t.push_back('k');
                fun(digits,i+1);
                t.pop_back();
                t.push_back('l');
                fun(digits,i+1);
                t.pop_back();
            }
            else if(digits[i]=='6'){
                t.push_back('m');
                fun(digits,i+1);
                t.pop_back();
                t.push_back('n');
                fun(digits,i+1);
                t.pop_back();
                t.push_back('o');
                fun(digits,i+1);
                t.pop_back();
            }
            else if(digits[i]=='7'){
                t.push_back('p');
                fun(digits,i+1);
                t.pop_back();
                t.push_back('q');
                fun(digits,i+1);
                t.pop_back();
                t.push_back('r');
                fun(digits,i+1);
                t.pop_back();
                t.push_back('s');
                fun(digits,i+1);
                t.pop_back();
            }
            else if(digits[i]=='8'){
                t.push_back('t');
                fun(digits,i+1);
                t.pop_back();
                t.push_back('u');
                fun(digits,i+1);
                t.pop_back();
                t.push_back('v');
                fun(digits,i+1);
                t.pop_back();
            }
            else if(digits[i]=='9'){
                t.push_back('w');
                fun(digits,i+1);
                t.pop_back();
                t.push_back('x');
                fun(digits,i+1);
                t.pop_back();
                t.push_back('y');
                fun(digits,i+1);
                t.pop_back();
                t.push_back('z');
                fun(digits,i+1);
                t.pop_back();
            }
        }
    }
    vector<string>ans;
    string t="";
    vector<string> letterCombinations(string digits) {
        fun(digits,0);
        return ans;
    }
};