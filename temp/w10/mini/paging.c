#include <stdio.h>

int main() {
    int p[10], n, ps, pno, off;

    scanf("%d%d", &n, &ps);   // pages, page size

    for (int i = 0; i < n; i++)
        scanf("%d", &p[i]);   // page table

    scanf("%d%d", &pno, &off);

    if (pno >= n || off >= ps)
        printf("Invalid\n");
    else if (p[pno] == -1)
        printf("Page Fault\n");
    else {
        int pa = p[pno] * ps + off;
        printf("%d\n", pa);
    }
}