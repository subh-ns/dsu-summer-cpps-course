#include<stdio.h>
int main()
{
        int k,c1,r1,c2,r2,i,j;
        printf("Enter the no. of rows and columns in the 1st matrix\n");
        scanf("%d%d",&r1,&c1);
        int a[r1][c1];
        printf("Enter the no. of rows and columns in the 2nd matrix\n");
        scanf("%d%d",&r2,&c2);
        int b[r2][c2];
        int product[r1][c2];
        for(i=0;i<r1;i++)
        {}
        else
                printf("Matrix multiplication not possible\n");
}

                for(j=0;j<c2;j++)
                {
                        product[i][j]=0;
                }
        }
        if(c1==r2)
        {
                printf("Matrix multiplication is possible\n");
                printf("Enter the element of the first matrix\n");
                for(i=0;i<r1;i++)
{
                        for(j=0;j<c1;j++)
                        {
                                printf("Enter data in [%d] [%d] position: ",i,j);
                                scanf("%d",&a[i][j]);
                        }
                }
                printf("Enter the elements of the second matrix\n");
                for(i=0;i<r2;i++)
                {
                        for(j=0;j<c2;j++)
                        {
                                printf("Enter data in [%d] [%d] position: ",i,j);
                                scanf("%d",&b[i][j]);
                        }for(i=0;i<r1;i++)
                {
                        for(j=0;j<c2;j++)
                        {
                   }
        else
                printf("Matrix multiplication not possible\n");
}
             for(k=0;k<c1;k++)
                                {
                                        product[i][j]+=a[i][k]*b[k][j];
                                }
                        }
                }
                printf("Order of resultant matrix is %dx%d\n",r1,c2);
                printf("Resultant Matrix is\n");
                for(i=0;i<r1;i++)
                {
                        for(j=0;j<c2;j++)
                        {
                                printf("%d\t",product[i][j]);
                        }
                        printf("\n");
                }
        }
        else
                printf("Matrix multiplication not possible\n");
}
