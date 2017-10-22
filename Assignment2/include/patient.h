#ifndef PATIENT_H
#define PATIENT_H

typedef struct Patient{
    char pid[100];
    char sym[3];
    int finishTime;
    int patientPriority;
}Patient;

/**Function that returns a dynamically allocated Car struct.
*@param pid String
*@param sym String
*@param patientPriority int
*@return pointer to Patient Struct
**/
Patient *createPatient(char *pid, char *sym, int patientPriority);

/**Function that returns id of the patient.
*@param pointer to a Patient struct
*@return pid String
**/
char *getID(Patient *p);

/**Function that returns symptom of the patient.
*@param pointer to a Patient struct
*@return sym String
**/
char *getSymptom(Patient *p);

/**Function that sets the finish time of the patient.
*@param pointer to a Patient struct
*@param finishTime int
**/
int getFinishTime(Patient *p);

/**Function that returns finishTime of the patient.
*@param pointer to a Patient struct
*@return finishTime int
**/
void setFinishTime(Patient *p, int finishTime);

/**Print Function for the patient
*@pre Data must be able to be printed via a standard print function
*@param toBePrinted pointer to the data that is to be printed. Taken from a data structure.
**/
void printPatient(void *data);

/**Function to delete linked list node based on the incoming data.
*@pre Data must not already be freed or NULL
*@param toBeDeleted Pointer to generic data to be deleted in the list.
**/
void deletePatient(void *data);

/**
*Comparison for two pointers to generic data. Must define an element of these pointers to use to compare
*the two pointers with each other.
*@pre first and second must be comparable.
*@param first pointer to data to be compared with second.
*@param second pointer to data to be compared with first.
*@return for sorting purposes,
*<0 The element pointed by 'first' goes before the element pointed by 'second'
*0  The element pointed by 'first' is equivalent to the element pointed by 'second'
*>0 The element pointed by 'first' goes after the element pointed by 'second'
**/
int comparePatient(const void *first, const void *second);


#endif