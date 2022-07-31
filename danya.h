#ifndef DANYA_H
#define DANYA_H
#include "struct.h"

extern FOREST *forest;
extern NAME *name;
extern RANK *rank;
extern MAIN_FOREST *main_forest;
extern int numLine;
extern int numName;


void open();
void clear();
void wait();
void showFileMenu();
void close();
void save();

#endif // DANYA_H
