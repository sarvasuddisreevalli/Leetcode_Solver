class Solution {
public:
    unordered_map<string,int> finde(string formula,int i,int j) {
        unordered_map<string,int>m1;
        while(i<j) {
            if(formula[i]>64 && formula[i]<=90) {
                string a="";
                a+=formula[i++];
                while(i<j && formula[i]>96 && formula[i]<=122) a+=formula[i++];
                int cnt=0;
                while(i<j && formula[i]>='0' && formula[i]<='9') cnt=cnt*10+(formula[i++]-'0');
                m1[a]+=max(1,cnt);
            }
            else if(formula[i]=='(') {
                i++;
                int p=i;
                int p1=1;
                while(i<j && p1!=0) {
                    if(formula[i]=='(') p1++;
                    if(formula[i]==')') p1--;
                    i++;
                }
                unordered_map<string,int>m=finde(formula,p,i-1);
                int cnt=0;
                while(i<j && formula[i]>='0' && formula[i]<='9')cnt=cnt*10+(formula[i++]-'0');
                cnt=max(cnt,1);
                for(auto i : m) m1[i.first]+=i.second*cnt;
            }
        }
        return m1;
    } 
    string countOfAtoms(string formula) {
        unordered_map<string,int>m;
        int i=0;
        while(i<formula.size()) {
            if(formula[i]>64 && formula[i]<=90) {
                int j=i;
                i++;
                while(i<formula.size() && formula[i]>96 && formula[i]<=122) i++;
                unordered_map<string,int>m1=finde(formula,j,i);
                int cnt=0;
                while(i<formula.size() && formula[i]>='0' && formula[i]<='9') cnt=cnt*10+(formula[i++]-'0');
                cnt=max(1,cnt);
                for(auto i : m1) m[i.first]+=cnt*i.second;
            }
            else if(formula[i]=='(') {
                i++;
                int j=i;
                int p1=1;
                while(i<formula.size() && p1!=0) {
                    if(formula[i]=='(') p1++;
                    if(formula[i]==')') p1--;
                    i++;
                }
                unordered_map<string,int>m1=finde(formula,j,i-1);
                int cnt=0;
                while(i<formula.size() && formula[i]>='0' && formula[i]<='9')cnt=cnt*10+(formula[i++]-'0');
                cnt=max(cnt,1);
                for(auto i : m1) m[i.first]+=i.second*cnt;
            }
        }
        priority_queue<string,vector<string>,greater<string>>q;
        for(auto i : m) q.push(i.first);
        string ans="";
        while(!q.empty()) {
            ans+=q.top();
            if(m[q.top()]>1) ans+=to_string(m[q.top()]);
            q.pop();
        }
        return ans;
    }
};