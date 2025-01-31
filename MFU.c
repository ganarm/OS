#include<stdio.h>
#include<stdlib.h>
struct node
{
  int pno,freq;
}frames[20];
int n;
int page_found(int pno)
{
  int fno;
  for(fno=0;fno<n;fno++)
    if(frames[fno].pno==pno)
       return fno;
    return -1;
}

int get_free_frame()
{  int fno;
  for (fno=0; fno<=n; fno++)
    if (frames[fno].pno==-1)
        return(fno);
   return(-1);
}

int get_mfu_frame()
{
  int fno;
  int selfno=0;
  for (fno=1; fno<n; fno++)
    if(frames[fno].freq>frames[selfno].freq)
    selfno=fno;
  return selfno;
}
void main()
{
   int p_request[20],i;
   int size;
     printf("\nHow many frames:");  
     scanf("%d",&n);
     printf("\nEnter No. of Pages in Refernce String : ");
     scanf("%d",&size);
     printf("\n***Enter Refernce String***\n\n");
     for (i=0;i<size;i++)
     {   
         printf("[%d]==>",i);
         scanf("%d",&p_request[i]);
     }
   
   int page_falts=0,j,fno;
 
   for (i=0; i<n; i++)
   { frames[i].pno=-1;
     frames[i].freq=0;
   }

   printf("\nPageNo     Page Frames              Page Fault");
   printf("\n---------------------------------------------------");
   for(i=0;i<size;i++)
   {
     j=page_found(p_request[i]);
     if(j==-1) 
     {
       j=get_free_frame();
       if (j==-1)
         j=get_mfu_frame();
       page_falts++;
       frames[j].pno=p_request[i];
       frames[j].freq=1;
       printf("\n%4d\t ",p_request[i]);
       for (fno=0; fno<n; fno++)
         printf("%4d:%2d",frames[fno].pno,frames[fno].freq);
       printf(" : YES");
     }
    else 
    {
       printf("\n%4d\t ",p_request[i]);
       frames[j].freq++;
       for (fno=0; fno<n; fno++)
         printf("%4d:%2d",frames[fno].pno,frames[fno].freq);
       printf(" : NO");
    }
   }
  printf("\n-------------------------------------------------------");
  printf("\n Number of Page_Falts=%d",page_falts);
}
