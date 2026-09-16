class Solution {
public:
    void Merge(vector<int>&A,int start,int end,int mid) {
	    int i=start,j=mid+1;
	    vector<int>B(end-start+1);
        while(i<=mid && j<=end) {
            if( (A[i]>1LL*2*A[j]) ) {
                cnt+=mid-i+1;
                j++;
            }
            else i++;
	    }
        int k=0;
        i=start,j=mid+1;
	    while(i<=mid && j<=end) {
		    if(A[i]<A[j]){
			    B[k++]=A[i++];
		    }
		    else B[k++]=A[j++];
	    }
	    while(i<=mid) B[k++]=A[i++];
	    while(j<=end) B[k++]=A[j++];
	    k=0;
	    for(int i=start;i<=end;i++){
		    A[i]=B[k++];
	    }
    }

    void MergeSortTechn(vector<int>& A,int start,int end) {
        if(start>=end) return;
        int mid=(start+end)/2;
        MergeSortTechn(A,start,mid);
        MergeSortTechn(A,mid+1,end);
        Merge(A,start,end,mid);
    }
    int cnt=0;
    int reversePairs(vector<int>& nums) {
        MergeSortTechn(nums,0,nums.size()-1);
        for(auto i : nums) cout<<i<<' ';
        return cnt;
    }
};