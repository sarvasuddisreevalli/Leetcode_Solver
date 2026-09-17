class Solution {
public:
    int find_set(int v,vector<int>& parent) {
        if (v == parent[v]) return v;
        return parent[v]=find_set(parent[v],parent);
    }

    void union_sets(int a, int b,vector<int>& parent) {
        a = find_set(a,parent);
        b = find_set(b,parent);
        if (a != b) parent[b] = a;
        else cnt++;
    }

    int cnt=0;

    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<int>parent1(n+1),parent2(n+1);
        for(int i=0;i<=n;i++) {
            parent1[i]=i; 
            parent2[i]=i;
        }
        sort(edges.rbegin(),edges.rend());
        int idx=0;
        while(idx<edges.size() && edges[idx][0]==3) {
            union_sets(edges[idx][1],edges[idx][2],parent1);
            idx++;
        }
        parent2=parent1;
        while(idx<edges.size() && edges[idx][0]==2) {
            union_sets(edges[idx][1],edges[idx][2],parent2);
            idx++;
        }
        while(idx<edges.size()) {
            union_sets(edges[idx][1],edges[idx][2],parent1);
            idx++;
        }
        int x=find_set(1,parent1),y=find_set(1,parent2);
        for(int i=2;i<=n;i++) {
            if(find_set(i,parent1) != x) return -1;
            if(find_set(i,parent2) != y) return -1;
        }
        return cnt;
    }
};