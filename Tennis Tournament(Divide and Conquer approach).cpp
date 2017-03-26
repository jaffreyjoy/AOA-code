#include<stdio.h>
#include<math.h>
int nx,ns;

tt(int m[100][100])
{
	int i,j,ar;
	int r,k;
	int ni,n;
	int bl,ur,br;
	for(ni=2;ni<=ns;ni++)
	{
		n=pow(2,ni);
		
		r=1;
		k=n/2+1,
		bl=n/2;
		ur=n/2-1;
		br=n/2;
		//printf("\nn=%d  k=%d\n",n,k);
		
		
		//bottom left
		for(i=bl;i<n;i++)
		{
			//printf("\nBottom left\n");
			for(j=0;j<n/2-1;j++)
			{
			//	printf("\n %d  %d  \n",i,j);
				m[i][j]=m[i-n/2][j]+n/2;
			}
		}
		
		//top right
		for(i=0;i<n/2;i++)
		{
			///printf("\ntop right\n");
			for(j=ur;j<n-1;j++)
			{
			//	printf("\n %d  %d  =  %d \n",i,j,k);
				m[i][j]=k++;
				if(k>n)
					k=n/2+1;
			}
			k++;
		}
		
		//bottom right
		for(j=n/2-1;j<n-1;j++)
		{
			
			if(j>(n/2)-1)
			{
				if(ar==1)
					r=n/2;
				else
					r=ar-1;
			}
			//printf("\nBottom right\n");
			for(i=n/2;i<n;i++)
			{
				//printf("\n %d  %d  \n",i,j);
				m[i][j]=r++;
				if(r>n/2)
					r=1;
			}
			ar=r;
		}

	}
	
}

print(int m[100][100])
{
	int i,j,k=0;
	char t[50]="PLAYER NO ||v";
	printf("\n\n    Tennis matrix:- \n\n\t");
	printf("D A Y  N O.   ----->\n\n\t    ");
	for(j=0;j<nx-1;j++)
	{
		if(j+1<=9)
		printf("%d   ",j+1);	
		else
		printf("%d  ",j+1);												//Day no. int print
	}
	printf("\n\t   ");
	for(j=0;j<nx-1;j++)
	{
		printf("----");														// border for day no.
	}
	printf("\n");
	for(i=0;i<nx;i++)
	{
		if(t[k]!='\0')
			printf("   %c    ",t[k++]);                             		// Player no. string print
		else
			printf("        ");
		if(i+1<=9)
		printf("%d | ",i+1);
		else
		printf("%d| ",i+1);													//Player no. int print
		for(j=0;j<nx-1;j++)
		{
			if(m[i][j]<=9)
			printf("%d   ",m[i][j]);    
			else
			printf("%d  ",m[i][j]);                                     //          Main  Printf
		}
		printf("\n");
	}
	for(i=k;i<50;i++)
	{
		if(t[k]!='\0')
			printf("   %c \n",t[k++]);
	}
}


int main()
{
	double ntemp;
	printf("\n-----------------------------------------------------------------------------------------------------------------------");
 	printf("\n_________________________________________Tennis Tournament Algorithm__________________________________________________\n");
 	printf("-----------------------------------------------------------------------------------------------------------------------\n\n");
	printf("Enter no. of players (Must be in the form 2^n (where n is a positive integer))\n>");
	labelinp:
	scanf("%d",&nx);
	ntemp=log(nx)/log(2);
	if( (ntemp-(int)ntemp)>0 || nx==0 || nx<0)
	{
		printf("No. of players entered is not a power of 2.Enter again\n>");
		goto labelinp;
	}
		

	
	int mat[100][100];
	
	ns=log(nx)/log(2);							// no of steps
	
	// Initialize matrix with primitive values
	mat[0][0]=2;				
	mat[1][0]=1;
	
	//calling tennis tournament function
	tt(mat);
	print(mat);
}

