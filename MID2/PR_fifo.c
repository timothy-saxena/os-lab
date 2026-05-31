#include <stdio.h>
int main() {
    int nof, nor;

    printf("Enter number of frames: ");
    scanf("%d", &nof);

    printf("Enter number of pages in reference string: ");
    scanf("%d", &nor);

    int ref[50];
    printf("Enter reference string:\n");

    for (int i = 0; i < nor; i++) scanf("%d", &ref[i]);

    int frame[10];

    for (int i = 0; i < nof; i++) frame[i] = -1;

    int pageFaults = 0;
    int victim = 0;

    printf("\nPage\tFrames\n");

    for (int i = 0; i < nor; i++) {
        int found = 0;

        for (int j = 0; j < nof; j++) {
            if (frame[j] == ref[i]) {
                found = 1;
                break;
            }
        }

        if (!found) {
            frame[victim] = ref[i];
            victim = (victim + 1) % nof;
            pageFaults++;
        }

        printf("%d\t", ref[i]);
        for (int j = 0; j < nof; j++) printf("%d ", frame[j]);
        printf("\n");
    }
    printf("\nTotal Page Faults = %d\n", pageFaults);
}
/* #include <stdio.h>

int main() {
    int noF;
    printf("number of frames: ");
    scanf("%d", &noF);

    int noref;
    printf("number of ref str: ");
    scanf("%d", &noref);

    int ref[50];
    printf("enter ref str:: ");
    for (int i = 0; i < noref; i++) {
        scanf("%d", &ref[i]);
    }

    int pf = 0;
    int victim = 0;
    int frames[20];
    for (int i = 0; i < 20; i++) frames[i] = -1;

    printf("Page \t Frames\n");

    for (int i = 0; i < noref; i++) {
        int found = 0;

        for (int j = 0; j < noF; j++) {
            if (frames[j] == ref[i]) {
                found = 1;
                break;
            }
        }

        if (!found) {
            frames[victim] = ref[i];
            victim = (victim + 1) % noF;
            pf++;
        }

        printf("%d\t", ref[i]);
        for (int i = 0; i < noF; i++) {
            printf("%d ", frames[i]);
        }
        printf("\n");
    }
    printf("not of pf %d", pf);
} */