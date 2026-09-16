class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int>a;
        for(auto i : arr) a.push_back(i);
        sort(arr.begin(),arr.end());
        int cnt=0;
        map<int,int>m1,m2;
        for(int i=0;i<a.size();i++) {
            m1[a[i]]++;
            m2[arr[i]]++;
            if(m1==m2) {
                cnt++;
                m1.clear();
                m2.clear();
            }
        }
        return cnt;
    }
};