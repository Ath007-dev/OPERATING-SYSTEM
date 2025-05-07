#include <stdio.h>

#define MAX_FRAMES 10

void lru(int pages[], int n, int frames) {
    int frame[frames];
    int pageFaults = 0;

    for (int i = 0; i < frames; i++) {
        frame[i] = -1;
    }

    printf("\nLRU Page Replacement:\n");
    for (int i = 0; i < n; i++) {
        int pageFound = 0;
        int leastRecent = -1, leastRecentIndex = -1;

        for (int j = 0; j < frames; j++) {
            if (frame[j] == pages[i]) {
                pageFound = 1;
                break;
            }
            if (frame[j] == -1) {
                leastRecentIndex = j;
                break;
            }
        }

        if (!pageFound) {
            if (leastRecentIndex != -1) {
                frame[leastRecentIndex] = pages[i];
            } else {
                for (int j = 0; j < frames; j++) {
                    for (int k = i - 1; k >= 0; k--) {
                        if (pages[k] == frame[j]) {
                            leastRecent = k;
                            break;
                        }
                    }
                    if (leastRecent == -1) {
                        leastRecentIndex = j;
                        break;
                    }
                }
                frame[leastRecentIndex] = pages[i];
            }
            pageFaults++;
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

    lru(pages, n, frames);

    return 0;
}
