int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int totalSize = nums1Size + nums2Size;
    int* combined = (int*)malloc(totalSize * sizeof(int));
    for(int i=0;i<nums1Size;i++)
    {
        combined[i]=nums1[i];
    }
    int j=0;
    for(int i=nums1Size;i<totalSize;i++)
    {
        combined[i]=nums2[j];
        j++;
    }
    qsort(combined, totalSize, sizeof(int), compare);
   
        if(totalSize%2==0)
        {
            int n=totalSize/2;
            double s=combined[n]+combined[n-1];
            return s/2;
        }
        else if(totalSize%2==1)
        {
            return combined[totalSize/2];
        }
        
  
    free(combined);
    return 0;

}