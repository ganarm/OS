#include<stdio.h>
#include<stdlib.h>
int main()
{
	int j,n,i,seek=0,max,head,move;
	printf("\n C-SCAN DISK SCHEDULING ALGORITHM:\n\n");
	printf("\n Enter Total Disk Size: ");
	scanf("%d",&max);
	printf("\n Enter the Number of Request: ");
	scanf("%d",&n);
	int q[n
	];
	printf("\n Enter the Request Sequence: ");
	for(i=0;i<n;i++)
		scanf("%d",&q[i]);
	printf("\n Enter Initial Head Position: ");
	scanf("%d",&head);
	printf("\n Enter the Head Movement direction (for high 1 and for low 0): ");
	scanf("%d",&move);
	
	for (i=0;i<n;i++)
	{
	    for (j=0;j<n-i-1;j++)
	    {
		if (q[j]>q[j+1])
		{
		   int temp;
		   temp=q[j];
		   q[j]=q[j+1];
		   q[j+1]=temp;
		}
	    }
	}
	
	int index;
	for (i=0;i<n;i++)
	{
	    if (head<q[i])
	    {
		index=i;
		break;
	    }
	}

	printf("\n Sequence of head movement:");
	if (move==1)
	{
	    printf(" %d ",head);
	    for (i=index;i<n;i++)
	    {
		seek+=abs(q[i]-head);
		head=q[i];
		printf(" %d ",q[i]);
	    }
	    seek+=abs(max-q[i-1]-1);
	    seek+=abs(max-1);
	    printf(" %d ",max-1);
	    head=0;
	    printf(" %d ",head);
	    for (i=0;i<index;i++)
	    {
		seek+=abs(q[i]-head);
		head=q[i];
		printf(" %d ",q[i]);
	    }
	}
	else
	{
	    printf(" %d ",head);
	    for (i=index-1;i>=0;i--)
	    {
		seek+=abs(q[i]-head);
		head=q[i];
		printf("%d\t",q[i]);
	    }
	    seek+=abs(q[i+1]-0);
	    seek+=abs(max-1-0);
	    head=max-1;
	    printf(" %d ",head);
	    for (i=n-1;i>=index;i--)
	    {
		seek+=abs(q[i]-head);
		head=q[i];
		printf(" %d ",q[i]);
	    }
	}
	printf("\n\n Total Head Movements are %d \n",seek);
	return 0;
}https://github.com/darshanpb07
