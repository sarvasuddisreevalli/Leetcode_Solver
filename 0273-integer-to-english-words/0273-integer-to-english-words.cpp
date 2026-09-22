class Solution {
public:
    string ones(char ch) {
        if(ch=='0') return "Ten ";
        if(ch=='1') return "Eleven ";
        if(ch=='2') return "Twelve ";
        if(ch=='3') return "Thirteen ";
        if(ch=='4') return "Fourteen ";
        if(ch=='5') return "Fifteen ";
        if(ch=='6') return "Sixteen ";
        if(ch=='7') return "Seventeen ";
        if(ch=='8') return "Eighteen ";
        return "Nineteen ";
    }
    string conv_number(char ch) {
        if(ch=='2') return "Twenty ";
        if(ch=='3') return "Thirty ";
        if(ch=='4') return "Forty ";
        if(ch=='5') return "Fifty ";
        if(ch=='6') return "Sixty ";
        if(ch=='7') return "Seventy ";
        if(ch=='8') return "Eighty ";
        if(ch=='9') return "Ninety ";
        return "";
    }
    string conv_int(char ch) {
        if(ch=='1') return "One ";
        if(ch=='2') return "Two ";
        if(ch=='3') return "Three ";
        if(ch=='4') return "Four ";
        if(ch=='5') return "Five ";
        if(ch=='6') return "Six ";
        if(ch=='7') return "Seven ";
        if(ch=='8') return "Eight ";
        if(ch=='9') return "Nine ";
        return "";
    }
    string numberToWords(int num) {
        if(num==0) return "Zero";
        string s=to_string(num);
        string ans="";
        // Billion
        if(s.size()==10) {
            ans+=conv_int(s[0]);
            ans+="Billion ";
            s.erase(s.begin());
        }
        while(!s.empty() && s[0]=='0') s.erase(s.begin());
        // Million
        if(s.size()>=7) {
            if(s.size()==9) {
                ans+=conv_int(s[0]);
                ans+="Hundred ";
                s.erase(s.begin());
            }
            if(s.size()==8) {
                if(s[0]=='1') ans+=ones(s[1]);
                else {
                    ans+=conv_number(s[0]);
                    if((s[1]-'0')>0) ans+=conv_int(s[1]);
                }
                s.erase(s.begin());
                s.erase(s.begin());
            }
            else{
                ans+=conv_int(s[0]);
                s.erase(s.begin());
            }
            ans+="Million ";
        }
        while(!s.empty() && s[0]=='0') s.erase(s.begin());
        // Thousands
        if(s.size()>=4) {
            if(s.size()==6) {
                ans+=conv_int(s[0]);
                ans+="Hundred ";
                s.erase(s.begin());
            }
            if(s.size()==5) {
                if(s[0]=='1') ans+=ones(s[1]);
                else {
                    ans+=conv_number(s[0]);
                    if((s[1]-'0')>0) ans+=conv_int(s[1]);
                }
                s.erase(s.begin());
                s.erase(s.begin());
            }
            else{
                ans+=conv_int(s[0]);
                s.erase(s.begin());
            }
            ans+="Thousand ";
        }
        while(!s.empty() && s[0]=='0') s.erase(s.begin());
        // Hundreds
        if(s.size()==3) {
            ans+=conv_int(s[0]);
            ans+="Hundred ";
            s.erase(s.begin());
        }
        while(!s.empty() && s[0]=='0') s.erase(s.begin());
        // Tens
        if(s.size()==2) {
            if(s[0]=='1') {
                ans+=ones(s[1]);
                s.erase(s.begin());
                s.erase(s.begin());
            }
            else {
                ans+=conv_number(s[0]);
                s.erase(s.begin());
            }
        }
        while(!s.empty() && s[0]=='0') s.erase(s.begin());
        if(!s.empty()) ans+=conv_int(s[0]);
        while(ans.back()==' ') ans.pop_back();
        return ans;
    }
};