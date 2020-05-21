int main()
{
    int nums[] = {0, 1, 0}, numsSize = sizeof(nums) / 4;
    int border = numsSize;
    int flag = 0;
    while (!flag)
    {
        flag = 1;
        for (int i = border - 1; i >= 0; i--)
        {
            if (nums[i] == 0)
            {
                for (int j = i; j < border - 1; j++)
                    nums[j] = nums[j + 1];
                flag = 0;
                nums[--border] = 0;
                break;
            }
        }
    }

    return 0;
}