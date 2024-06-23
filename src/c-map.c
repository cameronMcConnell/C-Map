#include "c-map.h"

StringMap *newStringMap(size_t size, float loadFactor) {
    StringMap *map = (StringMap*) malloc(sizeof(StringMap));
    if (map == NULL) {
        return NULL;
    }

    map->size = size;
    map->loadFactor = loadFactor;
    map->count = 0;
    map->entries = (StringMapEntry*) malloc(map->size * sizeof(StringMapEntry));
    if (map->entries == NULL) {
        free(map);
        return NULL;
    }

    for (size_t i = 0; i < map->size; i++) {
        map->entries[i].isOccupied = 0;
    }

    return map;
}

IntMap *newIntMap(size_t size, float loadFactor) {
    IntMap *map = (IntMap*) malloc(sizeof(IntMap));
    if (map == NULL) {
        return NULL;
    }

    map->size = size;
    map->loadFactor = loadFactor;
    map->count = 0;
    map->entries = (IntMapEntry*) malloc(map->size * sizeof(IntMapEntry));
    if (map->entries == NULL) {
        free(map);
        return NULL;
    }

    for (size_t i = 0; i < map->size; i++) {
        map->entries[i].isOccupied = 0;
    }

    return map;
}