#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>

int main(){

        int i=0;
        char c;
        int id = semget(5, 1, IPC_CREAT | 0666);
        if(id == -1){
                perror("semget");
                exit(1);
        }
        struct sembuf sem_op;
        sem_op.sem_num = 0;
        sem_op.sem_op = -1;
        sem_op.sem_flg = 0;
        semop(id, &sem_op, 1);

        while(i<=3){
                FILE *fp = fopen("qqq.txt","r+");
                while((c=getc(fp))!=EOF){
                        printf("%c",c);
                }
                i++;
                fclose(fp);
        }
        sem_op.sem_num = 0;
        sem_op.sem_op = 1;
        sem_op.sem_flg = 0;
        semop(id, &sem_op, 1);

        return 0;
}
