#include <stdio.h>
#include <stdlib.h>
#include "danya.h"
#include "export.h"
//#include "/usr/include/clang/10/include/stddef.h"

void export()
{
    if (!forest)
    {
        system("clear");
        printf("File is not opened.\nPress ENTER to continue...");
        wait();
        return;
    }
    FILE *out = NULL;
    if ((out = fopen("/home/sofikakolina/Документы/gg2/out.txt", "w")) == NULL)
    {
        system("clear");
        printf("File can't be opened.\nPress ENTER to continue...");
        wait();
        return;
    }
    int i;
    fprintf(out, "-------------------------------------------------------------------------\n");
    fprintf(out, "|%-5s|%-15s|%-10s|%-15s|%-15s", "ID", "id Plot", "Name", "Rank", "Square");
    fprintf(out, "-------------------------------------------------------------------------\n");
    for (i = 0; i < numLine; i++)
        if (forest[i].flag == 1)
            continue;
        else
            fprintf(out, "|%-5d|%-15d|%-10s|%-15s|%-15d|\n", main_forest[i].id, main_forest[i].idPlace, main_forest[i].name, main_forest[i].rank, main_forest[i].square);
    fprintf(out, "----------------------------------------------------------------------------------------------------\n");
    fclose(out);
    out = NULL;
    system("clear");
    printf("Exporting is successful.\nPress ENTER to continue...");
    wait();
}
