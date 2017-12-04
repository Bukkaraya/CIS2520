#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "binarySearchTreeAPI.h"
#include "rule.h"
#define MAX_LEN 400

void removeNewLine(char* str);
int getPositiveInt();
void displayRules(Tree* theTree);
void convertToLower(char *str);
void addNewRule(Tree* theTree);
void modifyRule(Tree* theTree);
void discuss(Tree* theTree);
void removeRule(Tree* theTree);


int main(int argc, char** argv){
    FILE* inputFile = NULL;
    char fileName[MAX_LEN];
    char fileValues[MAX_LEN];
    char secondValue[MAX_LEN];
    Tree *wordTree = createBinTree(compareRules, deleteRule);
    int userInput = 0;


    if(argc > 1){
        inputFile = fopen(argv[1], "r");
    }

    //If file file cannot be opened prompt the user
    while(inputFile == NULL){
        printf("Invalid file name, please try again.\n");
        fgets(fileName, MAX_LEN, stdin);
        removeNewLine(fileName);
        inputFile = fopen(fileName, "r");
    }

    printf("Successfully opened the file.\n");

    while(fgets(fileValues, MAX_LEN, inputFile)){
        fgets(secondValue, MAX_LEN, inputFile);
        removeNewLine(fileValues);
        removeNewLine(secondValue);
        convertToLower(fileValues);
        Rule* newRule = createRule(fileValues, secondValue, 0.5);
        addToTree(wordTree, newRule);
    }

    fclose(inputFile);


     //Start Main Loop
    while(userInput != 9){
        printf("Please enter your choice:\n");
        userInput = getPositiveInt();
        switch(userInput){
            case 1:
                addNewRule(wordTree);
                break;
            case 2:
                removeRule(wordTree);
                break;
            case 3:
                displayRules(wordTree);
                break;
            case 4:
                modifyRule(wordTree);
                break;
            case 5:
                discuss(wordTree);
                break;
            case 9:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid. Please try again.\n");
                break;
        }
    }

    destroyBinTree(wordTree);
    return 0;
}



void removeNewLine(char* str){
    if(str[strlen(str) - 1] == '\n'){
        str[strlen(str) - 1] = '\0';
    }
}


int getPositiveInt(){
    int userInt = 0;
    char userStr[MAX_LEN];

    while(userInt <= 0){
        fgets(userStr, MAX_LEN, stdin);
        removeNewLine(userStr);
        userInt = atoi(userStr);
        if(userInt <= 0){
            printf("Invalid. Please try again.\n");
        }
    }

    return userInt;
}


void displayRules(Tree* theTree){
    printInOrder(theTree, printRule);
}


void convertToLower(char *str){
    int i = 0;
    for(i = 0; i < strlen(str); i++){
        str[i] = tolower(str[i]);
    }
}


void addNewRule(Tree* theTree){
    char keyword[MAX_LEN];
    char response[MAX_LEN];
    double userRating = 0.0;

    printf("Please enter the name of the rule:\n");
    fgets(keyword, MAX_LEN, stdin);
    removeNewLine(keyword);
    convertToLower(keyword);

    printf("Please enter the response for the rule:\n");
    fgets(response, MAX_LEN, stdin);
    removeNewLine(response);

    printf("Please enter the user rating for the new rule:\n");
    scanf("%lf", &userRating);
    getchar();

    Rule *newRule = createRule(keyword, response, userRating);
    addToTree(theTree, newRule);

    printf("Rule (%s) has been added to the tree\n", keyword);
}


void modifyRule(Tree* theTree){
    char keyword[MAX_LEN];
    double newRating = 0.0;

    printf("Please enter the name of the rule/keyword:\n");
    fgets(keyword, MAX_LEN, stdin);
    removeNewLine(keyword);
    convertToLower(keyword);

    Rule* dummyRule = createRule(keyword, "response", 0.5);

    void* data = findInTree(theTree, dummyRule);

    deleteRule(dummyRule);

    if(data != NULL){
        Rule* matchedRule = (Rule *) data;
        printf("Rule (%s) has been found.\n", keyword);
        printf("Current user rating is: %.2lf\n", getUserRating(matchedRule));

        printf("Please enter the new rating:\n");
        scanf("%lf", &newRating);
        getchar();
        setUserRating(matchedRule, newRating);

        printf("The rating for the rule has been updated.\n");
    }else{
        printf("Rule with keyword - %s - not found.\n", keyword);
    }

}


void discuss(Tree* theTree){
    char userQuery[MAX_LEN];
    char* word = NULL;
    double tempRating = 0.0;
    double maxRating = 0.0;
    Rule *finalRule = NULL;

    printf("What would you like to talk about?\n");
    fgets(userQuery, MAX_LEN, stdin);
    removeNewLine(userQuery);
    convertToLower(userQuery);

    word = strtok(userQuery, " ?!-");
    while(word != NULL){
        Rule* tempRule = createRule(word, "response", 0.5);
        void *data = findInTree(theTree, tempRule);
        deleteRule(tempRule);


        if(data != NULL){
            Rule *matchedRule = (Rule *) data;
            tempRating = getUserRating(matchedRule) + getSystemRating(matchedRule);
            if(tempRating > maxRating){
                maxRating = tempRating;
                finalRule = matchedRule;
            }
        }

        word = strtok(NULL, " ?!-");
    }

    if(finalRule != NULL){
        printf("Personal Assistant: %s\n", getResponse(finalRule));
        increaseOccurences(finalRule);
        printf("Personal Assistant: Was this feedback helpful: ('y' for yes and 'n' for no)\n");

        fgets(userQuery, MAX_LEN, stdin);
        removeNewLine(userQuery);
        convertToLower(userQuery);

        if(strcmp(userQuery, "y") == 0){
            setSystemRating(finalRule, 1);
        }else if(strcmp(userQuery, "n") == 0){
            setSystemRating(finalRule, 0);
        }else{
            printf("Invalid input, please try again.\n");
        }

    }else{
        printf("Personal Assistant: Sorry, I don't have any information for your input.\n");
    }

}


void removeRule(Tree* theTree){
    char keyword[MAX_LEN];

    printf("Please enter the name of the rule you want to remove:\n");
    fgets(keyword, MAX_LEN, stdin);
    removeNewLine(keyword);
    convertToLower(keyword);


    Rule* dummyRule = createRule(keyword, "response", 0.5);

    void* data = findInTree(theTree, dummyRule);

    deleteRule(dummyRule);

    if(data != NULL){
        Rule* matchedRule = (Rule *) data;
        printf("Rule (%s) has been found.\n", keyword);
        removeFromTree(theTree, matchedRule);

        printf("The rule has been removed.\n");
    }else{
        printf("Rule with keyword - %s - not found.\n", keyword);
    }


}