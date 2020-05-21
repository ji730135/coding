int main()
{
    int nums[] = {0, 0};
    for (int i = 1; i > 0; i--)
    {
        while (i >= 0)
        {
            if (nums[i] != 0)
                i--;
            else
                break;
        }
        if (i < 0)
            break;
        int k = i;
        while (k >= 0)
        {
            if (nums[k] != 0)
                k--;
            else
                break;
        }
        if (k < 0)
            break;
        for (int j = k; j < i; j++)
            nums[j] = nums[j + 1];
        nums[i] = 0;
    }
    return 0;
}