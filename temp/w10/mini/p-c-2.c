#include <stdio.h>

int m = 1, f = 0, e = 3;
int buf[3], in = 0, out = 0;

int wait(int s) { return --s; }
int signal(int s) { return ++s; }

void prod() {
    if (m == 1 && e > 0) {
        m = wait(m);

        buf[in] = 1;   // dummy item
        in = (in + 1) % 3;

        f = signal(f);
        e = wait(e);

        m = signal(m);
    } else
        printf("Full\n");
}

void cons() {
    if (m == 1 && f > 0) {
        m = wait(m);

        int x = buf[out];
        out = (out + 1) % 3;

        f = wait(f);
        e = signal(e);

        m = signal(m);
    } else
        printf("Empty\n");
}

int main() {
    prod();
    cons();
}