/*
1. open source (O_RDONLY)
2. open destination (O_WRONLY | O_CREAT | O_TRUNC, 0644)
3. while(read > 0)
       write
4. close both
*/
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int fd1, fd2, n;
    char source[50], dest[50], buffer[1024];

    printf("Enter source file: ");
    scanf("%s", source);

    printf("Enter destination file: ");
    scanf("%s", dest);

    fd1 = open(source, O_RDONLY);
    if (fd1 < 0) {
        printf("Cannot open source file\n");
        exit(1);
    }

    fd2 = open(dest, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd2 < 0) {
        printf("Cannot open destination file\n");
        exit(1);
    }

    while ((n = read(fd1, buffer, sizeof(buffer))) > 0) {
        write(fd2, buffer, n);
    }

    close(fd1);
    close(fd2);

    printf("File copied successfully\n");

    return 0;
}