#include <stdio.h>
int main() {
    int n, ps;
    printf("Enter no of pages and size of each page: \n");
    scanf("%d %d", &n, &ps);

    int page[10];
    for (int i = 0; i < n; i++) {
        printf("\nenter frame no of page no %d", i);
        scanf("%d", &page[i]);
    }

    int pageNo, off;
    printf("\nEnter pageno and offset: ");
    scanf("%d %d", &pageNo, &off);

    int frameNo = page[pageNo];

    if (frameNo == -1) {
        printf("page fault \n");
    } else {
        int phy_add = (frameNo * ps) + off;
        printf("phy add: %d", phy_add);
    }
    
}