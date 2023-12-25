#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX 50

struct msg_buffer {
    long mesg_type;
    char mesg_text[100];
    
}message;

int main() {
    key_t key;
    int msgid;
    
    key = ftok("progfile", 65);
    msgid = msgget(key, 0666 | IPC_CREAT);
    message.mesg_type = 1;
    printf("Write data: \n");
    fgets(message.mesg_text, MAX, stdin);
    msgsnd(msgid, &message, sizeof(message), 0);
    printf("Data sent is : %s\n", message.mesg_text);
    return 0;
}
