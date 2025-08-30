#include<stdio.h>
#define N 10 // Max processes
#define M 3 // Number of resource types fixed as A,B,C
int n; // Number of processes
int total[M] = {7, 2, 6}; // Total resources: A=7, B=2, C=6
int alloc[N][M], max[N][M], need[N][M], avail[M];
void accept()
{
 printf("Enter number of processes: ");
 scanf("%d", &n);
 printf("Enter Allocation matrix (process wise):\n");
for(int i=0; i<n; i++)
 {
 printf("P%d:\n",i);
 for(int j=0; j<M; j++)
 {
 printf("%c: ",65+j);
 scanf("%d",&alloc[i][j]);
 }
 }
 printf("Enter Max matrix (process wise):\n");
 for(int i=0; i<n; i++)
 {
 printf("P%d:\n",i);
 for(int j=0; j<M; j++)
 {
 printf("%c: ",65+j);
 scanf("%d",&max[i][j]);
 }
 }
}
void calc_need()
{
 for(int i=0; i<n; i++)
 for(int j=0; j<M; j++)
need[i][j] = max[i][j] - alloc[i][j];
}
void calc_avail()
{
 int sum[M] = {0};
 for(int j=0; j<M; j++)
 {
 for(int i=0; i<n; i++)
 sum[j] += alloc[i][j];
 avail[j] = total[j] - sum[j];
 }
}
void display_alloc_max()
{
 printf("\nProcess\t Allocation\t Max\n\t");
 for(int j=0; j<M; j++)
 printf("%c ",65+j);
 printf("\t");
 for(int j=0; j<M; j++)
 printf("%c ",65+j);
 printf("\n");
for(int i=0; i<n; i++)
 {
 printf("P%d\t",i);
 for(int j=0; j<M; j++)
 printf("%d ",alloc[i][j]);
 printf("\t");
 for(int j=0; j<M; j++)
 printf("%d ",max[i][j]);
 printf("\n");
 }
}
void display_need()
{
 printf("\nNeed matrix:\nProcess\t");
 for(int j=0; j<M; j++)
 printf("%c ",65+j);
 printf("\n");
 for(int i=0; i<n; i++)
 {
 printf("P%d\t",i);
 for(int j=0; j<M; j++)
 printf("%d ",need[i][j]);
 printf("\n");
 }
}
void display_avail()
{
 printf("\nAvailable resources:\n");
 for(int j=0; j<M; j++)
 printf("%c ",65+j);
 printf("\n");
 for(int j=0; j<M; j++)
 printf("%d ",avail[j]);
 printf("\n");
}
void check_deadlock()
{
 int work[M], finish[N]={0}, safe_seq[N], count=0;
 for(int j=0; j<M; j++)
 work[j] = avail[j];
 while(count < n)
 {
 int found=0;
 for(int i=0; i<n; i++)
 {
 if(!finish[i])
 {
 int j;
for(j=0; j<M; j++)
 if(need[i][j] > work[j])
 break;
 if(j==M)
 {
 for(int k=0; k<M; k++)
 work[k] += alloc[i][k];
 finish[i]=1;
 safe_seq[count++] = i;
 found=1;
 }
 }
 }
 if(!found) break;
 }
 if(count==n)
 {
 printf("\nNo deadlock. System is in safe state.\nSafe sequence: ");
 for(int i=0; i<n; i++)
 printf("P%d ",safe_seq[i]);
 printf("\n");
 }
 else
 printf("\nDeadlock detected! System is not in safe state.\n");
}
int main()
{
 int ch;
 do{
 printf("\n--- Menu ---\n");
 printf("1. Accept Allocation and Max\n");
 printf("2. Display Allocation and Max\n");
 printf("3. Find Need and display\n");
 printf("4. Display Available\n");
 printf("5. Check for deadlock\n");
 printf("6. Exit\n");
 printf("Enter choice: ");
 scanf("%d",&ch);
 switch(ch)
 {
 case 1: accept(); break;
 case 2: display_alloc_max(); break;
 case 3: calc_need(); display_need(); break;
 case 4: calc_avail(); display_avail(); break;
 case 5: calc_need(); calc_avail(); check_deadlock(); break;
 case 6: break;
 default: printf("Invalid choice!\n");
 }
 }while(ch!=6);
 return 0;
}