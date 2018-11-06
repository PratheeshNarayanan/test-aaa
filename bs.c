#include<stdio.h>
void main()
{
int a[100][100],m[100][100],n[100][100];
int v[100],ava[100],ss[100];
int wc=0,i,j,x,y,l=0,c=0,g,p,o;
printf("enter the number of processes : ");
scanf("%d",&x);
printf("enter the number of available : ");
scanf("%d",&y);
printf("enter the allocation values : ");
printf("\n");
for(i=0;i<x;i++)
{
	for(j=0;j<y;j++)
	{
	printf("enter %dth allocation value of  p%d ",j+1,i+1);
	scanf("%d",&a[i][j]);
	}
printf("\n");
}
printf("Maximum:\n\n");
for(i=0;i<x;i++)
{
	for(j=0;j<y;j++)
	{
	printf("enter %dth max metrix value of  p%d ",j+1,i+1);
	scanf("%d",&m[i][j]);
	}
printf("\n");
}
printf("allocation metrix is :");
printf("\n");
for(i=0;i<x;i++)
{
	for(j=0;j<y;j++)
	{
	printf("%d\t",a[i][j]);
	}
printf("\n");
}
printf("maximum metrix is :");
printf("\n");
for(i=0;i<x;i++)
{
	for(j=0;j<y;j++)
	{
	printf("%d\t",m[i][j]);
	}
printf("\n");
}
for(i=0;i<x;i++)
{
	for(j=0;j<y;j++)
	{
	n[i][j]=m[i][j]-a[i][j];
	}
}
printf("needed metrix is :");
printf("\n");
for(i=0;i<x;i++)
{
	for(j=0;j<y;j++)
	{
	printf("%d\t",n[i][j]);
	}
printf("\n");
}
printf("enter the available resource list : ");
for(j=0;j<y;j++)
{
scanf("%d",&ava[j]);
}
for(i=0;i<x;i++)
{
v[i]=0;
}
g=0;
while(v[l]!=1)
{
for(i=0;i<x;i++)
{
c=0;
	for(j=0;j<y;j++)
	{
	  if((n[i][j])<=(ava[j]))
	   {
	   c++;
	   }
	}
	if(c==3)
	{
	v[i]=1;
	ss[g]=i;
	g++;
	for(p=0;p<x;p++)
		{
		for(o=0;o<y;o++)
			{
			ava[p]=ava[p]+a[p][o];
			}
		}
	}
}
l++;
}
for(j=0;j<x;j++)
	{
	printf("p%d\t",ss[j]);
	}
	   
}
