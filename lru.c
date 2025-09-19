#include <stdio.h>
#define MAX 100
int findLRU(int time[], int n) {
 int i, minimum = time[0], pos = 0;
 for(i = 1; i < n; ++i) {
 if(time[i] < minimum) {
 minimum = time[i];
 pos = i;
 }
 }
 return pos;
}
int main() {
 int frames[MAX], time[MAX];
 int referenceString[MAX];
 int n, refLen;
 int i, j, pos, pageFaults = 0, count = 0, found;
 // Input number of frames
 printf("Enter number of memory frames: ");
 scanf("%d", &n);
 // Input reference string length
 printf("Enter the length of the reference string: ");
 scanf("%d", &refLen);
 // Input reference string
 printf("Enter the reference string:\n");
 for(i = 0; i < refLen; i++) {
 scanf("%d", &referenceString[i]);
 }
 // Initialize frames
 for(i = 0; i < n; ++i) {
 frames[i] = -1;
 time[i] = 0;
 }
 printf("\nPage Replacement Process (LRU):\n");
for(i = 0; i < refLen; ++i) {
 found = 0;
 // Check if page is already in frame
 for(j = 0; j < n; ++j) {
 if(frames[j] == referenceString[i]) {
 count++;
 time[j] = count;
 found = 1;
 break;
 }
 }
 // If page not found => Page Fault
 if(!found) {
 // If frame has empty slot
 for(j = 0; j < n; ++j) {
 if(frames[j] == -1) {
 count++;
 pageFaults++;
 frames[j] = referenceString[i];
 time[j] = count;
 found = 1;
 break;
 }
 }
 }
 // If no empty slot, replace LRU page
 if(!found) {
 pos = findLRU(time, n);
 count++;
 pageFaults++;
 frames[pos] = referenceString[i];
 time[pos] = count;
 }
 // Display frame contents
 printf("Step %2d: ", i + 1);
 for(j = 0; j < n; ++j) {
 if(frames[j] != -1)
 printf("%d ", frames[j]);
 else
 printf("- ");
 }
if(found)
 printf(" <- No Page Fault\n");
 else
 printf(" <- Page Fault\n");
 }
 printf("\nTotal Page Faults = %d\n", pageFaults);
 return 0;
}
