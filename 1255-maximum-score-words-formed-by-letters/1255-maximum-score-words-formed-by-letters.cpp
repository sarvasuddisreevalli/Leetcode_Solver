class Solution {
public:
    int ans=0;

    void finde(vector<string>&words,vector<char>&letters,vector<int>&score,map<char,int>&m,int idx,int p) {
        if(idx>=words.size()) {
            ans=max(ans,p);
            return;
        }
        int flag=0;
        int p1=0;
        for(auto i :words[idx]) {
            m[i]--;
            p1+=score[i-'a'];
            if(m[i]<0) flag=1;
        }
        if(flag==0) finde(words,letters,score,m,idx+1,p+p1);
        for(auto i :words[idx]) {
            m[i]++;
        }
        finde(words,letters,score,m,idx+1,p);
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        map<char,int>m;
        for(auto i : letters) m[i]++;
        finde(words,letters,score,m,0,0);
        return ans;
    }
};