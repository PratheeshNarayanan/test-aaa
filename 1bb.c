#include<stdio.h>

struct process
{
	int t;
	int bt,ft,at,tat,wt;
}p[5];
void main()
{int i,j,temp,n,ttat=0,twt=0;
 float atat=0,awt=0;
printf("enter number of process");
scanf("%d",&n);
for(i=1;i<=n;i++)
{	printf("\nenter name of %d process",i);
        scanf("%d",&p[i].t);
	printf("\nenter arrival time and burst time");
	scanf("%d%d",&p[i].at,&p[i].bt);
}
for(i=0;i<n-1;i++)
 for(j=i;j<n-i-1;j++)
  if(p[j].bt>p[j+1].bt)
  {
      temp=p[j].bt;
      p[j].bt=p[i+1].bt;
      p[j+1].bt=temp;
  }


p[1].ft=p[1].bt;
for(i=2;i<=n;i++)
{
	p[i].ft=(p[i-1].ft+p[i].bt);
 }
for(i=1;i<=n;i++)
{       
	p[i].tat=(p[i].ft-p[i].at);ttat+=p[i].tat;
	p[i].wt=(p[i].tat-p[i].bt);twt+=p[i].wt;
}
for(i=1;i<=n;i++)
{ 	printf("\n%d|%d|%d|%d|%d|%d|",p[i].t,p[i].at,p[i].bt,p[i].ft,p[i].tat,p[i].wt);
}
atat=ttat/n;
awt=twt/n;
printf("\naverage turn aroundtime=%f",atat);
printf("\naverage waiting time=%f",awt);
}
