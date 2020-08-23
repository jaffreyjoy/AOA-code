#include<stdio.h>
int np,nq;

int w[100][100],c[100][100],r[100][100];

int sendk(int i1,int j1,int karr1[])
{
	int kt,x,min,minindex,temp;
	int ct[nq];
	for(x=0;x<nq;x++)
	{
		kt=karr1[x];
		ct[x]=-10;
	}
	for(x=0,temp=j1;x<nq,temp>i1;x++,temp--)
	{
		kt=karr1[x];
		ct[x]=c[i1][kt-1]+c[kt][j1]+w[i1][j1];
	//	printf("\nct[x]=%d c[i1][kt-1]=%d c[kt][j1]=%d w[i1][j1]=%d\n",ct[x],c[i1][kt-1],c[kt][j1],w[i1][j1]);
	}
	//printf("\nhere\n");
	min=ct[0];
	minindex=0;
	for(x=0;x<nq;x++)
	{
		if(ct[x]!=-10)
		{
			if(ct[x]<min)
			{
				min=ct[x];
				minindex=x;
			}	
		}
	//	printf("\nminhere nq=%d  minindex=%d\n",nq,minindex);
	}
	//printf("\nk =   %d\n",karr1[minindex]);
	return(karr1[minindex]);
}

print(int a[100][100])
{
	int i,j;
	for(i=0;i<nq;i++)
	{
		printf("\t");
		for(j=0;j<nq;j++)
		{
			if(i==j || j-i>=1)
			{
				if(a[i][j]>9)
					printf("%d ",a[i][j]);
				else
					printf("%d  ",a[i][j]);
			}
				
			else
				printf("   ");
		}
		printf("\n");
	}
}

int main()
{
	int i,j;
	int p[nq],q[nq];
	
	printf("\n-----------------------------------------------------------------------------------------------------------------------");
 	printf("\n__________________________________________Optimal Binary Search Tree__________________________________________________\n");
 	printf("-----------------------------------------------------------------------------------------------------------------------\n\n");
 	
	printf("   Enter the no. elements  :  ");
	scanf("%d",&np);
	printf("\n   Successful  Probabilities  :-\n");
	for(i=1;i<=np;i++)
	{
		printf("\tEnter successful probability p[%d] : ",i);
		scanf("%d",&p[i]);
	}
	nq=np+1;
	printf("\n   Unsuccessful  Probabilities  :-\n");
	for(i=0;i<nq;i++)
	{
		printf("\tEnter unsuccessful probability q[%d] : ",i);
		scanf("%d",&q[i]);
	}
	
//	for(i=0;i<nq;i++)
//	{
//		for(j=0;j<nq;j++)
//		{
//			w[i][j]=-10;
//		}
//	}
//	
//	for(i=0;i<nq;i++)
//	{
//		for(j=0;j<nq;j++)
//		{
//			c[i][j]=-10;
//		}
//	}
//	
//	for(i=0;i<nq;i++)
//	{
//		for(j=0;j<nq;j++)
//		{
//			r[i][j]=-10;
//		}
//	}
//	
//	
//	for(i=0;i<nq;i++)
//	{
//		for(j=0;j<nq;j++)
//		{
//			if(i==j)
//				w[i][j]=q[i];
//			if(j-i==1)
//			{
//				w[i][j]=q[i]+q[i+1]+p[i+1];
//			//	printf("\nw[i][j]=%d  q[i]=%d q[i+1]=%d p[i+1]=%d\n",w[i][j],q[i],q[i+1],p[i+1]);
//			}
//				
//		}
//	}
//	
////	print(w);
//	
//	for(i=0;i<nq;i++)
//	{
//		for(j=0;j<nq;j++)
//		{
//			if(j-i>1)
//			{
//				w[i][j]=w[i][j-1]+q[j]+p[j];
//			//	printf("\nw[i][j]=%d  w[i][j-1]=%d q[j]=%d p[j]=%d\n",w[i][j],w[i][j-1],q[j],p[j]);
//			}
//				
//		}
//	}

	
////  W   MATRIX

	int karr[nq];
	int m,n,x,l,kid;
	
	int itemp,jtemp,xtemp;
	
	itemp=0;
	jtemp=0;
	
	xtemp=nq;
	for(l=0;l<nq;l++)
	{
		i=itemp;
		j=jtemp;
		for(x=xtemp;x>0;x--)
		{
			if(i==j)
			{
				w[i][j]=q[i];
			}
				
			if(j-i==1)
			{
				w[i][j]=q[i]+q[i+1]+p[i+1];
			//	printf("\nw[i][j]=%d  q[i]=%d q[i+1]=%d p[i+1]=%d\n",w[i][j],q[i],q[i+1],p[i+1]);
			}
			if(j-i>1)
			{
				w[i][j]=w[i][j-1]+q[j]+p[j];
			//	printf("\nw[i][j]=%d  w[i][j-1]=%d q[j]=%d p[j]=%d\n",w[i][j],w[i][j-1],q[j],p[j]);
			}
			i++;
			j++;	
		}
		xtemp--;
		jtemp++;
	}
	
	
	printf("\n\n   W Matrix  :-\n\n");
	print(w);
	
//	for(i=0;i<nq;i++)
//	{
//		for(j=0;j<nq;j++)
//		{
//			if(i==j)
//			{
//				c[i][j]=0;
//				r[i][j]=0;
//			}
//				
//			if(j-i==1)
//			{
//				c[i][j]=q[i]+q[i+1]+p[i+1];
//				r[i][j]=j;
//			//	printf("\nw[i][j]=%d  q[i]=%d q[i+1]=%d p[i+1]=%d\n",w[i][j],q[i],q[i+1],p[i+1]);
//			}
//				
//		}
//	}
	
//	print(c);
//	printf("\n\n");
//	print(r);
	
//	printf("\nHere\n");





//// COST AND  ROOT  MATRIX  
	
	itemp=0;
	jtemp=0;
	
	xtemp=nq;
	for(l=0;l<nq;l++)
	{
		i=itemp;
		j=jtemp;
		for(x=xtemp;x>0;x--)
		{
			if(i==j)
			{
				c[i][j]=0;
				r[i][j]=0;
			}
				
			if(j-i==1)
			{
				c[i][j]=q[i]+q[i+1]+p[i+1];
				r[i][j]=j;
			//	printf("\nw[i][j]=%d  q[i]=%d q[i+1]=%d p[i+1]=%d\n",w[i][j],q[i],q[i+1],p[i+1]);
			}
			if(j-i>1)
			{
				for(m=j,n=0;m>i;m--,n++)
				{
					karr[n]=m;
				}
				kid=sendk(i,j,karr);
				c[i][j]=c[i][kid-1]+c[kid][j]+w[i][j];
				r[i][j]=kid;
			//	printf("\nw[i][j]=%d  w[i][j-1]=%d q[j]=%d p[j]=%d\n",w[i][j],w[i][j-1],q[j],p[j]);
			}
			i++;
			j++;	
		}
		xtemp--;
		jtemp++;
	}
	
	printf("\n\n   Cost  matrix:-\n\n");
	print(c);
	printf("\n\n   Root  matrix:-\n\n");
	print(r);
	
	
}
