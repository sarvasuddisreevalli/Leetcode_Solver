class Solution {
public:
    bool canJump(vector<int>& nums) {
        int start=1;
        for(auto i : nums) {
            if(start<=0) return 0;
            start--;
            start=max(start,i);
        }
        return true;
    }
};