void reverse(int *nums,int start,int end)
{
    while(start < end)
    {
        int temp=nums[start];
        nums[start]=nums[end];
        nums[end]=temp;
        start++;
        end--;
    }
}
void rotate(int* nums, int numsSize, int k) {
    if(numsSize==0) return ;
    k=k % numsSize;
    if(k==0)
    {
        return ;
    }
    int someMid=numsSize-k;
    reverse(nums,0,someMid-1);
    reverse(nums,someMid,numsSize-1);
    reverse(nums,0,numsSize-1);
}
