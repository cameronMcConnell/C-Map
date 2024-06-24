#ifndef C_MAP
#define C_MAP

#include <stdlib.h>
#include "c-string.h"

typedef struct {
    int key;
    string value;
    int isOccupied;
} StringMapEntry;

typedef struct {
    int key;
    int value;
    int isOccupied;
} IntMapEntry;

typedef struct {
    size_t size;
    size_t count;
    float loadFactor;
    StringMapEntry *entries;
} StringMap;

typedef struct {
    size_t size;
    size_t count;
    float loadFactor;
    IntMapEntry *entries;
} IntMap;

StringMap *newStringMap(size_t size, float loadFactor);

IntMap *newIntMap(size_t size, float loadFactor);

size_t quadraticProbe(size_t hash, size_t attempt, size_t size);

size_t hashFunction(int key, size_t size);

int stringToInt(string *str);

void resizeStringMap();

void stringMapInsert();

void stringMapGet();

void stringMapDelete();

void resizeIntMap();

void intMapInsert();

void intMapGet();

void intMapDelete();

#endif