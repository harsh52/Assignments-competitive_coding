#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdlib.h>
#include <stdio.h>
int main(){

        union semun {
                int              val;    /* Value for SETVAL */
                struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
                unsigned short  *array;  /* Array for GETALL, SETALL */
                } a;
        int i=0;
        int sid;
        char c;
        if ((sid = semget(5, 1, 0666 | IPC_CREAT)) == -1) {
                perror("semget");
                exit(1);
        }
        a.val = 1;
        if (semctl(sid, 0, SETVAL, a) == -1) {
                perror("semctl");
                exit(1);
        }
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
                FILE *fp = fopen("qqq
.txt","r+");
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
