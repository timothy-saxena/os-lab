#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    DIR *dir;
    struct dirent *entry;

    // Open current directory
    dir = opendir(".");

    if (dir == NULL) {
        printf("Unable to open directory\n");
        return 1;
    }

    printf("Contents of current directory:\n");

    // Read entries one by one
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    // Close directory
    closedir(dir);

    return 0;
}
/*

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main()
{
    DIR *dir;
    struct dirent *entry;

    // Open the current directory (".")
    dir = opendir(".");

    if (dir == NULL)
    {
        perror("opendir failed");
        exit(EXIT_FAILURE);
    }

    printf("Contents of current directory:\n");

    // Read directory entries one by one
    while ((entry = readdir(dir)) != NULL)
    {
        printf("%s\n", entry->d_name);
    }

    // Close the directory
    if (closedir(dir) == -1)
    {
        perror("closedir failed");
        exit(EXIT_FAILURE);
    }

    return 0;
}
    /* gpt */
*/