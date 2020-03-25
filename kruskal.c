#include<stdio.h>
#include<time.h>
#define infinity 999
int i,j,k,a,b,u,v,n,ne=1;
double st,et,tt;
int min,mincost=0,cost[9][9],parent[9];
int find(int);
int uni(int,int);
void main()
{
	printf("Enter the number of vertices:\n");
	scanf("%d",&n);
	printf("Adjacency Matrix:\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&cost[i][j]);
			if(cost[i][j]==0)
				cost[i][j]=infinity;
		}
	}
	st=clock();
	printf("The edges of the minimum cost spanning tree are:\n");
	while(ne<n)
	{
		for(i=1,min=999;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(cost[i][j]<min)
				{
					min=cost[i][j];
					a=u=i;
					b=v=j;
				}
			}
		}
		u=find(u);
		v=find(v);
		if(uni(u,v))
		{
			printf("\n%d edge: (%d %d) = %d \n",ne++,a,b,min);
			mincost+=min;
		}
		cost[a][b]=cost[b][a]=infinity;
	}
	printf("Minimum cost = %d\n",mincost);
	et=clock();
	st=(double)(st)/CLOCKS_PER_SEC;
	et=(double)(et)/CLOCKS_PER_SEC;
	printf("st=%lf et=%lf,tt=%lf\n",st,et,et-st);
}
int find(int i)
{
	while(parent[i])
		i=parent[i];
	return i;
}
int uni(int i,int j)
{
	if(i!=j)
	{
		parent[j]=i;
		return 1;
	}
	else
		return 0;
}
