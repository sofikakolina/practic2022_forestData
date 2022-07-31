#include "editFile.h"
#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "danya.h"
#include <string.h>

void showEditMenu()
{
    int ans;
    int i;
    const char menuItems[4][100] =
    {
        "1. Add a note",
        "2. Delete a note",
        "3. Edit an existing note",
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
            case 1: add(); break;
            case 2: del(); break;
            case 3: edit(); break;
            case 4: return;
            default: {
                        system("clear");
                        printf("There's no such menu item.\nPress ENTER to continue...");
                        wait();
                     }
         }
     }
}


void add()
{
    if (!main_forest)
    {
        system("clear");
        printf("File is not opened.\nPress ENTER to continue...");
        wait();
        return;
    }

    MAIN_FOREST *temp = NULL;
    int i;
    temp = (MAIN_FOREST *) malloc(sizeof(MAIN_FOREST) * numLine);
    for (i = 0; i < numLine; i++)
    {
        temp[i].id = main_forest[i].id;
        temp[i].idPlace = main_forest[i].idPlace;
        strcpy(temp[i].name,main_forest[i].name);
        strcpy(temp[i].rank, main_forest[i].rank);
        temp[i].square =main_forest[i].square;
        temp[i].flag = main_forest[i].flag;
    }
//    temp[numLine-1].id = main_forest[1].id;
//    temp[numLine-1].idPlace = main_forest[1].idPlace;
//    strcpy(temp[numLine-1].name,main_forest[1].name);
//    strcpy(temp[numLine-1].rank, main_forest[1].rank);
//    temp[numLine-1].square =main_forest[1].square;
//    temp[numLine-1].flag = main_forest[1].flag;
    free(main_forest);
    main_forest= NULL;
    numLine++;

    main_forest = (MAIN_FOREST*) malloc(sizeof(MAIN_FOREST) * numLine);
    for (i = 0; i < numLine-1; i++)
    {
        main_forest[i].id = temp[i].id;
        main_forest[i].idPlace = temp[i].idPlace;
        strcpy(main_forest[i].name,temp[i].name);
        strcpy(main_forest[i].rank,temp[i].rank);
        main_forest[i].square = temp[i].square;
        main_forest[i].flag = temp[i].flag;
    }
    free(temp);
    temp = NULL;

    //main_forest= (MAIN_FOREST*) malloc(sizeof(MAIN_FOREST) * numLine);

    main_forest[numLine-1].id = (main_forest[numLine-2].id + 1);

    system("clear");
    printf("Enter number plot: ");
    scanf("%d", &main_forest[numLine - 1].idPlace);
    clear();

    printf("Enter a name: ");
    fgets(main_forest[numLine - 1].name, 256, stdin);
    main_forest[numLine - 1].name[strcspn(main_forest[numLine - 1].name, "\n")] = '\0';


    printf("Enter a rank: ");
    fgets(main_forest[numLine - 1].rank, 256, stdin);
    main_forest[numLine - 1].rank[strcspn(main_forest[numLine - 1].rank, "\n")] = '\0';


    printf("Enter a square: ");
    scanf("%d", &main_forest[numLine - 1].square);
    clear();


    forest = (FOREST*) malloc(sizeof(FOREST) * numLine);
    name = (NAME*) malloc(sizeof(NAME) * numLine);
    rank= (RANK*) malloc(sizeof(RANK) * numLine);
    for (i = 0; i < numLine; i++)
        if (name[i].flag == 1)
            continue;
        else{
                    rank[i].id = main_forest[i].id;
                    strcpy(rank[i].rank, main_forest[i].name);
                    name[i].id = main_forest[i].id;
                    strcpy(name[i].name, main_forest[i].name);
                    forest[i].id=main_forest[i].id;
                    forest[i].idPlace=main_forest[i].idPlace;
                    forest[i].numName=main_forest[i].id;
                    forest[i].numRank=main_forest[i].id;
                    forest[i].square=main_forest[i].square;
                   }

    //system("clear");
    printf("Adding is successful.\nPress ENTER to continue...");
    wait();

}

void del()
{
    if (!main_forest)
    {
        system("clear");
        printf("File is not opened.\nPress ENTER to continue...");
        wait();
        return;
    }
    system("clear");
    printf("Enter an id to delete: ");
    int id;
    scanf("%d", &id);
    clear();
    int i;
    int match = 0;
    for (i = 0; i < numLine; i++)
        if (id == forest[i].id && forest[i].flag != 1)
        {
            match = 1;
            forest[i].flag = 1;
            main_forest[i].flag = 1;
            break;
        }
    if (!match)
    {
        system("clear");
        printf("That id doesn't exist.\nPress ENTER to continue...");
        wait();
        return;
    }


    system("clear");
    printf("Deleting is successful.\nPress ENTER to continue...");
    wait();
}

void edit()
{
    int match = 0;
    if (!main_forest)
    {
        system("clear");
        printf("File is not opened.\nPress ENTER to continue...");
        wait();
        return;
    }
    int id=0;
    system("clear");
    printf("Enter an id to edit: ");
    scanf("%d", &id);
    clear();
    int i=0;
    for (i=0;i<numLine;i++){
        if (id == main_forest[i].id)
        {
            system("clear");
            printf("Enter number plot: ");
            scanf("%d", &main_forest[i].idPlace);
            clear();

            printf("Enter a name: ");
            fgets(main_forest[i].name, 256, stdin);
            main_forest[i].name[strcspn(main_forest[i].name, "\n")] = '\0';


            printf("Enter a rank: ");
            fgets(main_forest[i].rank, 256, stdin);
            main_forest[i].rank[strcspn(main_forest[i].rank, "\n")] = '\0';


            printf("Enter a square: ");
            scanf("%d", &main_forest[i].square);
            clear();
            match =1;
        }
    }
    forest = (FOREST*) malloc(sizeof(FOREST) * numLine);
    name = (NAME*) malloc(sizeof(NAME) * numLine);
    rank= (RANK*) malloc(sizeof(RANK) * numLine);
    for (int i = 0; i < numName; i++)
        if (name[i].flag == 1)
            continue;
        else{
                    rank[i].id = main_forest[i].id;
                    strcpy(rank[i].rank, main_forest[i].name);

                    name[i].id = main_forest[i].id;
                    strcpy(name[i].name, main_forest[i].name);

                    forest[i].id=main_forest[i].id;
                    forest[i].idPlace=main_forest[i].idPlace;
                    forest[i].numName=main_forest[i].id;
                    forest[i].numRank=main_forest[i].id;
                    forest[i].square=main_forest[i].square;
                   }

    system("clear");
    if (match) printf("Editing is successful.\nPress ENTER to continue...");
    else printf("Id not found!\nPress ENTER to continue...");
    wait();
}
