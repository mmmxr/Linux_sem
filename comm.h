#pragma once
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>
#include <sys/wait.h>
#define PATHNAME "."
#define PROJ_ID 0x6666
union semun {
    int val;            /* value for SETVAL */
    struct semid_ds *buf;   /* buffer for IPC_STAT & IPC_SET */
    unsigned short *array;  /* array for GETALL & SETALL */
    struct seminfo *__buf;  /* buffer for IPC_INFO */
    void *__pad;

};
int CreatSem(int nums);
int InitSem(int semid,int nums,int initval);
int GetSem(int nums);
int P(int semid,int who);
int V(int semid,int who);
int DestroySem(int semid);
