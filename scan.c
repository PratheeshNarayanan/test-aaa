#include<stdio.h>
#include<math.h>
void main()
{
	int que1[10],que2[10],i,n,temp,ehp;
	int chp,mdisk,sdisk,edisk,low,high,j,diff=0,dif=0;
	float seek,avg,tseek;
	printf("Enter the number of heads");
	scanf("%d",&n);
	printf("Enter the seek time ");
	scanf("%f",&seek);
	printf("Enter the current head position ");
	scanf("%d",&chp);
	printf("Enter the end head position ");
	scanf("%d",&ehp);
	printf("Enter the %d heads",n);
	que1[0]=0;
	que1[n+1]=ehp;
	for(i=1;i<n+1;i++)
	{
		scanf("%d",&que1[i]);
	}
	          
	
        for(i=0;i<n;i++)
            {
                        for(j=0;j<n-i;j++)
                        {
                                    if(que1[j]>que1[j+1])
                                    {
                                                temp=que1[j+1];
                                                que1[j+1]=que1[j];
                                                que1[j]=temp;
                                    }
                        }
            }
            
           
	for(i=0;i<n+1;i++)
	{
		if( (chp>que1[i]) && (chp<que1[i+1]))
		{
		
			low=i;high=i+1; 
		}
	
	}
	
	
	for(i=0;i<=n+1;i++)
		{
			printf("%d\t",que1[i]);	
		}
		
	printf("\n***********HEAD MOVEMENT**************");
	printf("\n%d ->",chp);
	
	if((chp-que1[0])<=(que1[n+1]-chp))
	{
		diff=abs(chp-que1[low]);
		for(i=low;i>0;i--)
		{
			printf("%d ->",que1[i]);		
			diff=diff+(abs(que1[i]-que1[i-1])); //printf("%d-%d=%d,",que1[i],que1[i-1],diff);
		}
		
		diff+=abs(0-que1[high]);
		
		for(i=low+1;i<n+1;i++)
		{	
			printf("%d ->",que1[i]);		
			diff=diff+(abs(que1[i]-que1[i+1]));//printf("%d-%d=%d,",que1[i],que1[i-1],diff);
		}
		
			printf("\n");
	}
	else if((chp-que1[0])>=(que1[n+1]-chp))
	{
		diff=abs(chp-que1[high]);
		for(i=high;i<n+1;i++)
		{	
			//printf("%d ->",que1[i]);	
			diff=diff+(abs(que1[i]-que1[i+1]));
		}
		diff+=abs(que1[n+1]-que1[low]);
		for(i=low;i>0;i--)
		{
			//printf("%d ->",que1[i]);			
			diff=diff+(abs(que1[i]-que1[i-1]));
		}
		//diff+=que1[i];
		
	}
	

	
printf("\ntotal head movements= %d",diff );
avg=diff/n;
printf("average head movement= %f",avg);
tseek=seek*diff;
printf("\ntotal seek= %f",tseek );}
