#define max(a, b) ((a) > (b) ? (a) : (b))
int jump(int* nums, int numsSize) {
    if (numsSize <= 1){
        return 0;
    }
    int jump=0;
    int current_end=0;
    int far=0;
    for(int i=0;i< numsSize;i++)
    {
        far=max(far,i+nums[i]);
        if(i==current_end)
        {
            jump++;
            current_end=far;
             if (current_end >= numsSize - 1) {
                break;
        }
    }
    }
return jump;
}