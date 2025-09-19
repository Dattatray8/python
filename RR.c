#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 20
#define IO_WAIT 2
typedef struct {
 int pid;
 int arrival;
 int burst1; // first CPU burst
 int burst2; // second CPU burst (random)
 int remaining; // remaining time (for RR)
 int completion;
 int turnaround;
 int waiting;
 int done;
} Process;
int main() {
 Process p[MAX];
 int n, tq;
 int current_time = 0, completed = 0;
 float avgTAT = 0, avgWT = 0;
 srand(time(NULL));
 printf("Enter number of processes: ");
 scanf("%d", &n);
 printf("Enter Time Quantum: ");
 scanf("%d", &tq);
 // Input processes
 for(int i=0; i<n; i++) {
 p[i].pid = i+1;
 printf("\nEnter arrival time of P%d: ", p[i].pid);
 scanf("%d", &p[i].arrival);
 printf("Enter first CPU burst of P%d: ", p[i].pid);
 scanf("%d", &p[i].burst1);
 // Random second burst
 p[i].burst2 = (rand() % 10) + 1;
 // Remaining time = first burst + I/O wait + second burst
 p[i].remaining = p[i].burst1 + IO_WAIT + p[i].burst2;
 p[i].done = 0;
 }
 printf("\n\nGantt Chart:\n");
 int queue[MAX], front = 0, rear = 0, inQueue[MAX] = {0};
 // Scheduling loop
 while(completed < n) {
 // Load new arrivals
 for(int i=0; i<n; i++) {
 if(p[i].arrival <= current_time && !inQueue[i] && !p[i].done) {
 queue[rear++] = i;
 inQueue[i] = 1;
 }
 }
 if(front == rear) { // No process in queue
 current_time++;
 continue;
 }
 int idx = queue[front++];
 inQueue[idx] = 0;
 printf("| P%d ", p[idx].pid);
 if(current_time < p[idx].arrival)
 current_time = p[idx].arrival;
 int exec_time = (p[idx].remaining > tq) ? tq : p[idx].remaining;
 current_time += exec_time;
 p[idx].remaining -= exec_time;
 // Check new arrivals during execution
 for(int i=0; i<n; i++) {
 if(p[i].arrival <= current_time && !inQueue[i] && !p[i].done && p[i].remaining > 0) {
 queue[rear++] = i;
 inQueue[i] = 1;
 }
 }
 if(p[idx].remaining > 0) {
 queue[rear++] = idx; // Put back into queue
 inQueue[idx] = 1;
 } else {
 p[idx].completion = current_time;
 p[idx].turnaround = p[idx].completion - p[idx].arrival;
 p[idx].waiting = p[idx].turnaround - (p[idx].burst1 + p[idx].burst2);
 avgTAT += p[idx].turnaround;
 avgWT += p[idx].waiting;
 p[idx].done = 1;
 completed++;
 }
 }
 printf("|\n");
 printf("\nProcess\tAT\tBT1\tBT2\tCT\tTAT\tWT");
 for(int i=0; i<n; i++) {
 printf("\nP%d\t%d\t%d\t%d\t%d\t%d\t%d",
 p[i].pid, p[i].arrival, p[i].burst1, p[i].burst2,
 p[i].completion, p[i].turnaround, p[i].waiting);
 }
 printf("\n\nAverage Turnaround Time = %.2f", avgTAT/n);
 printf("\nAverage Waiting Time = %.2f\n", avgWT/n);
 return 0;
}
