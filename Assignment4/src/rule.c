#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rule.h"


Rule* createRule(char* keyword, char* response, double userRating){
    Rule* rule = malloc(sizeof(Rule));
    
    rule->keyword = malloc(sizeof(char)*strlen(keyword) + 1);
    strncpy(rule->keyword, keyword, strlen(keyword) + 1);

    rule->response = malloc(sizeof(char)*strlen(response) + 1);
    strncpy(rule->response, response, strlen(response) + 1);

    rule->systemRating = userRating;
    rule->userRating = userRating;

    rule->occurences = 0;
    rule->learningRate = 0.05;

    return rule;
}


char* getKeyword(Rule* rule){
    if(rule){
        return rule->keyword;
    }
}


char* getResponse(Rule* rule){
    if(rule){
        return rule->response;
    }
}


double getUserRating(Rule* rule){
    if(rule){
        return rule->userRating;
    }
}


double getSystemRating(Rule* rule){
    if(rule){
        return rule->systemRating;
    }
}


double getLearningRate(Rule* rule){
    if(rule){
        return rule->learningRate;
    }
}


int getOccurences(Rule* rule){
    if(rule){
        return rule->occurences;
    }
}


void setUserRating(Rule* rule, double newRating){
    rule->userRating = newRating;
}


void setSystemRating(Rule* rule, int option){
    double temp = 0.0;

    if(option == 0){
        temp = rule->systemRating - (rule->systemRating*rule->learningRate/rule->occurences);
    }else if(option == 1){
        temp = rule->systemRating + (rule->systemRating*rule->learningRate/rule->occurences);
    }

    if(temp > 0.99){
        rule->systemRating = 0.98;
    }else if(temp < 0.10){
        rule->systemRating = 0.10;
    }else{
        rule->systemRating = temp;
    }
}


void increaseOccurences(Rule* rule){
    rule->occurences++;
}


int compareRules(const void* a, const void* b){
    Rule *r1 = (Rule *) a;
    Rule *r2 = (Rule *) b;

    if(strcmp(r1->keyword, r2->keyword) > 0){
        return 1;
    }else if(strcmp(r1->keyword, r2->keyword) < 0){
        return -1;
    }else{
        return 0;
    }
}


void printRule(void* data){
    Rule *r = (Rule *) data;

    printf("%s\t\tRating: %g\tSystem: %g\tOccurences: %d\n", r->keyword, r->userRating, r->systemRating, r->occurences);
}


void deleteRule(void* data){
    if(data != NULL){
        Rule *r = (Rule *) data;
        free(r->keyword);
        free(r->response);
        free(r);
    }
}