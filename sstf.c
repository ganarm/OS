#include<stdio.h>
#include<stdlib.h>
int main()
{
	int q[100],i,n,seek=0,head,count=0;
	printf("\n Enter the Number of Request: ");
	scanf("%d",&n);
	printf("\n Enter the Request Sequence: ");
	for(i=0;i<n;i++)
		scanf("%d",&q[i]);
	printf("\n Enter Initial Head Position: ");
	scanf("%d",&head);
	printf("Sequence of Head Movement:\n");
	while (count!=n)
	{
		int min=1000,diff,index;
		for (i=0;i<n;i++)
		{
		    diff=abs(q[i]-head);
	            if  (min>=diff)
		    {
			min=diff;
			index=i;
		    }
		}
		seek+=min;
		head=q[index];
		printf("%d ",q[index]);
		q[index]=1000;
		count++;
	}
	printf("\nTotal head movement is: %d.\n",seek);
	return 0;
}

