#include <stdio.h>
#include <stdlib.h>

#define MAX_BLOCKS 100

void worstFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
    for (int i = 0; i < n; i++) {
        allocation[i] = -1;  // Initially, no process is allocated
    }

    for (int i = 0; i < n; i++) {
        int maxIndex = -1;
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (maxIndex == -1 || blockSize[maxIndex] < blockSize[j]) {
                    maxIndex = j;
                }
            }
        }

        if (maxIndex != -1) {
            allocation[i] = maxIndex;
            blockSize[maxIndex] -= processSize[i];
        }
    }

    printf("\nWorst Fit Allocation:\n");
    for (int i = 0; i < n; i++) {
        if (allocation[i] != -1)
            printf("Process %d is allocated to Block %d\n", i + 1, allocation[i] + 1);
        else
            printf("Process %d is not allocated\n", i + 1);
    }
}

void bestFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
    for (int i = 0; i < n; i++) {
        allocation[i] = -1;  // Initially, no process is allocated
    }

    for (int i = 0; i < n; i++) {
        int minIndex = -1;
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (minIndex == -1 || blockSize[minIndex] > blockSize[j]) {
                    minIndex = j;
                }
            }
        }

        if (minIndex != -1) {
            allocation[i] = minIndex;
            blockSize[minIndex] -= processSize[i];
        }
    }

    printf("\nBest Fit Allocation:\n");
    for (int i = 0; i < n; i++) {
        if (allocation[i] != -1)
            printf("Process %d is allocated to Block %d\n", i + 1, allocation[i] + 1);
        else
            printf("Process %d is not allocated\n", i + 1);
    }
}

void firstFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
    for (int i = 0; i < n; i++) {
        allocation[i] = -1;  // Initially, no process is allocated
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }

    printf("\nFirst Fit Allocation:\n");
    for (int i = 0; i < n; i++) {
        if (allocation[i] != -1)
            printf("Process %d is allocated to Block %d\n", i + 1, allocation[i] + 1);
        else
            printf("Process %d is not allocated\n", i + 1);
    }
}

int main() {
    int m, n;

    printf("Enter the number of memory blocks: ");
    scanf("%d", &m);

    int blockSize[m];
    printf("Enter the size of each memory block:\n");
    for (int i = 0; i < m; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &blockSize[i]);
    }

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processSize[n];
    printf("Enter the size of each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &processSize[i]);
    }

    worstFit(blockSize, m, processSize, n);
    bestFit(blockSize, m, processSize, n);
    firstFit(blockSize, m, processSize, n);

    return 0;
}
