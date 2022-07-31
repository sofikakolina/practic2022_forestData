#include <stdio.h>
#include<stdlib.h>
#include "danya.h"
#include "editFile.h"
#include "check.h"
#include "aboutMe.h"
#include "export.h"
#include "checkhelperfile.h"
int main()
{
    int ans;
    int i;
    const char menuItems[7][100] =
    {
        "1. File",
        "2. Edit the File",
        "3. Show the File",
        "4. Export Document to txt File",
        "5. Open support Files",
        "6. About the program",
        "7. Exit"
    };
    while(1)
    {
        system("clear");
        for (i = 0; i < 7; i++)
            printf("%s\n", menuItems[i]);
        printf("\nEnter a menu item: ");
        scanf("%d", &ans);
        clear();
        switch(ans)
        {
            case 1: showFileMenu(); break;
            case 2: showEditMenu(); break;
            case 3: showDoc(); break;
            case 4: export(); break;
            case 5: showDictMenu(); break;
            case 6: showAbout(); break;
            case 7: exit(0);
            default: {
                        system("clear");
                        printf("There's no such menu item.\nPress ENTER to continue...");
                        wait();
                     }
        }
    }
    return 0;
}


