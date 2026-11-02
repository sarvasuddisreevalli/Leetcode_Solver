class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int j=intervals[0][1],cnt=0;
        for(int i=1;i<intervals.size();i++) {
            if(intervals[i][0]<j) {
                cnt++;
                j=min(j,intervals[i][1]);
            }
            else j=intervals[i][1];
        }
        return cnt;
    }
};