#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "patient.h"


Patient *createPatient(char *pid, char *sym, int patientPriority){
    Patient *p = malloc(sizeof(Patient));
    strcpy(p->pid, pid);
    strcpy(p->sym, sym);
    p->patientPriority = patientPriority;

    return p;
}


char *getID(Patient *p){
    return p->pid;
}


char *getSymptom(Patient *p){
    return p->sym;
}


void setFinishTime(Patient *p, int finishTime){
    p->finishTime = finishTime;
}


int getFinishTime(Patient *p){
    return p->finishTime;
}


void printPatient(void *data){
    Patient *p = (Patient *) data;
    printf("%s\t\t\t|%d\t\t\t|%s\t\t\t|%d\n",p->pid, p->patientPriority, p->sym, p->finishTime);
}


void deletePatient(void *data){
    if(data != NULL){
        free(data);
    }
}


int comparePatient(const void *first, const void *second){
    Patient *p1 = (Patient *) first;
    Patient *p2 = (Patient *) second;

    return strcmp(getID(p1), getID(p2));
}