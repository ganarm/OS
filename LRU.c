//LRU : 
#include<stdio.h>
 int m=0,n=0,ref[20]={0},sp=0,frames[10]={0},mem[20][20]={0},arr[20],fa=0,time[20];
 int search(int p)
 {
     int i;
     for (i=0;i<n;i++)
         if (frames[i]==p)
             return(i);
     return(-1); 
 
 }
 int get_LRU()
 {
     int i,min_i,min=999;
     for (i=0;i<n;i++)
         if (time[i]<min)
         {
            min=time[i];
            min_i=i;
         } 
     return(min_i);
 }
 
 void LRU()
 {
      int i,j,k;
      for (i=0;i<m && sp<n;i++)
      {
          k=search(ref[i]);
          if (k==-1)
          {
             arr[i]=1;
             frames[sp]=ref[i];
             time[sp]=i;
             sp++;
             fa++;
             for (j=0;j<n;j++)
             {
                 mem[j][i]=frames[j];
             }
          }
          else
          {
             time[k]=i;
             for (j=0;j<n;j++)
             {
                 mem[j][i]=frames[j];
             }
          }
      }
      
      for (;i<m;i++)
      {
          k=search(ref[i]);
          if (k==-1)
          {
             arr[i]=1;
             sp=get_LRU();
             frames[sp]=ref[i];
             time[sp]=i;
             fa++;
             for (j=0;j<n;j++)
                 mem[j][i]=frames[j];
             
          }
          else
          {
             time[k]=i;
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
     for (j=0;j<m;j++)
         printf("%4d",ref[j]);
     printf("\n");
     for (j=0;j<m;j++)
         printf("----");
      printf("\n");
     for (i=0;i<n;i++)
     {
         for (j=0;j<m;j++)
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
     for (j=0;j<m;j++)
         printf("----");
      printf("\n");
     for (j=0;j<m;j++)
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
     scanf("%d",&n);
     printf("\nEnter No. of Pages in Refernce String : ");
     scanf("%d",&m);
     printf("\n***Enter Refernce String***\n\n");
     for (i=0;i<m;i++)
     {   
         printf("[%d]==>",i);
         scanf("%d",&ref[i]);
     }
     LRU();
     display();
}
