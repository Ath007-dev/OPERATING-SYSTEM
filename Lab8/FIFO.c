#include <stdio.h>

#define MAX_FRAMES 10

void fifo(int pages[], int n, int frames) {
    int frame[frames];
    int pageFaults = 0;
    int index = 0;

    for (int i = 0; i < frames; i++) {
        frame[i] = -1;
    }

    printf("\nFIFO Page Replacement:\n");
    for (int i = 0; i < n; i++) {
        int pageFound = 0;
        for (int j = 0; j < frames; j++) {
            if (frame[j] == pages[i]) {
                pageFound = 1;
                break;
            }
        }

        if (!pageFound) {
            frame[index] = pages[i];
            pageFaults++;
            index = (index + 1) % frames;
        }

        printf("Frame: ");
        for (int j = 0; j < frames; j++) {
            if (frame[j] != -1)
                printf("%d ", frame[j]);
        }
        printf("\n");
    }

    printf("Total Page Faults: %d\n", pageFaults);
}

int main() {
    int n, frames;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    int pages[n];
    printf("Enter page reference string: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    fifo(pages, n, frames);

    return 0;
}
