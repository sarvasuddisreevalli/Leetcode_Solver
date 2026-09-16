class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int cnt=0;
        queue<int>q;
        for(int i=0;i<nums.size();i++) {
            while(!q.empty() && q.front()+k<=i) q.pop();
            int flips=q.size()%2;
            if(flips==1) nums[i]=1-nums[i];
            if(nums[i]==0) {
                q.push(i);
                cnt++;
            }
        }
        while(!q.empty()) {
            if(q.front()+k<=nums.size()) q.pop();
            else return -1;
        }
        return cnt;
    }
};