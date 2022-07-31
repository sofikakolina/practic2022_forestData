#include "checkhelperfile.h"
#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "danya.h"
#include "string.h"

char selectedDict[256];

void showDictMenu()
{
    int ans;
    int i;
    const char menuItems[3][100] =
    {
        "1. Select a directory",
        "2. Display the directory",
        "3. To the main menu"
    };

    while(1)
    {
        system("clear");
        for (i = 0; i < 3; i++)
            printf("%s\n", menuItems[i]);
        printf("\nEnter a menu item: ");
        scanf("%d", &ans);
        clear();
        switch(ans)
        {
            case 1: selectDict(); break;
            case 2: showDict(); break;
            case 3: return;
            default: {
                        system("clear");
                        printf("There's no such menu item.\nPress ENTER to continue...");
                        wait();
                     }
         }
     }
}

void selectDict()
{
    if (!rank && !name)
    {
        FILE *fname = NULL;
        FILE *frank= NULL;
        if ((fname = fopen("/home/sofikakolina/Документы/gg2/name.db", "r")) == NULL)
        {
            system("clear");
            printf("File can't be opened.\nPress ENTER to continue...");
            wait();
            return;
        }
        if ((frank= fopen("/home/sofikakolina/Документы/gg2/rank.db", "r")) == NULL)
        {
            system("clear");
            printf("File can't be opened.\nPress ENTER to continue...");
            wait();
            return;
        }
        if (!numName)
        {
            while (!feof(frank))
                if (fgetc(frank) == '\n')
                    numName++;
            rewind(frank);
        }
        if (!numName)
        {
            while (!feof(fname))
                if (fgetc(fname) == '\n')
                    numName++;
            rewind(fname);
        }
        int i;
        rank = (RANK*) malloc(sizeof(RANK) * numName);
        for (i = 0; i < numName; i++)
        {
            char temp[256];
            fgets(temp, 256, frank);
            rank[i].id = atoi(strtok(temp, ";"));
            strcpy(rank[i].rank, strtok(NULL, ";"));
        }
        fclose(frank);
        frank = NULL;
        name = (NAME *) malloc(sizeof(NAME) * numName);
        for (i = 0; i < numName; i++)
        {
            char temp[256];
            fgets(temp, 256, fname);
            name[i].id = atoi(strtok(temp, ";"));
            strcpy(name[i].name, strtok(NULL, ";"));
        }
        fclose(fname);
        fname = NULL;
    }
    system("clear");
    printf("1. rank.db\n2. name.db\n\nEnter a file number: ");
    int ans;
    scanf("%d", &ans);
    clear();
    switch(ans)
    {
    case 1: strcpy(selectedDict, "/home/sofikakolina/Документы/gg2/rank.db\0"); break;
    case 2: strcpy(selectedDict, "/home/sofikakolina/Документы/gg2/name.db\0"); break;
    default: {
                system("clear");
                printf("There's no such menu item.\nPress ENTER to continue...");
                wait();
             }
    }
    printf("\nThe selected directory is %s\nPress ENTER to continue...", selectedDict);
    wait();
}

void showDict()
{
    if (strcmp(selectedDict, "/home/sofikakolina/Документы/gg2/rank.db\0") == 0)
    {
        system("clear");
        int i;
        for (i = 0; i < numName; i++)
            if (name[i].flag == 1)
                continue;
            else
                printf("%-5d%-10s\n", rank[i].id, rank[i].rank);
        printf("\nPress ENTER to continue...");
        wait();
        return;
    }
    if (strcmp(selectedDict, "/home/sofikakolina/Документы/gg2/name.db\0") == 0)
    {
        system("clear");
        int i;
        for (i = 0; i < numName; i++)
            if (name[i].flag == 1)
                continue;
            else
                printf("%-5d%-10s\n", name[i].id, name[i].name);
        printf("\nPress ENTER to continue...");
        wait();
        return;
    }
    system("clear");
    printf("Directory is not selected.\nPress ENTER to continue...");
    wait();
    return;
}
