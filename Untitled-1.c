int minSubArrayLen(int target, int* nums, int numsSize) {
    int st=0,end=0;
    int sum=0;
    int min_len=INT_MAX;
    while(end<numsSize)
    {
        sum+=nums[end];
        while(sum>=target)
        {
            int length=(end-st)+1;
            if(length<min_len)
            {
                min_len=length;
            }
            sum-=nums[st];
            st++;
        }
        end++;
    }
    return (min_len==INT_MAX) ? 0:min_len;
}