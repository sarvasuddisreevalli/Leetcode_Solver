class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char,int>m1;
        for(auto i : s) m1[i]++;
        map<char,int>m2;
        vector<int>ans;
        int c=1;
        for(auto i : s){
            m2[i]++;
            int flag=0;
            for(auto j : m2){
                if(j.second>0 && j.second!=m1[j.first]){
                    flag=1;
                    break;
                }
            }
            if(flag==0) {
                ans.push_back(c);
                c=0;
            }
            c++;
        }
        return ans;
    }
};