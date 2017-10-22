#ifndef PATIENT_H
#define PATIENT_H

typedef struct Patient{
    char pid[100];
    char sym[3];
    int finishTime;
    int patientPriority;
}Patient;

Patient *createPatient(char *pid, char *sym, int patientPriority);

char *getID(Patient *p);

char *getSymptom(Patient *p);

int getFinishTime(Patient *p);

void setFinishTime(Patient *p, int finishTime);

void printPatient(void *data);

void deletePatient(void *data);

int comparePatient(const void *first, const void *second);

#endif