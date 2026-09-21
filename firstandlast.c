/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int* arr = (int*)malloc(sizeof(int) * 2);
    arr[0] = -1;
    arr[1] = -1;

    if (numsSize == 0) {
        return arr;
    }

    int l = 0, r = numsSize - 1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (nums[m] == target) {
            arr[0] = m;
            r = m - 1; 
        } else if (nums[m] < target) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    l = 0; 
    r = numsSize - 1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (nums[m] == target) {
            arr[1] = m;
            l = m + 1; 
        } else if (nums[m] < target) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }

    return arr;
}
