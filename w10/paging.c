#include <stdio.h>
#define MAX 50

int main() {
    int page[MAX], n, f, ps;
    int pno, off, choice = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page size: ");
    scanf("%d", &ps);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    // Initialize page table
    for (int i = 0; i < n; i++)
        page[i] = -1;

    printf("\nEnter page table (frame number for each page):\n");
    for (int i = 0; i < n; i++) {
        printf("Page %d: ", i);
        scanf("%d", &page[i]);
    }

    do {
        printf("\nEnter logical address (page number and offset): ");
        scanf("%d%d", &pno, &off);

        // Validation
        if (pno < 0 || pno >= n) {
            printf("Invalid page number!\n");
            continue;
        }

        if (off < 0 || off >= ps) {
            printf("Invalid offset!\n");
            continue;
        }

        if (page[pno] == -1) {
            printf("Page Fault! Page not in memory.\n");
        } else {
            int frame = page[pno];
            int physical_address = frame * ps + off;

            printf("Frame number: %d\n", frame);
            printf("Physical Address: %d\n", physical_address);
        }

        printf("Continue? (1/0): ");
        scanf("%d", &choice);

    } while (choice == 1);

    return 0;
}