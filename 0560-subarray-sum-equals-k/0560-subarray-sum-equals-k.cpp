class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        int sum=0;
        int cnt=0;
        m[0]=1;
        for(auto i : nums) {
            sum+=i;
            if(m[sum-k]>0) cnt+=m[sum-k];
            m[sum]++;
        }
        return cnt;
    }
};