#include<stdio.h>
#include<math.h>
void main()
{
 int chp,sdl,mdl,n,i,a[10],thm=0,temp=0,j,pos,k,sum=0;
 float stym;
 printf("enter the current head position:");
 scanf("%d",&chp);
 printf("\nenter the seek time:");
 scanf("%f",&stym);
 printf("\nenter the starting disk limit:");
 scanf("%d",&sdl);
 printf("\nenter the maximum disk limit:");
 scanf("%d",&mdl);
 printf("\nenter the no. of request:");
 scanf("%d",&n);

 for(i=0;i<n;i++)
 {
	printf("enter the %d request",i);
	scanf("%d",&a[i]);
 }
 a[i]=chp;
 for(i=0;i<n+1;i++)
	{
		for(j=i+1;j<n+1;j++)
		{
			if(a[i]>a[j])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
for(i=0;i<n;i++)
{
	if((chp>a[i])&&(chp<a[i+1]))
	{
		pos=i;
	}
}
	printf("->%d",a[pos]);
	if((chp-a[0])< (a[n+1]-chp))
	{
		sum=chp-a[pos];
		for(k=pos;k>0;k--)
		{
			printf("->%d",a[k]);
			sum+=abs(a[k]-a[k-1]);
		}
	}
	else
	{
		
		sum+=(a[pos+1]-chp);
		for(k=pos+1;k<n;k++)
		{
			printf("->%d",a[k]);
			sum+=abs(a[k+1]-a[k]);
		}
	}		
		
		


 printf("disk movement:\n");

 for(i=0;i<n+1;i++)
 {
	printf("->%d",a[i]);
}

for(i=0;i<=n;i++)
{
	thm+=abs(a[i]-a[i+1]);
	
}
printf("\ntotal head movement=%d",thm);
printf("\naverage head movement=%d",thm/n);
printf("\ntotal seek tym=%f\n",thm*stym);

}
