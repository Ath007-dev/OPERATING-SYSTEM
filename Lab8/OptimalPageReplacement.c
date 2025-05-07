#include <stdio.h>
#include <limits.h>

#define MAX_FRAMES 10

void optimal(int pages[], int n, int frames) {
    int frame[frames];
    int pageFaults = 0;

    for (int i = 0; i < frames; i++) {
        frame[i] = -1; // Initialize frames as empty
    }

    printf("\nOptimal Page Replacement:\n");

    for (int i = 0; i < n; i++) {
        int pageFound = 0;

        // Check if the page is already in the frame
        for (int j = 0; j < frames; j++) {
            if (frame[j] == pages[i]) {
                pageFound = 1;
                break;
            }
        }

        if (!pageFound) {
            // Find the page that will not be used for the longest period of time
            int farthest = -1;
            int replaceIndex = -1;

            // If there is an empty frame, place the page in the empty frame
            for (int j = 0; j < frames; j++) {
                if (frame[j] == -1) {
                    replaceIndex = j;
                    break;
                }
            }

            // If all frames are full, find the page to replace
            if (replaceIndex == -1) {
                for (int j = 0; j < frames; j++) {
                    int nextUse = -1;
                    // Find when the page in the frame will be used again in the future
                    for (int k = i + 1; k < n; k++) {
                        if (frame[j] == pages[k]) {
                            nextUse = k;
                            break;
                        }
                    }

                    // If the page will not be used again, replace it
                    if (nextUse == -1) {
                        replaceIndex = j;
                        break;
                    }

                    // Otherwise, choose the page that is used farthest in the future
                    if (nextUse > farthest) {
                        farthest = nextUse;
                        replaceIndex = j;
                    }
                }
            }

            // Replace the page in the selected frame
            frame[replaceIndex] = pages[i];
            pageFaults++;
        }

        // Print the frame status after every page reference
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

    optimal(pages, n, frames);

    return 0;
}
