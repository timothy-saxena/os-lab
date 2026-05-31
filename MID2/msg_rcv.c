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
        msgrcv(msgid, &m, MAX, 0, 0);

        printf("Received: %s", m.text);

        if (strncmp(m.text, "end", 3) == 0) break;
    }

    msgctl(msgid, IPC_RMID, NULL);

    return 0;
} */
