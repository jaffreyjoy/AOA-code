#include<stdio.h>
//#include<conio.h>
int a[10];
int first,last,val,res=0;
int bs(int x[],int f,int l,int k)
{
	int m;
	while(f<=l)
	{
		m=(f+l)/2;
		if(x[m]<k)
		{
			printf("\n1)first=%d  last=%d  middle=%d\n",f,l,m);
			return(bs(x,m+1,l,k));
		}
		if(x[m]==k)
		{
			res=1;
			if(val==1)
			{
				printf("\n2)first=%d  last=%d  middle=%d\n",f,l,m);
				first=m;
				return(bs(x,f,m-1,k));
			}
			if(val==0)
			{
				printf("\n2)first=%d  last=%d  middle=%d\n",f,l,m);
				last=m;
				return(bs(x,m+1,l,k));
			}
		}
		if(x[m]>k)
		{
			printf("\n3)first=%d  last=%d  middle=%d\n",f,l,m);
			return(bs(x,f,m-1,k));
		}
	}

}

int main()
{
	int n,i,key;
	printf("Enter no. of elements\n");
	scanf("%d",&n);
	printf("Enter the elements\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("\nEnter element to be searched\n");
	scanf("%d",&key);

	printf("\nSTEPS:-\n");
	//for first
	val=1;
	bs(a,0,n-1,key);

	printf("\n-----------------------------------------\n",n);

	//for last
	val=0;
	bs(a,0,n-1,key);
	//

	if(res==0)
	{
		printf("Key not found\n");
	}
	else
	{
		printf("\nFirst occurance of key i.e %d is at position %d\n",key,first);
		printf("\nLast occurance of key i.e %d is at position %d\n",key,last);
		printf("\nKey has occured %d time(s)",last-first+1);
	}
//	getch();
}
