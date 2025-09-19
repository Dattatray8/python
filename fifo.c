#include <stdio.h>
#define MAX 100
int main() {
 int referenceString[MAX], frames[MAX], n, refLen;
 int i, j, k, pageFaults = 0, found, pos = 0;
 // Input number of frames
 printf("Enter number of memory frames: ");
 scanf("%d", &n);
 // Input length of reference string
 printf("Enter the length of the reference string: ");
 scanf("%d", &refLen);
 // Input reference string
 printf("Enter the reference string (space-separated):\n");
 for(i = 0; i < refLen; i++) {
 scanf("%d", &referenceString[i]);
 }
 // Initialize frames to -1 (empty)
 for(i = 0; i < n; i++) {
 frames[i] = -1;
 }
 printf("\nPage Replacement Process (FIFO):\n");
 // FIFO implementation
 for(i = 0; i < refLen; i++) {
 found = 0;
 // Check if page is already in frame
 for(j = 0; j < n; j++) {
 if(frames[j] == referenceString[i]) {
 found = 1;
 break;
 }
 }
 // If page not found => Page Fault
 if(!found) {
 frames[pos] = referenceString[i];
 pos = (pos + 1) % n; // Move pointer circularly
 pageFaults++;
 // Display current frame status
 printf("Step %2d: ", i + 1);
 for(k = 0; k < n; k++) {
 if(frames[k] != -1)
    printf("%d ", frames[k]);
 else
   printf("- ");
 }
 printf(" <- Page Fault\n");
 } else {
 // Display if page already in frame
 printf("Step %2d: ", i + 1);
 for(k = 0; k < n; k++) {
 if(frames[k] != -1)
 printf("%d ", frames[k]);
 else
 printf("- ");
 }
 printf(" <- No Page Fault\n");
 }
 }
 // Output total number of page faults
 printf("\nTotal Page Faults = %d\n", pageFaults);
 return 0;
}
