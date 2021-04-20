#include<stdio.h>
#include<math.h>
void main()
{
    float a,b;
    scanf("%f",&a);
    b = (7.8-sin(a))/(exp(a)+0.3); 
    printf("%0.3f",b);
}