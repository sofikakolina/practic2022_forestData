#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "danya.h"
FOREST *forest= NULL;
NAME *name= NULL;
RANK *rank= NULL;
MAIN_FOREST *main_forest = NULL;
int numName = 0;
int numLine = 0;
void clear()
{
    while (getchar() != '\n');
}

void wait()
{
    char keyPressed = 0;
    while (scanf("%c", &keyPressed) == 1 && keyPressed != '\n');
}
void showFileMenu()
{
    int ans;
    int i;
    const char menuItems[4][100] =
    {
        "1. Open File",
        "2. Save File",
        "3. Close File",
        "4. To the main menu"
    };

    while(1)
    {
        system("clear");
        for (i = 0; i < 4; i++)
            printf("%s\n", menuItems[i]);
        printf("\nEnter a menu item: ");
        scanf("%d", &ans);
        clear();
        switch(ans)
        {
            case 1: open(); break;
            case 2: save(); break;
            case 3: close(); break;
            case 4: return;
            default: {
                        system("clear");
                        printf("There's no such menu item.\nPress ENTER to continue...");
                        wait();
                     }
         }
     }
}

void open()
{
    if (!forest)
    {
        FILE *in = NULL;
        if ((in = fopen("/home/sofikakolina/Документы/gg2/forest.db", "r")) == NULL)
        {
            system("clear");
            printf("File can't be opened.\nPress ENTER to continue...");
            wait();
            return;
        }

        if (!name)
        {
            FILE *fname = NULL;
            int i;
            if ((fname = fopen("/home/sofikakolina/Документы/gg2/name.db", "r")) == NULL)
            {
                system("clear");
                printf("File can't be opened.\nPress ENTER to continue...");
                wait();
                return;
            }
            if (!numName)
            {
                while (!feof(fname))
                    if (fgetc(fname) == '\n')
                        numName++;
                rewind(fname);
            }
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
        if (!rank)
        {
            FILE *frank= NULL;
            int i;
            if ((frank = fopen("/home/sofikakolina/Документы/gg2/rank.db", "r")) == NULL)
            {
                system("clear");
                printf("File can't be opened.\nPress ENTER to continue...");
                wait();
                return;
            }

            rank = (RANK *) malloc(sizeof(RANK) * numName);
            for (i = 0; i < numName; i++)
            {
                char temp[256];
                fgets(temp, 256, frank);
                rank[i].id = atoi(strtok(temp, ";"));
                strcpy(rank[i].rank, strtok(NULL, ";"));
            }
            fclose(frank);
            frank = NULL;
        }

        if (!numLine)
        {
            while (!feof(in))
                if (fgetc(in) == '\n')
                    numLine++;
            rewind(in);
        }
        int i;

        forest = (FOREST*) malloc(sizeof(FOREST) * numLine);
        for (i = 0; i < numLine; i++)
        {
            char temp[256];
            fgets(temp, 256, in);
            forest[i].id = atoi(strtok(temp, ";"));
            forest[i].idPlace = atoi(strtok(NULL, ";"));
            forest[i].numName= atoi(strtok(NULL, ";"));
            forest[i].numRank= atoi(strtok(NULL, ";"));
            forest[i].square= atoi(strtok(NULL, ";"));
        }

        fclose(in);
        in = NULL;
        int j;
        main_forest = (MAIN_FOREST*) malloc(sizeof(MAIN_FOREST) * numLine);
        for (i = 0; i < numLine; i++)
        {
            int match = 0;
            main_forest[i].id = forest[i].id;
            main_forest[i].idPlace = forest[i].idPlace;
            for (j = 0; j < numName; j++)
                if (forest[i].id == rank[j].id)
                {
                    match = 1;
                    strcpy(main_forest[i].name, name[j].name);
                    break;
                }
            if (!match)
            {
                system("clear");
                printf("ID doesn't exist.\nPress ENTER to continue...");
                wait();
                return;
            }
            match = 0;
            for (j = 0; j < numName; j++)
                if (forest[i].id == rank[j].id)
                {
                    match = 1;
                    strcpy(main_forest[i].rank, rank[j].rank);
                    break;
                }
            if (!match)
            {
                system("clear");
                printf("ID doesn't exist.\nPress ENTER to continue...");
                wait();
                return;
            }
            match = 0;
            main_forest[i].square=forest[i].square;

        }
        system("clear");
        printf("File is successfuly opened.\nPress ENTER to continue...");
        wait();
    }
    else
    {
        system("clear");
        printf("File is already opened.\nPress ENTER to continue...");
        wait();
        return;
    }
}

void close()
{
    if (main_forest)
    {
        free(main_forest);
        main_forest = NULL;
        numLine = 0;
    }
    if (forest)
    {
        free(forest);
        forest = NULL;
        numLine = 0;
    }
    if (name && rank)
    {
        free(rank);
        rank= NULL;
        free(name);
        name = NULL;
        numName = 0;
    }
    system("clear");
    printf("The file is successfuly closed.\nPress ENTER to continue...");
    wait();
}

void save()
{
    if (!main_forest|| !name || !rank)
        {
            system("clear");
            printf("File is not opened.\nPress ENTER to continue...");
            wait();
            return;
        }
        int i;
        FILE *fname = NULL;
        if ((fname = fopen("/home/sofikakolina/Документы/gg2/name.db", "w")) == NULL)
        {
            system("clear");
            printf("File can't be opened.\nPress ENTER to continue...");
            wait();
            return;
        }
        for (i = 0; i < numLine; i++)
            if (name[i].flag == 1)
                continue;
            else
                fprintf(fname, "%d;%s;\n", main_forest[i].id, main_forest[i].name);
        fclose(fname);
        fname = NULL;

        FILE *frank= NULL;
        if ((fname = fopen("/home/sofikakolina/Документы/gg2/rank.db", "w")) == NULL)
        {
            system("clear");
            printf("File can't be opened.\nPress ENTER to continue...");
            wait();
            return;
        }
        for (i = 0; i < numLine; i++)
            if (name[i].flag == 1)
                continue;
            else
                fprintf(fname, "%d;%s;\n", main_forest[i].id, main_forest[i].rank);
        fclose(fname);
        fname = NULL;

        FILE *in = NULL;
        if ((in = fopen("/home/sofikakolina/Документы/gg2/forest.db", "w")) == NULL)
        {
            system("clear");
            printf("File can't be opened.\nPress ENTER to continue...");
            wait();
            return;
        }
        for (i = 0; i < numLine; i++)
            if (forest[i].flag == 1)
                continue;
            else
                fprintf(in, "%d;%d;%d;%d;%d;\n", forest[i].id, forest[i].idPlace, forest[i].id, forest[i].id, forest[i].square);
        fclose(in);
        in = NULL;
        system("clear");
        printf("Saving is successful.\nPress ENTER to continue...");
        wait();
}
