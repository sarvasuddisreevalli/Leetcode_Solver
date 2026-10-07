class Solution {
public:
    vector<long long>a;

    Solution(vector<int>& w) {
        long long sum=0;
        for(int i=0;i<w.size();i++) {
            sum+=w[i];
            a.push_back(sum);
        }
    }
    
    int pickIndex() {
        int p= rand()%a.back()+1;
        return lower_bound(a.begin(),a.end(),p)-a.begin();
    }
};