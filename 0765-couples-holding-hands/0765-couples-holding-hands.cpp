class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n=row.size();
        map<int,int>m;
        for(int i=0;i<n;i+=2) {
            m[row[i]]=row[i+1];
            m[row[i+1]]=row[i];
        }
        int cnt=0;
        for(int i=0;i<n;i+=2) {
            if(m[i]==i+1 && m[i+1]==i) continue;
            else {
                cnt++;
                int x=m[i];
                int y=m[i+1];
                m[x]=y;
                m[y]=x;            
            }
        }
        return cnt;
    }
};