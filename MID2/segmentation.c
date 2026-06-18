/* #include <stdio.h>

int main() {
    int numSeg;

    printf("Enter number of segments: ");
    scanf("%d", &numSeg);

    int segTable[10][2];  // [Limit][Base]

    printf("\nEnter Limit and Base Address for each segment:\n");

    for (int i = 0; i < numSeg; i++) {
        printf("Segment %d: ", i);
        scanf("%d %d", &segTable[i][0], &segTable[i][1]);
    }

    int segNo, offset;

    printf("\nEnter Segment Number and Offset: ");
    scanf("%d %d", &segNo, &offset);

    if (segNo < 0 || segNo >= numSeg) {
        printf("Invalid Segment Number\n");
    } else if (offset < 0 || offset >= segTable[segNo][0]) {
        printf("Invalid Offset (exceeds limit)\n");
    } else {
        int base = segTable[segNo][1];
        int physicalAddress = base + offset;

        printf("Base Address = %d\n", base);
        printf("Physical Address = %d\n", physicalAddress);
    }

    return 0;
} */

#include <stdio.h>

int main() {
    /*
    1. i need the segment table
    2. i will input segno & off
    3. then just check condition and output

     */

    int noSeg;
    printf("Enter number of segment: ");
    scanf("%d", &noSeg);

    int seg_table[10][2];
    printf("Enter limit and base values: ");
    for (int i = 0; i < noSeg; i++) {
        scanf("%d %d", &seg_table[i][0], &seg_table[i][1]);
    }

    int s, off;
    printf("Enter segment & off: ");
    scanf("%d %d", &s, &off);

    if (s < 0 || s > noSeg) {
        printf("invalid segment");
    } else if (off < 0 || off > seg_table[s][0]) {
        printf("page fault");
    } else {
        int pa = off + seg_table[s][1];
        printf("pa %d", pa);
    }
}