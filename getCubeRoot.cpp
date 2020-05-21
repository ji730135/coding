#include <stdio.h>
#define step 0.1

int main()
{
    double input, output = 1.0;
    scanf("%lf", &input);
    do
    {
        output = output - (output * output * output - input) / (3 * output * output);
    } while ((output * output * output - input) > 1e-6);
    printf("%.1lf\n", output);
}