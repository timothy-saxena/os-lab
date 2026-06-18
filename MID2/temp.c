#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>

int main(){
    int shmid;
    shmid = shmget(2345,1024,0666 || IPC_CREAT);
    char * shared_memory;
    shared_memory = (char *)shmat(shmid,NULL,0);
    printf("ID %d", shmid);
    printf("Attach loc: %p",shared_memory);

    char msg[100];
    printf("enter something: ");
    scanf("%s",msg);

    strcpy(shared_memory,msg);
    printf("value: %s", shared_memory);
}