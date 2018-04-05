#include "comm.h"

int CommSem(int nums,int flags)
{
    key_t key=ftok(PATHNAME,PROJ_ID);
    if(key<0)
    {
        perror("ftok");
        return -1;
    }
    int semid=semget(key,nums,flags);
    if(semid<0)
    {
        perror("semget");
        return -2;
    }
    return semid;

}
int CreatSem(int nums)
{
    return CommSem(nums,IPC_CREAT|IPC_EXCL|0666);
}

int GetSem(int nums)
{
    return CommSem(nums,IPC_CREAT);
}

int InitSem(int semid,int nums,int initval)
{
    union semun un;
    un.val=initval;
    if(semctl(semid,nums,SETVAL,un)<0)
    {
        perror("semctl");
        return -1;
    }
    return 0;
}
static int commPV(int semid,int who,int op)
{
    struct sembuf buf;
    buf.sem_num=who;
    buf.sem_op=op;
    buf.sem_flg=0;
    if(semop(semid,&buf,1)<0)
    {
        perror("semop");
        return -1;
    }
    return 0;
}

int P(int semid,int who)
{
    return commPV(semid,who,-1);
}
int V(int semid,int who)
{
    return commPV(semid,who,1);
}
int DestroySem(int semid)
{
    if(semctl(semid,0,IPC_RMID)<0)
    {
        perror("semctl");
        return -1;
    }
    return 0;
}
