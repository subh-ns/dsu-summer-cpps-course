#include<stdio.h>
#include<time.h>
int input()
{
        int num;
        scanf("%d",&num);
        return num;
}
int fact(int n)
{
        while(n>0)
                return (n*(fact(n-1)));
}

int npr(int n,int r)
{
        int res;
        if(n>r&&n>0&&r>0)
        {
                res=fact(n)/fact(n-r);
                return res;
        }
        else
                return -1;
}
int ncr(int n,int r)
{
        int res;
        if(n>r&&n>0&&r>0)
        {
                res=(fact(n)/(fact(r)*fact(n-r)));
                return res;
        }
        else
                return -1;
}
void display(int n,int r)
{
        printf("npr=%d",npr(n,r));
        printf("ncr=%d",ncr(n,r));
}
int main()
{
        int n,r;
        n=input();
        r=input();
        clock_t t;
        double time_taken;
        if(npr(n,r)==-1||ncr(n,r)==-1)
                printf("Invalid inputs\n");
        else
        {
                t=clock();
                display(n,r);
                t=clock()-t;
                time_taken=((double)t)/CLOCKS_PER_SEC;
                printf("The display function takes %lf seconds\n",time_taken);
        }
}
