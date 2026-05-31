#include <stdio.h>

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
}