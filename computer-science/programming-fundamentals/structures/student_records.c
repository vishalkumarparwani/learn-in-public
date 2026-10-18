#include <stdio.h>
#include <string.h>
struct date
{
    int day;
    char month[15];
    int year;
};
struct student
{
    char name[25];
    float marks;
    int batch;
    char city[25];
    int rollNumber;
    struct date birthday;
};

int main()
{
    struct student sectionK[5];
    char choice = 'y';
    int count = 0;
    for (int i = 0; i < 5; i++)
    {
        printf("Enter your name\n");
        scanf(" %s", sectionK[i].name);
        getchar();
        printf("Enter your marks\n");
        scanf(" %f", &sectionK[i].marks);
        getchar();
        printf("Enter your batch\n");
        scanf(" %d", &sectionK[i].batch);
        getchar();
        printf("Enter your city\n");
        scanf(" %s", sectionK[i].city);
        getchar();
        printf("Enter your rollNumber\n");
        scanf(" %d", &sectionK[i].rollNumber);
        getchar();
        printf("Enter day\n");
        scanf(" %d", &sectionK[i].birthday.day);
        getchar();
        printf("Enter month\n");
        scanf(" %s", &sectionK[i].birthday.month);
        getchar();
        printf("Enter year\n");
        scanf(" %d", &sectionK[i].birthday.year);

        printf("Continue? (y/n): ");
        scanf(" %c", &choice);
        count++;

        if (choice != 'y')
        {
            break;
        }
    }

    for (int i = 0; i < count; i++)
    {

        printf("\nYour name is: %s\n", sectionK[i].name);
        printf("Your marks: %.2f\n", sectionK[i].marks);
        printf("Your batch: %d\n", sectionK[i].batch);
        printf("Your city: %s\n", sectionK[i].city);
        printf("Your rollNumber: %d\n", sectionK[i].rollNumber);
        printf("Day: %d\n", sectionK[i].birthday.day);
        printf("Month: %s\n", sectionK[i].birthday.month);
        printf("Year: %d\n", sectionK[i].birthday.year);
    }

    return 0;
}