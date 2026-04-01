#include <stdio.h>

int main() {
    int segTable[10][2]; // [limit, base]
    int numSeg, segNo, offset;

    printf("Enter number of segments: ");
    scanf("%d", &numSeg);

    // Input segment table
    for (int i = 0; i < numSeg; i++) {
        printf("Segment %d (Limit Base): ", i);
        scanf("%d %d", &segTable[i][0], &segTable[i][1]);
    }

    while (1) {
        printf("\nEnter segment number and offset (-1 to exit): ");
        scanf("%d", &segNo);

        if (segNo == -1) break;

        scanf("%d", &offset);

        // Validation
        if (segNo < 0 || segNo >= numSeg) {
            printf("Invalid segment number!\n");
            continue;
        }

        int limit = segTable[segNo][0];
        int base  = segTable[segNo][1];

        if (offset < 0 || offset >= limit) {
            printf("Invalid offset! (Exceeds limit)\n");
        } else {
            int physical = base + offset;

            printf("Base = %d, Offset = %d\n", base, offset);
            printf("Physical Address = %d\n", physical);
        }
    }

    return 0;
}