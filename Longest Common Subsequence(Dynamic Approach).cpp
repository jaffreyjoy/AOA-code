#include<stdio.h>
#include<string.h>

int len[50][50]={0};
char dir[50][50];
int sl,ssl;
char s[50],ss[50];
char s1[50],ss1[50];
char lcs[50];
//char s1[50],ss1[50];

int lcsf()
{
	int i,j,minx;
	for(i=1;i<=sl;i++)
	{
		for(j=1;j<=ssl;j++)
		{
			if(s[i-1]==ss[j-1])
			{
			//	printf("\ns[i-1=%d]=%c ss[j-1=%d]=%c\n",i-1,s[i-1],j-1,ss[j-1]);
				len[i][j]=len[i-1][j-1]+1;
				dir[i][j]='d';	
			}
			
			if(s[i-1]!=ss[j-1])
			{
				if(len[i-1][j]>=len[i][j-1])
				{
					len[i][j]=len[i-1][j];
					dir[i][j]='u';	
				}
				if(len[i-1][j]<len[i][j-1])
				{
					len[i][j]=len[i][j-1];
					dir[i][j]='l';	
				}	
			}
			
		}
	}
	return(len[sl][ssl]);
}

storelcs()
{
	int i=sl,j=ssl,ind=0;
	char x=dir[i][j];
	while(len[i][j]!=0)
	{
		if(x=='d')
		{
			lcs[ind++]=ss[j-1];
			i=i-1;
			j=j-1;
		}
		else if(x=='l')
		{
			j=j-1;
		}
		else if(x=='u')
		{
			i=i-1;
		}
		x=dir[i][j];
	}
}

print()
{
	int i,j;
	for(i=1;i<=sl;i++)
	{
		for(j=1;j<=ssl;j++)
		{
			printf("%d  ",len[i][j]);
		}
		printf("\n");
	}
}

printc()
{
	int i,j;
	for(i=1;i<=sl;i++)
	{
		for(j=1;j<=ssl;j++)
		{
			printf("%c  ",dir[i][j]);
		}
		printf("\n");
		}
}

int main()
{
	int l,i;
	printf("Enter Sequence 1\n");
	scanf("%s",s);
	printf("Enter Sequence 2\n");
	scanf("%s",ss);
	sl=strlen(s);
	ssl=strlen(ss);
	printf("\n%s  %d",s,sl);
	printf("\n\n%s  %d",ss,ssl);
	l=lcsf();
	storelcs();
	printf("\n\n");
	print();
	printf("\n\n");
	printc();
	printf("\nLength of Longest Commmon Subsequence is %d  ",l);
	printf("\nLongest Commmon Subsequence : ");
	for(i=l-1;i>=0;i--)
	{
		printf("%c",lcs[i]);
	}
}
