class Solution {
public:
    string intToRoman(int num) {
        string ans="";
        if((log2(num)+1)>=4) {
            int t=num/1000;
            cout<<t<<endl;
            for(int i=0;i<t;i++) ans+='M';
        }
        if((log2(num)+1)>=3) {
            int t=(num/100)%10;
            if(t==9){
                ans+='C';
                ans+='M';
            }
            else if(t>=5){
                ans+='D';
                for(int i=5;i<t;i++) ans+='C';
            }
            else if(t==4){
                ans+='C';
                ans+='D';
            }
            else {
                for(int i=0;i<t;i++) ans+='C';
            }
        }
        if((log2(num)+1)>=2) {
            int t=(num/10)%10;
            if(t==9){
                ans+='X';
                ans+='C';
            }
            else if(t>=5){
                ans+='L';
                for(int i=5;i<t;i++) ans+='X';
            }
            else if(t==4){
                ans+='X';
                ans+='L';
            }
            else {
                for(int i=0;i<t;i++) ans+='X';
            }
        }
        if((log2(num)+1)>=1) {
            int t=num%10;
            if(t==9){
                ans+='I';
                ans+='X';
            }
            else if(t>=5){
                ans+='V';
                for(int i=5;i<t;i++) ans+='I';
            }
            else if(t==4){
                ans+='I';
                ans+='V';
            }
            else {
                for(int i=0;i<t;i++) ans+='I';
            }
        }
        return ans;
    }
};