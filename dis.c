#include<stdio.h>
#include<stdlib.h>
int main(){
      int n, i;
    printf("Enter number of disk requests: ");
    scanf("%d", &n);
    int requests[n];
    printf("Enter the disk requests:\n");
  
      for(i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }
    int head;
    printf("Enter initial head position: ");
    scanf("%d", &head);
  int totalSeekTime = 0;

    printf("\nSeek Sequence: %d", head);

    for(i = 0; i < n; i++) {
        int seek = abs(requests[i] - head);
        totalSeekTime += seek;
        head = requests[i];

        printf(" -> %d", head);
    }

    printf("\n\nTotal Seek Time: %d", totalSeekTime);

   printf("\nGraph (Disk Head Movement):\n\n");

    for(i = 0; i <= n; i++) {
        printf("Step %d (%3d): ", i, sequence[i]);

        // print spaces proportional to disk position
        for(int j = 0; j < sequence[i]; j += 2) {
            printf(" ");
        }

        printf("*\n");
    }
    return 0;
}