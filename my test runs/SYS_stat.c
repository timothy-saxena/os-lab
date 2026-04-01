#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>

int main() {
    struct stat s;
    char file[50];

    printf("Enter file name: ");
    scanf("%s", file);

    if (stat(file, &s) == -1) {
        printf("Error getting file details\n");
        return 1;
    }

    printf("\nFile Size: %ld bytes\n", s.st_size);

    printf("Permissions:\n");

    if (s.st_mode & S_IRUSR) printf("User has read permission\n");

    if (s.st_mode & S_IWUSR) printf("User has write permission\n");

    if (s.st_mode & S_IXUSR) printf("User has execute permission\n");

    printf("Change Time: %s", ctime(&s.st_ctime));
    printf("Last Modified: %s", ctime(&s.st_mtime));

    return 0;
}
/*  */
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>

void printFileProperties(struct stat fileStat);

int main() {
    char path[100];
    struct stat fileStat;

    printf("Enter file path: ");
    scanf("%s", path);

    if (stat(path, &fileStat) == 0) {
        printFileProperties(fileStat);
    } else {
        perror("stat failed");
        exit(EXIT_FAILURE);
    }

    return 0;
}

void printFileProperties(struct stat fileStat) {
    struct tm *timeinfo;

    printf("\n--- File Properties ---\n");

    // File Size
    printf("File Size: %ld bytes\n", fileStat.st_size);

    // File Permissions
    printf("File Permissions: ");

    if (fileStat.st_mode & S_IRUSR)
        printf("r");
    else
        printf("-");

    if (fileStat.st_mode & S_IWUSR)
        printf("w");
    else
        printf("-");

    if (fileStat.st_mode & S_IXUSR)
        printf("x");
    else
        printf("-");

    printf("\n");

    // Last Status Change Time
    timeinfo = localtime(&fileStat.st_ctime);
    printf("Last Status Change: %s", asctime(timeinfo));

    // Last Modification Time
    timeinfo = localtime(&fileStat.st_mtime);
    printf("Last Modified: %s", asctime(timeinfo));
}