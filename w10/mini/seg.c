#include <stdio.h>

int main() {
    int s[10][2], n, sn, off;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d%d", &s[i][0], &s[i][1]); // limit, base

    scanf("%d%d", &sn, &off);

    if (sn >= n)
        printf("Invalid\n");
    else if (off >= s[sn][0])
        printf("Limit Exceeded\n");
    else {
        int pa = s[sn][1] + off;
        printf("%d\n", pa);
    }
}