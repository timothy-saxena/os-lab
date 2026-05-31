#include <stdio.h>

int main() {
    int noF;
    printf("Number of frames: ");
    scanf("%d", &noF);

    int noR;
    printf("Number page references: ");
    scanf("%d", &noR);

    int ref[50];
    printf("Page references: ");
    for (int i = 0; i < noR; i++) scanf("%d", &ref[i]);

    int frames[20];
    for (int i = 0; i < noF; i++) frames[i] = -1;

    int pageFault = 0;

    for (int i = 0; i < noR; i++) {
        // check for page hit
        int found = 0;
        for (int j = 0; j < noF; j++) {
            if (frames[j] == ref[i]) {
                found = 1;
                break;
            }
        }

        // not present in the current frames
        if (!found) {
            // check for empty frame
            int pos = -1;
            for (int j = 0; j < noF; j++) {
                if (frames[j] == -1) {
                    pos = j;
                    break;
                }
            }
            // needs replacement
            if (pos == -1) {
                int lruIdx = i;
                pos = 0;
                for (int j = 0; j < noF; j++) {
                    int k;
                    for (k = i - 1; k >= 0; k--) {
                        if (frames[j] == ref[k]) break;
                    }
                    if (k < lruIdx) {
                        lruIdx = k;
                        pos = j;
                    }
                }
            }
            frames[pos] = ref[i];
            pageFault++;
        }
        printf("%d\t", ref[i]);
        for (int i = 0; i < noF; i++) printf("%d ", frames[i]);
        printf("\n");
    }
    printf("No of page faults: %d", pageFault);
}