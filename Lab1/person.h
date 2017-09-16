typedef struct Person{
    int age;
    char name[30];
} Person;

void printPerson(Person *p);
void addBirthday(Person *p);
int compareAges(const Person *a, const Person *b);