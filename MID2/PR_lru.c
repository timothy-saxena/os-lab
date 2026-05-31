#include <stdio.h>

int main() {
    int nof, nor;

    printf("Enter number of frames: ");
    scanf("%d", &nof);

    printf("Enter number of pages: ");
    scanf("%d", &nor);

    int ref[50];

    printf("Enter reference string:\n");

    for (int i = 0; i < nor; i++) scanf("%d", &ref[i]);

    int frame[10];

    for (int i = 0; i < nof; i++) frame[i] = -1;

    int pageFaults = 0;

    printf("\nPage\tFrames\n");

    for (int i = 0; i < nor; i++) {
        int found = 0;
        // checking for page hit
        for (int j = 0; j < nof; j++) {
            if (frame[j] == ref[i]) {
                found = 1;
                break;
            }
        }

        if (!found) {
            int pos = -1;
            // checking for empty frame
            for (int j = 0; j < nof; j++) {
                if (frame[j] == -1) {
                    pos = j;
                    break;
                }
            }
            // Need replacement
            if (pos == -1) {
                int lruIndex = i;
                pos = 0;

                for (int j = 0; j < nof; j++) {
                    int k;

                    for (k = i - 1; k >= 0; k--) {
                        if (frame[j] == ref[k]) break;
                    }

                    if (k < lruIndex) {
                        lruIndex = k;
                        pos = j;
                    }
                }
            }

            frame[pos] = ref[i];
            pageFaults++;
        }

        printf("%d\t", ref[i]);
        for (int j = 0; j < nof; j++) printf("%d ", frame[j]);
        printf("\n");
    }
    printf("\nTotal Page Faults = %d\n", pageFaults);
}