#include <stdio.h>

int main() {
    int n, m;
    printf("Number of frames: ");
    scanf("%d", &n);
    printf("Number of References: ");
    scanf("%d", &m);

    int f[n];          
    int ref[m];   
  int pageFound = 0;
    int pageFaults = 0;
    int nextToReplace = 0; 
    for (int i = 0; i < n; i++) {
        f[i] = -1;
    }

    printf("Enter the String reference: ");
    for (int i = 0; i < m; i++) {
        scanf("%d", &ref[i]);
    }

   
    for (int i = 0; i < m; i++) {
        int page = ref[i];
        int found = 0;

        for (int j = 0; j < n; j++) {
            if (f[j] == page) {
                found = 1;
              pageFound++;
              break;
            }
        }

        if (!found) {
            f[nextToReplace] = page;
            nextToReplace = (nextToReplace + 1) % n;
            pageFaults++;
        }

   
        printf("Step %d: ", i + 1);
        for (int j = 0; j < n; j++) {
            if (f[j] == -1)
                printf(" - ");
            else
                printf(" %d ", f[j]);
        }
        printf("\n");
    }

    printf("Total Page Faults = %d\n", pageFaults);
   printf("Total Page Found = %d\n", pageFound);
  float r = (float)pageFound/m;
   printf("Hit Ratio = %.2f\n", r);

    return 0;
}
