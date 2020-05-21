int main()
{
    int nums[] = {0, 1, 0}, numsSize = sizeof(nums) / 4;
    int border = 0;
    for (int cur = 0; cur < numsSize; cur++)
    {
        if (nums[cur] != 0)
            nums[border++] = nums[cur];
    }
    for (int i = border; i < numsSize; i++)
        nums[i] = 0;
    return 0;
}