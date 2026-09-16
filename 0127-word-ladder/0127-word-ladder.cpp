class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>word(wordList.begin(),wordList.end());
        queue<string>q;
        unordered_set<string>s;
        int cnt=0;
        q.push(beginWord);
        s.insert(beginWord);
        while(!q.empty()) {
            cnt++;
            int len=q.size();
            for(int l=0;l<len;l++) {
                string t=q.front();
                q.pop();
                if(t==endWord) return cnt;
                for(int i=0;i<t.size();i++) {
                    for(int j=0;j<26;j++) {
                        char ch=t[i];
                        t[i]=('a'+j);
                        if(word.count(t)>0 && s.count(t)==0) {
                            s.insert(t);
                            q.push(t);
                        }
                        t[i]=ch;
                    }
                }
            }  
        }
        return 0;
    }
};