typedef struct rule{
    char* keyword;
    char* response;
    double userRating;
    double systemRating;
    int occurences;
    double learningRate;
} Rule;


Rule* createRule(char* keyword, char* response, double userRating);

char* getKeyword(Rule* rule);

char* getResponse(Rule* rule);

double getUserRating(Rule* rule);

double getSystemRating(Rule* rule);

int getOccurences(Rule* rule);

double getLearningRate(Rule* rule);

void increaseOccurences(Rule* rule);

void setUserRating(Rule* rule, double newRating);

void setSystemRating(Rule* rule, int option);

void printRule(void* data);

int compareRules(const void* a, const void* b);

void deleteRule(void* data);