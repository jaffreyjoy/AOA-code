#include<stdio.h>
int p[10],p1[10],w[10],t[10],w1[10];
double pw[10],pw1[10];
int c,n;

isgreater(double p1,int x)
{
	int i,j=0;
	for(i=0;i<n;i++)
	{
		if(p1>pw[i])
			j++;
		if(p1==pw[i] && i!=x)
		{
			if(p[x]>p[i])
				j++;
		}
	}
	return(j);
}

int main()
{
	int i,j;
	printf("\n-----------------------------------------------------------------------------------------------------------------------");
 	printf("\n____________________________________________ Knapsack ______________________________________________________________\n");
 	printf("-----------------------------------------------------------------------------------------------------------------------\n");
	printf("\nEnter no. of elements :  ");
	scanf("%d",&n);
	
	printf("\nPROFIT INPUTS:-\n");
	
	for(i=0;i<n;i++)
	{
		printf("Enter profit for element [%d] : ",i+1);
		scanf("%d",&p[i]);
	}
	
	printf("\nWEIGHT INPUTS:-\n");
	
	for(i=0;i<n;i++)
	{
		printf("Enter weight of element [%d] : ",i+1);
		scanf("%d",&w[i]);
	}
	
	printf("\n\nEnter the capacity : ");
	scanf("%d",&c);
	
	for(i=0;i<n;i++)
	{
		pw[i]=(double)p[i]/w[i];
	}
	printf("\n\nObject\tProfit\tWeight\tPi/Wi");
	for(i=0;i<n;i++)
	{
		printf("\n%d\t%d\t%d\t%lf",i+1,p[i],w[i],pw[i]);
	}
	
	//printf("\n--------\n");
	
	for(i=0;i<n;i++)
	{
		t[i]=isgreater(pw[i],i);
	//	printf("\n%d\n",t[i]);
	}
	
	int t1[10];
	
	for(i=0;i<n;i++)
	{
		pw1[t[i]]=pw[i];
		p1[t[i]]=p[i];
		w1[t[i]]=w[i];
		t1[t[i]]=i;
	}
	
//	printf("\n--------\n");
	
	for(i=0;i<n;i++)
	{
	//	printf("\n%d\n",t1[i]);
	}
	
	printf("\n\nAfter Arranging:-");
	printf("\nObject\tProfit\tWeight\tPi/Wi");
	for(i=n-1;i>=0;i--)
	{
		printf("\n%d\t%d\t%d\t%lf",t1[i]+1,p1[i],w1[i],pw1[i]);
	}
	
	double mp=0;
	
	printf("\n\nObject\tCapacity remaining\tTotal profit\nadded");
	for(i=n-1;i>=0;i--)
	{
		if(w1[i]<=c)
		{
			mp=mp+p1[i];
			c=c-w1[i];
		}
		else 
		{
			mp=mp+pw1[i]*c;
			c=0;
		}
		printf("\n%d\t%d\t\t\t%lf",t1[i]+1,c,mp);
		if(c==0)
			break;
	}
	
	printf("\n\nMaximum profit = %lf",mp);
}
