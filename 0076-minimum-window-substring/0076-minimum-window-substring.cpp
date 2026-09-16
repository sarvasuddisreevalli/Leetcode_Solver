class Solution {
public:
    string minWindow(string s, string t) {
        string ans="";
	    unordered_map<char,int>m1,m2;
	    for(auto i : t) m2[i]++;
	    int i=0,j=0;
	    while(j<s.size()) {
	        m1[s[j++]]++;
	        while(i<j && m1[s[i]]>m2[s[i]]) m1[s[i++]]--;
	        bool flage=1;
	        for(char l='a';l<='z';l++) if(m1[l]<m2[l]) flage=0;
	        if(flage==1) for(char l='A';l<='Z';l++) if(m1[l]<m2[l]) flage=0;
	        if(flage==1 && (ans.empty()||(j-i)<ans.size())) ans=s.substr(i,j-i);
	    }
	    return ans;
    }
};