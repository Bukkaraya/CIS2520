#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "priorityQueue.h"
#include "patient.h"
#define MAX_LEN 100

void removeNewLine(char* str);
int strEmpty(char* str);
int getTreatmentTime(char *sym);
void getString(char *prompt, char* str);
int getPositiveInt();
void runHospitalSimulator(PriorityQueue *q);
void printHyphens(int num);


//Changes to make
//Write tests
//Add starvation algorithm in a new file, probably going to change update priorities based on time (buffer time of 15 seconds or so)


int main(int argc, char **argv){
    
    FILE* inputFile = NULL;
    char fileName[MAX_LEN];
    char fileValues[MAX_LEN];
    char patientID[MAX_LEN];
    char symptom[MAX_LEN];
    int priority = 0;
    List *outList = initializeList(printPatient, deletePatient, comparePatient);
    PriorityQueue *patients = createQueue(printPatient, deletePatient, comparePatient);
    int userChoice = 0;


    if(argc > 1){
        inputFile = fopen(argv[1], "r");
    }

    //Prompt User
    while(inputFile == NULL){
        printf("Invalid file name, please try again.\n");
        fgets(fileName, MAX_LEN, stdin);
        removeNewLine(fileName);
        inputFile = fopen(fileName, "r");
    }

    printf("Successfully opened the file.\n");

    //Get data from file and store in data structures
    while(fgets(fileValues, MAX_LEN, inputFile)){
        removeNewLine(fileValues);
        sscanf(fileValues, "%s %d %s", patientID, &priority, symptom);
        //Disregard Empty Lines
        if(!strEmpty(fileValues)){
            Patient *pat = createPatient(patientID, symptom, priority);
            insertFront(outList, pat);
            insert(patients, pat, priority);
        }
    }
    //Closing the file
    fclose(inputFile);
    inputFile = NULL;

    printHyphens(90);
    printf("Enter 1 to add a patient.\n");
    printf("Enter 2 to run simulation and exit.\n");
    printf("Enter 3 to exit program.\n");
    printHyphens(90);

    //Prompt user
    while(userChoice != 3){
        printf("Please enter your choice:\n");
        userChoice = getPositiveInt();
        if(userChoice == 1){
            getString("Enter the patient ID:", patientID);
            printf("Enter the patient priority:\n");
            priority = getPositiveInt();
            getString("Enter the patient's symptom:", symptom);
            
            Patient * newPatient = createPatient(patientID, symptom, priority);
            insertFront(outList, newPatient);
            insert(patients, newPatient, priority);
        }else if(userChoice == 2){
            runHospitalSimulator(patients);
            
            printf("Patient ID\t\t|Priority\t\t|Symptom Code\t\t|TimeFinished\n");
            printHyphens(90);
            printBackwards(outList);

            getchar();
            printf("GoodBye!\n");
            break;
        }else if(userChoice == 3){
            printf("GoodBye!\n");
        }else{
            printf("Improper input try again.\n");
        }
    }

    destroyQueue(patients);
    deleteList(outList);

    return 0;
}




void removeNewLine(char *str){
    if(str[strlen(str) - 1] == '\n'){
        str[strlen(str) - 1] = '\0';
    }
}


int strEmpty(char *str){
    if(str[0] == '\0'){
        return 1;
    }

    return 0;
}


int getTreatmentTime(char *sym){

    if(strcmp(sym, "CV") == 0){
        return 5;
    }else if(strcmp(sym, "HN") == 0){
        return 3;
    }else if(strcmp(sym, "EV") == 0){
        return 10;
    }else if(strcmp(sym, "GI") == 0){
        return 2;
    }else if(strcmp(sym, "MH") == 0){
        return 5;
    }else if(strcmp(sym, "NC") == 0){
        return 5;
    }else if(strcmp(sym, "EC") == 0){
        return 1;
    }else if(strcmp(sym, "RC") == 0){
        return 1;
    }else if(strcmp(sym, "SK") == 0){
        return 2;
    }else if(strcmp(sym, "SA") == 0){
        return 7;
    }else if(strcmp(sym, "TR") == 0){
        return 4;
    }

    return 0;
}


void getString(char *prompt, char *str){
    char userStr[MAX_LEN] = "";
    while(strcmp(userStr, "") == 0){
        printf("%s\n", prompt);
        fgets(userStr, MAX_LEN, stdin);
        removeNewLine(userStr);
        if(strcmp(userStr, "") == 0){
            printf("Cannot enter an empty string. Please try again.");
        }
    }
    strcpy(str, userStr);
}


int getPositiveInt(){
    int userInt = 0;
    char userStr[MAX_LEN];

    while(userInt <= 0){
        fgets(userStr, MAX_LEN, stdin);
        removeNewLine(userStr);
        userInt = atoi(userStr);
        if(userInt <= 0){
            printf("Invalid. Please try again.");
        }
    }

    return userInt;
}


void runHospitalSimulator(PriorityQueue *patients){
    int simTimer = 1;
    int treatmentTime = 0;
    while(!queueEmpty(patients)){
        Patient *curPat = peek(patients);
        treatmentTime = getTreatmentTime(getSymptom(curPat));
        setFinishTime(curPat, simTimer + treatmentTime);
        pop(patients);
        simTimer += treatmentTime + 1;
    }
}


void printHyphens(int num){
    int i = 0;

    for(i = 0; i < num; i++){
        printf("-");
    }
    printf("\n");
}