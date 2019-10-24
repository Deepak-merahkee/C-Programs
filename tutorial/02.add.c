/* sum of two numbers */
#include <stdio.h>

int main()
{
    int a,b,sum;
    printf("Enter first number: ");
    scanf("%d",&a);
    printf("Enter second number: ");
    scanf("%d",&b);
    sum = a + b;
    printf("sum of %d and %d is: %d",a,b,sum);
    return 0;
}
