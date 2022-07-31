#include <stdio.h>
#include <stdlib.h>
#include "danya.h"
#include "check.h"
void showDoc()
{
    if (!forest)
    {
        system("clear");
        printf("Files is not opened.\nPress ENTER to continue...");
        wait();
        return;
    }
    system("clear");
    int i;
    printf("----------------------------------------------------------------------------------------------------\n");
    printf("|%-5s|%-15s|%-30s|%-30s|%-15s|\n", "ID", "id Plot", "Name", "Rank", "Square");
    printf("----------------------------------------------------------------------------------------------------\n");
    for (i = 0; i < numLine; i++)
        if (forest[i].flag == 1)
            continue;
        else
            printf("|%-5d|%-15d|%-30s|%-30s|%-15d|\n", main_forest[i].id, main_forest[i].idPlace, main_forest[i].name, main_forest[i].rank, main_forest[i].square);
    printf("----------------------------------------------------------------------------------------------------\n");
    printf("\nPress ENTER to continue...");
    wait();
}
