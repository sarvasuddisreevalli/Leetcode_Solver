class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans(1,vector<int>(1,1));
        while(ans.size()<numRows) {
            vector<int>t(1,1);
            for(int i=1;i<ans.back().size();i++) t.push_back(ans.back()[i-1]+ans.back()[i]);
            t.push_back(1);
            ans.push_back(t);
        }
        return ans;
    }
};