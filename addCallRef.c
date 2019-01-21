#include <stdio.h>
#include <stdlib.h>
void input(int *a,int *b)
{
    printf("Enter the first number\n");
    scanf("%d",&a);
    printf("Enter the second number\n");
    scanf("%d",&b);
}
void compute(int a,int b,int c){
    c=a+b;
}
void output(){
    int a,b,c;
    printf("%d+%d=%d",a,b,c);
}
void main(){
    input(&a,&b);
    
    
}
