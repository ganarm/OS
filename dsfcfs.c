#include<stdio.h>
#include<stdlib.h>

int main()
{
    int q[20],head,n,i,j,seek=0,max,diff;
    printf("\nEnter Max Range of Disk: ");
    scanf("%d",&max);
    printf("\nEnter size of queue request: ");
    scanf("%d",&n);
    printf("\nEnter queue disk position to be read: ");
    for (i=1;i<=n;i++)
       scanf("%d",&q[i]);
    printf("\nEnter Initial Head Position: ");
    scanf("%d",&head);
    q[0]=head;
    for (j=0;j<n;j++)
    {
        diff = abs(q[j+1]-q[j]);
        seek+=diff;
        printf("Disk head moves from %d to %d with seek %d.\n",q[j],q[j+1],diff);
    }   
    printf("Total Head Movement is %d. \n",seek);
    return 0;
}
