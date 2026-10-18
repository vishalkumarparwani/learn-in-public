#include <stdio.h>
#include <stdlib.h>

struct Employee
{
    int *ratings;
    int totalScore;
};
void inputEmployees(int **ratings, int numEmployees, int numPeriods)
{
    for (int i = 0; i < numEmployees; i++)
    {
        ratings[i] = (int *)malloc(numPeriods * sizeof(int));
        for (int j = 0; j < numPeriods; j++)
        {
            do
            {
                printf("Enter the rating for employee %d, period %d (1-10): ", i + 1, j + 1);
                scanf("%d", &ratings[i][j]);
            } while (ratings[i][j] < 1 || ratings[i][j] > 10);
        }
    }
}
void displayPerformance(int **ratings, int numEmployees, int numPeriods)
{
    for (int i = 0; i < numEmployees; i++)
    {
        printf("Employee %d: ", i + 1);
        for (int j = 0; j < numPeriods; j++)
        {
            printf("%d ", ratings[i][j]);
        }
        printf("\n");
    }
}

int findEmployeeOfTheYear(int **ratings, int numEmployees, int numPeriods)
{
    int maxAvg = 0, maxIndex = 0;
    for (int i = 0; i < numEmployees; i++)
    {
        int sum = 0;
        for (int j = 0; j < numPeriods; j++)
        {
            sum += ratings[i][j];
        }
        int avg = sum / numPeriods;
        if (avg > maxAvg)
        {
            maxAvg = avg;
            maxIndex = i;
        }
    }
    return maxIndex;
}

int findHighestRatedPeriod(int **ratings, int numEmployees, int numPeriods)
{
    int maxAvg = 0, maxPeriod = 0;
    for (int i = 0; i < numPeriods; i++)
    {
        int sum = 0;
        for (int j = 0; j < numEmployees; j++)
        {
            sum += ratings[j][i];
        }
        int avg = sum / numEmployees;
        if (avg > maxAvg)
        {
            maxAvg = avg;
            maxPeriod = i;
        }
    }
    return maxPeriod;
}

int findWorstPerformingEmployee(int **ratings, int numEmployees, int numPeriods)
{
    int minAvg = 10, minIndex = 0;
    for (int i = 0; i < numEmployees; i++)
    {
        int sum = 0;
        for (int j = 0; j < numPeriods; j++)
        {
            sum += ratings[i][j];
        }
        int avg = sum / numPeriods;
        if (avg < minAvg)
        {
            minAvg = avg;
            minIndex = i;
        }
    }
    return minIndex;
}

int main()
{
    int numEmployees, numPeriods;

    printf("Enter the number of employees: ");
    scanf("%d", &numEmployees);
    printf("Enter the number of evaluation periods: ");
    scanf("%d", &numPeriods);

    int **ratings = (int **)malloc(numEmployees * sizeof(int *));

    inputEmployees(ratings, numEmployees, numPeriods);

    displayPerformance(ratings, numEmployees, numPeriods);

    int employeeOfTheYear = findEmployeeOfTheYear(ratings, numEmployees, numPeriods);
    printf("Employee of the Year: %d\n", employeeOfTheYear + 1);

    int highestRatedPeriod = findHighestRatedPeriod(ratings, numEmployees, numPeriods);
    printf("Highest Rated Period: %d\n", highestRatedPeriod + 1);

    int worstPerformingEmployee = findWorstPerformingEmployee(ratings, numEmployees, numPeriods);
    printf("Worst Performing Employee: %d\n", worstPerformingEmployee + 1);

    for (int i = 0; i < numEmployees; i++)
    {
        free(ratings[i]);
    }
    free(ratings);

    return 0;
}