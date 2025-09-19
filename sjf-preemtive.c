#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 20
#define IO_WAIT 2
typedef struct {
 int pid;
 int arrival;
 int burst1;
 int burst2;
 int remaining; // remaining time (for preemptive SJF)
 int completion;
 int turnaround;
 int waiting;
 int done;
} Process;
int main() {
 Process p[MAX];
 int n, completed = 0;
 int current_time = 0, prev = -1;
 float avgTAT = 0, avgWT = 0;
 srand(time(NULL));
 printf("Enter number of processes: ");
 scanf("%d", &n);
 // Input processes
 for(int i=0; i<n; i++) {
 p[i].pid = i+1;
 printf("\nEnter arrival time of P%d: ", p[i].pid);
 scanf("%d", &p[i].arrival);
 printf("Enter first CPU burst of P%d: ", p[i].pid);
 scanf("%d", &p[i].burst1);
 // Random second burst
 p[i].burst2 = (rand() % 10) + 1;
 // Total required time = burst1 + IO_WAIT + burst2
 p[i].remaining = p[i].burst1 + IO_WAIT + p[i].burst2;
 p[i].done = 0;
 }
 printf("\n\nGantt Chart:\n");
 // Preemptive SJF Simulation
 while(completed < n) {
 int idx = -1;
 int min_remaining = 99999;
 // Pick process with shortest remaining time among arrived
 for(int i=0; i<n; i++) {
 if(!p[i].done && p[i].arrival <= current_time && p[i].remaining < min_remaining &&
p[i].remaining > 0) {
 min_remaining = p[i].remaining;
 idx = i;
 }
 }
 if(idx == -1) {
 current_time++;
 continue;
 }
 // Print process in Gantt chart if it changes
 if(prev != idx) {
 printf("| P%d ", p[idx].pid);
 prev = idx;
 }
 p[idx].remaining--;
 current_time++;
 // If process finishes
 if(p[idx].remaining == 0) {
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
