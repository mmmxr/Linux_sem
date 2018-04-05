#include "comm.h"
int main()
{
    int semid=CreatSem(1);
    InitSem(semid,0,1);
    pid_t id=fork();
    if(id==0)
    {
        int _semid=GetSem(0);
        while(1)
        {
            P(_semid,0);
            printf("A");
            fflush(stdout);
            usleep(123456);
            printf("A ");
            fflush(stdout);
            usleep(234512);
            V(_semid,0);
        }
    }
    else
    {
        while(1)
        {
            P(semid,0);
            printf("B");
            fflush(stdout);
            usleep(134532);
            printf("B ");
            fflush(stdout);
            usleep(121412);
            V(semid,0);
        }
    wait(NULL);
    }
    DestroySem(semid);
    return 0;
}
