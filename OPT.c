//OPT : 
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
 int get_OPT()
 {
     int i,count=0,max,j;
     for (i=sp+1;i<m;i++)
     {
         max=-1;
         if(ref[i]==search(ref[i]) && count<n)
         {
           max=i;
           count++;
           printf("%d",max);
           printf("%d",count);
         }
     }
     for (i=0;i<n;i++)
         if(max==frames[i])
         {
           max=i;
           printf("%d",max);
         }
     return(max);
     
 }
 
 void OPT()
 {
      int i,j,k,p;
      sp=0;
      for (i=0;i<m && sp<n;i++)
      {
          k=search(ref[i]);
          if (k==-1)
          {

             frames[sp]=ref[i];
             sp++;
             fa++;
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
             printf("%d",sp);
             p=get_OPT();
             frames[p]=ref[i];
             fa++;
             for (j=0;j<n;j++)
                 mem[j][i]=frames[j];
             sp++;
             
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
     OPT();
     display();
}
