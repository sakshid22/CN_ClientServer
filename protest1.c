#include<stdio.h>
#include<stdlib.h>

int m[10][10],s,d,n,ind,mval,sol,path[10],strength[10],associativity[10],path1[10],mval1,s1,a[10][10],sol1,ind1;

void maxx1(int j)
{
int temp=0,i;
mval1=0;
	for(i=0;i<n;i++)
	{
		if(temp<a[j][i])
		{
		temp=a[j][i];
		ind1=i;
		mval1=temp;
		}
	}
a[j][ind1]=0;
a[ind1][j]=0;
}

void maxx(int j)
{
int temp=0,i;
mval=0;
	for(i=0;i<n;i++)
	{
		if(temp<m[j][i])
		{
		temp=m[j][i];
		ind=i;
		mval=temp;
		}
	}
m[j][ind]=0;
m[ind][j]=0;
}

int abr(int src,int ans,int count,int curr)
{
//printf("for abr\n");
printf("%d  %d %d %d \n",src,ans,count,mval1);
if(src==d)
{
sol1=ans;
return 0;
}
maxx1(src);
if(count==n)
{
printf("No path available \n");
sol1=0;
return 0;
}

if(mval1==0)
abr(path1[curr-2],ans-associativity[curr-1],count+1,curr-1);
else
{
path1[curr]=ind1;
associativity[curr]=mval1;
abr(ind1,ans+mval1,0,curr+1);
}
}
int ssr(int src,int ans,int count,int curr)
{
printf("%d  %d %d %d \n",src,ans,count,mval);
if(src==d)
{
sol=ans;
return 0;
}
maxx(src);
if(count==n)
{
printf("No path available \n");
sol=0;
return 0;
}

if(mval==0)
ssr(path[curr-2],ans-strength[curr-1],count+1,curr-1);
else
{
path[curr]=ind;
strength[curr]=mval;
ssr(ind,ans+mval,0,curr+1);
}
}

int main()
{
int i,j,ch,n1,n2;
for(i=0;i<10;i++)
{
	for(j=0;j<10;j++)
	{
		m[i][j]=0;
		a[i][j]=0;
	}
}
printf("enter the number of nodes\n");
scanf("%d",&n);
printf("if value is less than 2,the signal is weak signal otherwise its a strong signal\n");
printf("enter the strength and associativity of the signal from node to node\n");
for(i=0;i<n;i++)
{
	for(j=0;j<n;j++)
	{
		if(i==j)
		{
			m[i][j]=0;
			a[i][j]=0;
			continue;
		}
		printf("from %d to %d\n",i,j);
		scanf("%d",&m[i][j]);
		scanf("%d",&a[i][j]);
	}
}
printf("enter the source and destination nodes\n");
scanf("%d",&s);
scanf("%d",&d);
path[0]=s;
path1[0]=s;
associativity[0]=0;
strength[0]=0;
printf("for ssr\n");
ssr(s,0,0,1);
printf("for abr\n");
abr(s,0,0,1);
printf("for SIGNAL STABILITY ROUTING node %d to node %d---value %d --\n",s,d,sol);
printf("for ssb path followed by :     ");
for(i=0;i<n-1;i++)
{
if(path[i]!=d)
printf("%d--->",path[i]);
else 
break;
}
printf("%d\n",path[i]);
printf(" for ASSOCIATIVITY BASED ROUTING node %d to node %d---value %d --\n",s,d,sol1);
printf("for abr path followed by :     ");
for(i=0;i<n-1;i++)
{
if(path1[i]!=d)
printf("%d--->",path1[i]);
else 
break;
}
printf("%d\n",path1[i]);
printf("is there any error between any link? type 0 for yes and 1 for no\n");
scanf("%d",&ch);
printf("enter the nodes between which link has failed\n");
scanf("%d%d",&n1,&n2);
m[n1][n2]=0;
m[n2][n1]=0;
a[n1][n2]=0;
a[n2][n1]=0;
sol=0;
sol1=0;
if(ch==0)
{
printf("for ssr\n");
ssr(s,0,0,1);
printf("for abr\n");
abr(s,0,0,1);
printf("for SIGNAL STABILITY ROUTING node %d to node %d---value %d --\n",s,d,sol);
printf("for ssb path followed by :     ");
for(i=0;i<n-1;i++)
{
if(path[i]!=d)
printf("%d--->",path[i]);
else 
break;
}
printf("%d\n",path[i]);
printf(" for ASSOCIATIVITY BASED ROUTING node %d to node %d---value %d --\n",s,d,sol1);
printf("for abr path followed by :     ");
for(i=0;i<n-1;i++)
{
if(path1[i]!=d)
printf("%d--->",path1[i]);
else 
break;
}
printf("%d\n",path[i]);
}
}
