// FIFO:
#include<stdio.h>
 int f=0,n=0,ref[20]={0},sp=0,frames[10]={0},mem[20][20]={0},arr[20],fa=0;
 int search(int p)
 {
     int i;
     for (i=0;i<f;i++)
         if (frames[i]==p)
             return(i);
     return(-1); 
 
 }
 void fifo()
 {
      int i,j;
      for (i=0;i<n;i++)
      {
          if (search(ref[i])==-1)
          {
             arr[i]=1;
             frames[sp]=ref[i];
             sp=(sp+1)%f;
             fa++;
             for (j=0;j<n;j++)
             {
                 mem[j][i]=frames[j];
             }
          }
          else
          {
             for (j=0;j<n;j++)
             {
                 mem[j][i]=frames[j];
             }
          }
      
      }
 }

 void display()
 {
     printf("\n\n\n");
     int i=0,j=0;
     for (j=0;j<n;j++)
         printf("%4d",ref[j]);
     printf("\n");
     for (j=0;j<n;j++)
         printf("----");
      printf("\n");
     for (i=0;i<f;i++)
     {
         for (j=0;j<n;j++)
         {
             if (mem[i][j]==-1)
             {
                 printf("    ");
             } 
             else
             {
                printf("%4d",mem[i][j]);
             } 
         }
         printf("\n");
     }
     for (j=0;j<n;j++)
         printf("----");
      printf("\n");
     for (j=0;j<n;j++)
         if (arr[j]==-1)
            printf("%4s","H");
         else
            printf("%4s","M");
     printf("\n\n\n\n\nTotal No. of Page Faults : %d",fa);
     printf("\n\n\n");
 }

 void main()
{
     int i,j;
     for (i=0;i<20;i++)
     {
         frames[i]=-1;
         arr[i]=-1;
         for (j=0;j<20;j++)
             mem[i][j]=-1;
     }
     printf("\nEnter No. of Frames : ");
     scanf("%d",&f);
     printf("\nEnter No. of Pages in Refernce String : ");
     scanf("%d",&n);
     printf("\n***Enter Refernce String***\n\n");
     for (i=0;i<n;i++)
     {   
         printf("[%d]==>",i);
         scanf("%d",&ref[i]);
     }
     fifo();
     display();
}
