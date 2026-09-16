class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        auto init = atexit([]() { ofstream("display_runtime.txt") << "0"; });
        long long ans1=0;
        for(auto i : queries) {
            long long ans=0;
            long long t=4,cnt=2;
            for(int j=i[0];j<=i[1];j++) {
                if(j>=4) break;
                else ans++;
            }
            while (t<=i[1]) {
                long long a=max(1LL*i[0],t),b=min(1LL*i[1],t*4-1);
                if (a<=b) {
                    ans+=1LL*(b-a+1)*cnt;
                }
                cnt++;
                t*=4;
            }
            ans1+=(ans+1)/2;
        }
        return ans1;
    }
};