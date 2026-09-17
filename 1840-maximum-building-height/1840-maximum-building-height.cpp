class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        sort(restrictions.begin(),restrictions.end());
        int m=restrictions.size();
        if(m==0) return n-1;
        // left -> right
        restrictions[0][1]=min(restrictions[0][1],restrictions[0][0]-1);
        for(int i=1;i<m;i++) {
            restrictions[i][1]=min(restrictions[i][1],restrictions[i][0]-1);
            int dif=restrictions[i][0]-restrictions[i-1][0];
            restrictions[i][1]=min(restrictions[i-1][1]+dif,restrictions[i][1]);
        }
        // for(auto i : restrictions) cout<<i[0]<<' '<<i[1]<<endl;
        // right -> left
        restrictions[m-1][1]=min(restrictions[m-1][1],restrictions[m-1][0]-1);
        for(int i=m-2;i>=0;i--) {
            restrictions[i][1]=min(restrictions[i][1],restrictions[i][0]-1);
            int dif=restrictions[i+1][0]-restrictions[i][0];
            restrictions[i][1]=min(restrictions[i+1][1]+dif,restrictions[i][1]);
        }
        for(auto i : restrictions) cout<<i[0]<<' '<<i[1]<<endl;
        int ht=restrictions[0][1];
        for(int i=1;i<m;i++) {
            if(restrictions[i-1][1]>restrictions[i][1]) {
                int d=restrictions[i-1][1]-restrictions[i][1];
                int left=restrictions[i-1][0];
                int right=restrictions[i][0]-d;
                int mid=(left+right)/2;
                int maxi=restrictions[i-1][1]+(mid-left);
                ht=max(ht,maxi);
            }
            else {
                int d=restrictions[i][1]-restrictions[i-1][1];
                int left=restrictions[i-1][0]+d;
                int right=restrictions[i][0];
                int mid=(left+right)/2;
                int maxi=restrictions[i][1]+(mid-left);
                ht=max(ht,maxi);
            }

        }
        ht=max((n-restrictions[m-1][0])+restrictions[m-1][1],ht);
        // for front part
        int d=restrictions[0][1];
        int left=1;
        int right=restrictions[0][0];
        int mid=(left+right)/2;
        int maxi=restrictions[0][1]+(mid-left);
        ht=max(ht,maxi);

        return ht;
    }
};