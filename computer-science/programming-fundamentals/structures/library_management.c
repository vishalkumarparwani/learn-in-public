#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STRING_LENGTH 100

struct management
{
    int id;
    char *title;
    char *artist;
    char *genre;
    int no_tracks;
};

int main()
{
    struct management CD[50];
    int count = 0;

    for (int i = 0; i < MAX_STRING_LENGTH; i++)
    {
        CD[i].title = (char *)malloc(MAX_STRING_LENGTH * sizeof(char));
        CD[i].artist = (char *)malloc(MAX_STRING_LENGTH * sizeof(char));
        CD[i].genre = (char *)malloc(MAX_STRING_LENGTH * sizeof(char));

        if (CD[i].title == NULL || CD[i].artist == NULL || CD[i].genre == NULL)
        {
            printf("DMA has failed!\n");
            return 1;
        }
    }

    char choice = 'y';

    for (int i = 0; choice == 'y' && i < 50; i++)
    {
        printf("\nEnter the ID of the CD: ");
        scanf("%d", &CD[i].id);
        printf("\nEnter the title of the CD: ");
        scanf("%s", CD[i].title);
        printf("\nEnter the artist name of the CD:");
        scanf("%s", CD[i].artist);
        printf("\nEnter the genre of the CD: ");
        scanf("%s", CD[i].genre);
        printf("\nEnter the number of tracks in the CD: ");
        scanf("%d", &CD[i].no_tracks);
        count++;

        printf("Do you want to add more details? (y/n): ");
        scanf(" %c", &choice);

        if (choice != 'y')
        {
            break;
        }
    }

    printf("\nSelect an option:\n\n1.Delete a CD\n2.Search for a CD\n3.Update CD details\n");
    int option;
    scanf("%d", &option);
    int found = 0;
    if (option == 1)
    {
        printf("Enter the ID of the CD you want to delete: ");
        int id_search;
        scanf("%d", &id_search);
        for (int i = 0; i < count; i++)
        {
            if (id_search == CD[i].id)
            {
                found = 1;
                CD[i].id = 0;
                CD[i].title = NULL;
                CD[i].artist = NULL;
                CD[i].genre = NULL;
                CD[i].no_tracks = 0;

                printf("\nDeletion successful!\n");
                return 0;
            }
            if (!found)
            {
                printf("\nDeletion failed!\n");
                return 1;
            }
        }
    }

    char title_search[15];
    char artist_search[15];

    if (option == 2)
    {
        printf("\nEnter title and artist name to search a CD: ");
        scanf("%s %s", title_search, artist_search);
        for (int i = 0; i < count; i++)
        {
            if (strcmp(title_search, CD[i].title) == 0 && strcmp(artist_search, CD[i].artist) == 0)
            {
                printf("\nSearch found!");

                printf("\nID: %d", CD[i].id);
                printf("\nTitle: %s", CD[i].title);
                printf("\nArtist: %s", CD[i].artist);
                printf("\nGenre: %s", CD[i].genre);
                printf("\nNumber of tracks: %d", CD[i].no_tracks);

                printf("Wanter to seach another CD? (y/n)");
                char ch = 'y';
                scanf(" %c", &ch);

                if (ch != 'y')
                {
                    break;
                }
            }
        }
    }

    int id_update;
    int tracks_update;
    char genre_update[15];
    int update_option;
    if (option == 3)
    {
        printf("\nEnter ID to update a CD: ");
        scanf("%d", &id_update);

        for (int i = 0; i < count - 1; i++)
        {
            if (id_update == CD[i].id)
            {
                printf("\nSelect an option to change:\n\n1.Title\n2.Artist name\n3.Genere\n4.No of Tracks\n");
                scanf("%d", &update_option);

                if (update_option == 1)
                {
                    printf("\nEnter new title: ");
                    scanf("%s", title_search);

                    strcpy(CD[i].title, title_search);
                }
                if (update_option == 2)
                {
                    printf("\nEnter new Artist name: ");
                    scanf("%s", title_search);

                    strcpy(CD[i].artist, artist_search);
                }
                if (update_option == 3)
                {
                    printf("\nEnter new genre: ");
                    scanf("%s", genre_update);

                    strcpy(CD[i].genre, genre_update);
                }
                if (update_option == 4)
                {
                    printf("\nEnter new tracks number: ");
                    scanf("%d", &tracks_update);

                    CD[i].no_tracks = tracks_update;
                }
                else
                {
                    return 1;
                }
            }
            printf("\nDo you want to update another CD? (y/n): ");
            scanf(" %c", &choice);

            if (choice != 'y')
            {
                break;
            }
        }
    }
    else
    {
        return 1;
    }

    printf("\nWhich sorting do you want?\n");
    printf("\n1.Sorting by title");
    printf("\n2.Sorting by artist's name");
    printf("\n3.Sorting by number of tracks");
    scanf("%d", &option);

    struct management temp;

    if (option == 1)
    {
        for (int i = 0; i < count; i++)
        {
            if (strcmp(CD[i].title, CD[i + 1].title) > 0)
            {
                temp = CD[i];
                CD[i] = CD[i + 1];
                CD[i + 1] = temp;
            }
        }
    }
    if (option == 2)
    {
        for (int i = 0; i < count; i++)
        {
            if (strcmp(CD[i].artist, CD[i + 1].artist) > 0)
            {
                temp = CD[i];
                CD[i] = CD[i + 1];
                CD[i + 1] = temp;
            }
        }
    }
    if (option == 3)
    {
        for (int i = 0; i < count; i++)
        {
            if (CD[i].no_tracks > CD[i + 1].no_tracks)
            {
                temp = CD[i];
                CD[i] = CD[i + 1];
                CD[i + 1] = temp;
            }
        }
    }

    return 0;
}