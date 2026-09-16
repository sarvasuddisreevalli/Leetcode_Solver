double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    float C[nums1Size+nums2Size];
	int i=0,j=0,x=0;
	while(i<nums1Size && j<nums2Size){
		if(nums1[i]<nums2[j]) C[x++]=nums1[i++];
		else C[x++]=nums2[j++];
	}
	for(int k=j;k<nums2Size;k++) C[x++]=nums2[k];
	for(int k=i;k<nums1Size;k++) C[x++]=nums1[k];
    float ans;
    if((nums1Size+nums2Size)&1) return ans=C[(nums1Size+nums2Size)/2];
    else return ans=(C[(nums1Size+nums2Size)/2]+C[(nums1Size+nums2Size-1)/2])/2;
}