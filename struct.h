#ifndef STRUCT_H
#define STRUCT_H

typedef struct FOREST
{
    int id;
    int idPlace;
    int  numName;
    int numRank;
    int square;
    int flag;
} FOREST;

typedef struct MAIN_FOREST
{
    int id;
    int idPlace;
    char  name[256];
    char rank[256];
    int square;
    int flag;
} MAIN_FOREST;

typedef struct RANK
{
    int id;
    char rank[256];
    int flag;
} RANK;

typedef struct NAME
{
    int id;
    char name[256];
    int flag;
} NAME;

#endif // STRUCT_H
