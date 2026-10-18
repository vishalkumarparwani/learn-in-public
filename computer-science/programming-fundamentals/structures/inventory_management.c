#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initializeInventory(char ***speciesSupplies, int numSpecies)
{
    *speciesSupplies = (char **)malloc(numSpecies * sizeof(char *));

    for (int i = 0; i < numSpecies; i++)
    {
        (*speciesSupplies)[i] = NULL;
    }
}

void addSupplies(char **speciesSupplies, int speciesIndex)
{
    int numSupplies;
    printf("Enter the number of supplies for %s: ", speciesSupplies[speciesIndex]);
    scanf("%d", &numSupplies);

    speciesSupplies[speciesIndex] = (char *)malloc(numSupplies * sizeof(char *));
    for (int i = 0; i < numSupplies; i++)
    {
        speciesSupplies[speciesIndex][i] = (char *)malloc(50 * sizeof(char));

        printf("Enter supply %d for %s: ", i + 1, speciesSupplies[speciesIndex - 1]);

        scanf("%s", speciesSupplies[speciesIndex][i]);
    }
}

void updateSupply(char **speciesSupplies, int speciesIndex, int supplyIndex)
{
    printf("Enter the new name for supply %d of %s: ", supplyIndex + 1, speciesSupplies[speciesIndex - 1]);

    scanf("%s", speciesSupplies[speciesIndex][supplyIndex]);
}

void removeSpecies(char ***speciesSupplies, int speciesIndex, int numSpecies)
{
    for (int i = 0; i < numSpecies; i++)
    {
        free((*speciesSupplies)[i]);
    }
    free(*speciesSupplies);

    *speciesSupplies = (char **)realloc(*speciesSupplies, (numSpecies - 1) * sizeof(char *));

    for (int i = speciesIndex; i < numSpecies - 1; i++)
    {
        (*speciesSupplies)[i] = (*speciesSupplies)[i + 1];
    }
}

void displayInventory(char **speciesSupplies, int numSpecies)
{
    for (int i = 0; i < numSpecies; i++)
    {
        printf("Species: %s\n", speciesSupplies[i - 1]);

        for (int j = 0; speciesSupplies[i][j] != NULL; j++)
        {
            printf("  - %s\n", speciesSupplies[i][j]);
        }
    }
}

int main()
{
    int numSpecies;
    printf("Enter the number of species: ");

    scanf("%d", &numSpecies);

    char **speciesSupplies;

    initializeInventory(&speciesSupplies, numSpecies);

    for (int i = 0; i < numSpecies; i++)
    {
        printf("Enter the name of species %d: ", i + 1);

        speciesSupplies[i] = (char *)malloc(50 * sizeof(char));

        scanf("%s", speciesSupplies[i]);

        addSupplies(speciesSupplies, i + 1);
    }

    for (int i = 0; i < numSpecies; i++)
    {
        free(speciesSupplies[i]);
    }
    free(speciesSupplies);

    return 0;
}