#include <stdio.h>
#define MAX 100
// Function to find the page to replace (which is used farthest in the future)
int predict(int referenceString[], int frames[], int refLen, int index, int n) {
 int i, j, farthest = index, pos = -1, found;
 for(i = 0; i < n; i++) {
 found = 0;
 for(j = index; j < refLen; j++) {
 if(frames[i] == referenceString[j]) {
 if(j > farthest) {
 farthest = j;
 pos = i;
 }
 found = 1;
 break;
 }
 }
 // If the page is never used again
 if(!found)
 return i;
 }
 // If all pages will be used again, replace the farthest one
 return (pos == -1) ? 0 : pos;
}
int main() {
 int referenceString[MAX], frames[MAX];
 int refLen = 0, n = 3;
 int i, j, k, pageFaults = 0, found;
 // Input reference string
 printf("Enter the length of the reference string: ");
 scanf("%d", &refLen);
 printf("Enter the reference string (space-separated):\n");
 for(i = 0; i < refLen; i++) {
 scanf("%d", &referenceString[i]);
 }
 // Initialize frames to -1 (empty)
 for(i = 0; i < n; i++) {
 frames[i] = -1;
 }
 printf("\nPage Replacement Process (OPT):\n");
 for(i = 0; i < refLen; i++) {
 found = 0;
 // Check if page is already in frame
 for(j = 0; j < n; j++) {
 if(frames[j] == referenceString[i]) {
 found = 1;
 break;
 }
 }
 // Page Fault
 if(!found) {
 int pos = -1;
 // If there is empty frame
 for(j = 0; j < n; j++) {
 if(frames[j] == -1) {
 pos = j;
 break;
 }
 }
// If no empty frame, find optimal page to replace
 if(pos == -1)
 pos = predict(referenceString, frames, refLen, i + 1, n);
 frames[pos] = referenceString[i];
 pageFaults++;
 }
 // Display current frame status
 printf("Step %2d: ", i + 1);
 for(k = 0; k < n; k++) {
 if(frames[k] != -1)
 printf("%d ", frames[k]);
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
