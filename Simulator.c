
#include <stdio.h>

#define MAX 50

struct Process {
    int pid;
    int arrival;
    int burst;
    int completion;
    int turnaround;
    int waiting;
};

// main function
int main() {
    struct Process p[MAX];
    int n;
    int currentTime = 0;
    float avgWaiting = 0;
    float avgTurnaround = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX) {
        printf("Invalid number of processes!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;

        printf("\nEnter arrival time for P%d: ", i + 1);
        scanf("%d", &p[i].arrival);

        printf("Enter burst time for P%d: ", i + 1);
        scanf("%d", &p[i].burst);

        if (p[i].arrival < 0 || p[i].burst <= 0) {
            printf("Invalid process details!\n");
            return 1;
        }
    }

    for (int i = 0; i < n; i++) {

        if (currentTime < p[i].arrival) {
            currentTime = p[i].arrival;
        }

        currentTime = currentTime + p[i].burst;

        p[i].completion = currentTime;

        p[i].turnaround =
            p[i].completion - p[i].arrival;

        p[i].waiting =
            p[i].turnaround - p[i].burst;

        avgWaiting += p[i].waiting;
        avgTurnaround += p[i].turnaround;
    }

    // results
    printf("\n\n ----- FCFS CPU SCHEDULER ----- \n");

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");

    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
            p[i].pid,
            p[i].arrival,
            p[i].burst,
            p[i].completion,
            p[i].turnaround,
            p[i].waiting);
    }

    avgWaiting = avgWaiting / n;
    avgTurnaround = avgTurnaround / n;

    printf("\nAverage Waiting Time: %.2f", avgWaiting);
    printf("\nAverage Turnaround Time: %.2f\n", avgTurnaround);

    return 0;
}
