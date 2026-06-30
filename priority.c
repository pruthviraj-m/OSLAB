#include <stdio.h>

int main() {
    int n, tq;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], rt[n];
    int ct[n], tat[n], wt[n];

    printf("Enter Arrival Times:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &at[i]);
    }

    printf("Enter Burst Times:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
        rt[i] = bt[i];   
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    int time = 0, completed = 0;
    int found;

    while(completed < n) {

        found = 0;  
        for(int i = 0; i < n; i++) {

            if(rt[i] > 0 && at[i] <= time) {
                found = 1;

                if(rt[i] > tq) {
                    time += tq;
                    rt[i] -= tq;
                } 
                else {
                    time += rt[i];
                    ct[i] = time;
                    rt[i] = 0;
                    completed++;
                }
            }
        }

        if(!found) {
            time++;
        }
    }

    float avgTAT = 0, avgWT = 0;

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");

    for(int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        avgTAT += tat[i];
        avgWT += wt[i];

        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    avgTAT /= n;
    avgWT /= n;

    printf("\nAverage Turnaround Time = %.2f", avgTAT);
    printf("\nAverage Waiting Time = %.2f\n", avgWT);

    return 0;
}