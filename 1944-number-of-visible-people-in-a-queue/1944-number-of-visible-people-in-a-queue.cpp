class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        vector<int>ans(heights.size());
        stack<int>s;
        s.push(heights[heights.size()-1]);
        for(int i=heights.size()-2;i>=0;i--){
            int cnt=0;
            while(!s.empty()){
                if(s.top()>heights[i]){
                    cnt++;
                    break;
                }
                else{
                    s.pop();
                    cnt++;
                }
            }
            s.push(heights[i]);
            ans[i]=cnt;
        }
        return ans;
    }
};