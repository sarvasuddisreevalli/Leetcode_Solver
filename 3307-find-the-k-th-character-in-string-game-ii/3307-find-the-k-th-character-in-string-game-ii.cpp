class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        long long x=1;
        long long idx=0;
        while(x<k) {
            x<<=1;
            idx++;
        }
        idx--;
        long long h=x,l=0,s=0;
        while(idx>=0){
            long long mid=h>>1;
            if(k>mid) {
                if(operations[idx]==1) s++;
                k-=mid;
            }
            h=mid;
            idx--;
        }
        return 'a'+(s%26);
    }
};