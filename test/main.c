#include <stdio.h>
#include <assert.h>
#include "lib/c-map.h"
#include "lib/c-string.h"

void testIntMap() {
    IntMap *map = newIntMap(5, 0.75);

    // Test insertion
    intMapInsert(map, 1, 100);
    intMapInsert(map, 2, 200);
    intMapInsert(map, 3, 300);
    intMapInsert(map, 4, 400);
    intMapInsert(map, 5, 500);

    assert(intMapGet(map, 1) == 100);
    assert(intMapGet(map, 2) == 200);
    assert(intMapGet(map, 3) == 300);
    assert(intMapGet(map, 4) == 400);
    assert(intMapGet(map, 5) == 500);

    // Test deletion
    intMapDelete(map, 3);
    assert(intMapGet(map, 3) == -1);

    // Test resizing
    intMapInsert(map, 6, 600);
    assert(intMapGet(map, 6) == 600);

    // Cleanup
    free(map->entries);
    free(map);
}

void testStringMap() {
    StringMap *map = newStringMap(5, 0.75);

    // Create some strings
    string *key1 = newString("key1");
    string *key2 = newString("key2");
    string *key3 = newString("key3");
    string *key4 = newString("key4");
    string *key5 = newString("key5");

    // Test insertion
    stringMapInsert(map, key1, 100);
    stringMapInsert(map, key2, 200);
    stringMapInsert(map, key3, 300);
    stringMapInsert(map, key4, 400);
    stringMapInsert(map, key5, 500);

    assert(stringMapGet(map, key1) == 100);
    assert(stringMapGet(map, key2) == 200);
    assert(stringMapGet(map, key3) == 300);
    assert(stringMapGet(map, key4) == 400);
    assert(stringMapGet(map, key5) == 500);

    // Test deletion
    stringMapDelete(map, key3);
    assert(stringMapGet(map, key3) == -1);

    // Test resizing
    string *key6 = newString("key6");
    stringMapInsert(map, key6, 600);
    assert(stringMapGet(map, key6) == 600);

    // Cleanup
    free(map->entries);
    free(map);

    // Free strings
    freeString(key1);
    freeString(key2);
    freeString(key3);
    freeString(key4);
    freeString(key5);
    freeString(key6);
}

int main() {
    testIntMap();
    testStringMap();

    printf("All tests passed!\n");
    return 0;
}