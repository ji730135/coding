class Solution
{
public:
    int numTrees(int n)
    {
        if (n == 1)
            return 1;
        double index = 2.0 * (2.0 * n - 1) / (n + 1.0);
        return (int)(index * numTrees(n - 1));
    }
};