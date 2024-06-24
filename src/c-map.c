#include "c-map.h"

size_t quadraticProbe(size_t hash, size_t attempt, size_t size) {
    return (hash + attempt * attempt) % size;
}

size_t hashFunction(int key, size_t size) {
    return key % size;
}

int stringToInt(string *str) {
    int result = 0;
    for (size_t i = 0; i < str->length; i++) {
        result += (int) str->str[i];
    }
    return result;
}

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

void resizeStringMap(StringMap *map) {
    size_t newSize = map->size * 2;
    StringMapEntry *newEntries = (StringMapEntry*) malloc(newSize * sizeof(StringMapEntry));
    if (newEntries == NULL) {
        return;
    }

    for (size_t i = 0; i < newSize; i++) {
        newEntries->isOccupied = 0;
    }

    for (size_t i = 0; i < map->size; i++) {
        if (map->entries[i].isOccupied) {
            string *key = map->entries[i].key;
            int value = map->entries[i].value;
            size_t hash = hashFunction(stringToInt(key), newSize);
            size_t attempt = 0;
            size_t index = quadraticProbe(hash, attempt, newSize);
            while (newEntries[index].isOccupied) {
                attempt += 1;
            }
            newEntries[index].key = key;
            newEntries[index].value = value;
            newEntries[index].isOccupied = 1;
        }
    }

    free(map->entries);
    map->entries = newEntries;
    map->size = newSize;
}

void resizeIntMap(IntMap *map) {
    size_t newSize = map->size * 2;
    IntMapEntry *newEntries = (IntMapEntry*) malloc(newSize * sizeof(IntMapEntry));
    if (newEntries == NULL) {
        return;
    }

    for (size_t i = 0; i < newSize; i++) {
        newEntries->isOccupied = 0;
    }

    for (size_t i = 0; i < map->size; i++) {
        if (map->entries[i].isOccupied) {
            int key = map->entries[i].key;
            int value = map->entries[i].value;
            size_t hash = hashFunction(key, newSize);
            size_t attempt = 0;
            size_t index = quadraticProbe(hash, attempt, newSize);
            while (newEntries[index].isOccupied) {
                attempt += 1;
            }
            newEntries[index].key = key;
            newEntries[index].value = value;
            newEntries[index].isOccupied = 1;
        }
    }

    free(map->entries);
    map->entries = newEntries;
    map->size = newSize;
}

void stringMapInsert(StringMap *map, string *key, int value) {
    if ((float) map->count / map->size >= map->loadFactor) {
        resizeStringMap(map);
    }

    size_t hash = hashFunction(stringToInt(key), map->size);
    size_t attempt = 0;
    
    size_t index = quadraticProbe(hash, attempt, map->size);
    while (map->entries[index].isOccupied) {
        attempt++;
    }
    
    map->entries[index].key = key;
    map->entries[index].value = value;
    map->entries[index].isOccupied = 1;
    map->count++;
}

void intMapInsert(IntMap *map, int key, int value) {
    if ((float) map->count / map->size >= map->loadFactor) {
        resizeIntMap(map);
    }

    size_t hash = hashFunction(key, map->size);
    size_t attempt = 0;

    size_t index = quadraticProbe(hash, attempt, map->size);
    while (map->entries[index].isOccupied) {
        attempt++;
    }

    map->entries[index].key = key;
    map->entries[index].value = value;
    map->entries[index].isOccupied = 1;
    map->count++;
}

int stringMapGet(StringMap *map, string *key) {
    size_t hash = hashFunction(stringToInt(key), map->size);
    size_t attempt = 0;

    size_t index = quadraticProbe(hash, attempt, map->size);
    while (map->entries[index].isOccupied) {
        if (compare(map->entries[index].key, key)) {
            return map->entries[index].value;
        }
        attempt++;
        index = quadraticProbe(hash, attempt, map->size);
    }

    return -1;
}

int intMapGet(IntMap *map, int key) {
    size_t hash = hashFunction(key, map->size);
    size_t attempt = 0;

    size_t index = quadraticProbe(hash, attempt, map->size);
    while (map->entries[index].isOccupied) {
        if (map->entries[index].key == key) {
            return map->entries[index].value;
        }
        attempt++;
        index = quadraticProbe(hash, attempt, map->size);
    }

    return -1;
}