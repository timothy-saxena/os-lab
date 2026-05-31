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
        // chek for page hit
        int found = 0;
        for (int j = 0; j < noF; j++) {
            if (frames[j] == ref[i]) {
                found = 1;
                break;
            }
        }

        // if not found
        if (!found) {
            // check for empty frame
            int pos = -1;
            for (int j = 0; j < noF; j++) {
                if (frames[j] == -1) {
                    pos = j;
                    break;
                }
            }
            // if no empty frame is present
            if (pos == -1) {
                int farthest = -1;
                for (int j = 0; j < noF; j++) {
                    int k;
                    for (k = i + 1; k < noR; k++) {
                        if (frames[j] == ref[k]) break;
                    }
                    if (k == noR) {
                        pos = j;
                        break;
                    }
                    if (k > farthest) {
                        farthest = k;
                        pos = j;
                    }
                }
            }
            frames[pos] = ref[i];
            pageFault++;
        }
        printf("%d\t", ref[i]);
        for (int j = 0; j < noF; j++) printf("%d ", frames[j]);
        printf("\n");
    }
    printf("Number of page faults: %d", pageFault);
}