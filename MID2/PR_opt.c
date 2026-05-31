#include <stdio.h>

int main() {
    int nof, nop;

    printf("Enter number of frames: ");
    scanf("%d", &nof);

    printf("Enter number of pages: ");
    scanf("%d", &nop);

    int pages[50];

    printf("Enter reference string:\n");

    for (int i = 0; i < nop; i++) scanf("%d", &pages[i]);

    int frame[10];

    for (int i = 0; i < nof; i++) frame[i] = -1;

    int pageFaults = 0;

    printf("\nPage\tFrames\n");

    for (int i = 0; i < nop; i++) {
        int found = 0;

        // Check page hit
        for (int j = 0; j < nof; j++) {
            if (frame[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        if (!found) {
            int pos = -1;

            // Find empty frame
            for (int j = 0; j < nof; j++) {
                if (frame[j] == -1) {
                    pos = j;
                    break;
                }
            }

            // Need replacement
            if (pos == -1) {
                int farthest = -1;

                for (int j = 0; j < nof; j++) {
                    int k;

                    for (k = i + 1; k < nop; k++) {
                        if (frame[j] == pages[k]) break;
                    }

                    // Never used again
                    if (k == nop) {
                        pos = j;
                        break;
                    }

                    if (k > farthest) {
                        farthest = k;
                        pos = j;
                    }
                }
            }

            frame[pos] = pages[i];
            pageFaults++;
        }

        printf("%d\t", pages[i]);
        for (int j = 0; j < nof; j++) printf("%d ", frame[j]);
        printf("\n");
    }
    printf("\nTotal Page Faults = %d\n", pageFaults);
}