/* #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX 512

struct msg {
    long type;
    char text[MAX];
};

int main() {
    int msgid;
    struct msg m;

    msgid = msgget(12345, 0666 | IPC_CREAT);

    if (msgid == -1) {
        perror("msgget");
        exit(1);
    }

    while (1) {
        printf("Enter message: ");
        fgets(m.text, MAX, stdin);

        m.type = 1;

        msgsnd(msgid, &m, strlen(m.text) + 1, 0);

        if (strncmp(m.text, "end", 3) == 0) break;
    }

    return 0;
} */
