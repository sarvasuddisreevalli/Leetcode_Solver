class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int>p(ratings.size(),1);
        vector<int>s(ratings.size(),1);
        for(int i=1;i<ratings.size();i++) if(ratings[i]>ratings[i-1]) p[i]=p[i-1]+1;
        for(int i=ratings.size()-2;i>=0;i--) if(ratings[i]>ratings[i+1]) s[i]=s[i+1]+1;
        int ans=0;
        for(int i=0;i<ratings.size();i++) ans+=max(p[i],s[i]);
        return ans;
    }
};