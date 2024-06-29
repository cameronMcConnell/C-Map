# C-Map
C-Map is a lightweight and efficient C library for creating and managing hashmaps, offering fast key-value pair storage and retrieval. It features dynamic memory management, collision resolution, and automatic resizing to ensure optimal performance in various applications.

## Features

- **String and Integer Key Support**: Supports hashmaps with string and integer keys.
- **Quadratic Probing**: Uses quadratic probing for collision resolution.
- **Dynamic Resizing**: Automatically resizes the hashmap when the load factor threshold is exceeded.

## Installation

Clone the repository to your local machine:

```sh
git clone https://github.com/cameronMcConnell/C-Map.git
cd C-Map
```

## Usage

Include the c-map.h header in your C project:

```c
#include "c-map.h"
```

## API

### StringMap

Creating a new StringMap
```c
StringMap *newStringMap(size_t size, float loadFactor);
```

Freeing a StringMap
```c
void freeStringMap(StringMap *map);
```

Inserting a key-value pair
```c
void stringMapInsert(StringMap *map, string *key, int value);
```

Retrieving a value by key
```c
int stringMapGet(StringMap *map, string *key);
```

Deleting a key-value pair
```c
void stringMapDelete(StringMap *map, string *key);
```

### IntMap

Creating a new IntMap
```c
IntMap *newIntMap(size_t size, float loadFactor);
```

Freeing an IntMap
```c
void freeIntMap(IntMap *map);
```

Inserting a key-value pair
```c
void intMapInsert(IntMap *map, int key, int value);
```

Retrieving a value by key
```c
int intMapGet(IntMap *map, int key);
```

Deleting a key-value pair
```c
void intMapDelete(IntMap *map, int key);
```

## Example
Here's an example of using the C-Map library:

```c
#include <stdio.h>
#include "c-map.h"
#include "c-string.h"

int main() {
    // Create a new IntMap
    IntMap *intMap = newIntMap(5, 0.75);
    intMapInsert(intMap, 1, 100);
    intMapInsert(intMap, 2, 200);
    printf("Value for key 1: %d\n", intMapGet(intMap, 1));
    intMapDelete(intMap, 1);
    printf("Value for key 1 after deletion: %d\n", intMapGet(intMap, 1));
    freeIntMap(intMap);

    // Create a new StringMap
    StringMap *stringMap = newStringMap(5, 0.75);
    string key1 = newString("key1");
    stringMapInsert(stringMap, &key1, 100);
    printf("Value for key 'key1': %d\n", stringMapGet(stringMap, &key1));
    stringMapDelete(stringMap, &key1);
    printf("Value for key 'key1' after deletion: %d\n", stringMapGet(stringMap, &key1));
    freeString(&key1);
    freeStringMap(stringMap);

    return 0;
}
```

## Running Tests
A set of basic tests is included in test/main.c. To compile and run the tests:

```sh
cd test
gcc main.c lib/c-map.c lib/c-string.c lib/c-map.h lib/c-map.c
./a.out
```

## Contributing
Contributions are welcome! Please feel free to submit a pull request or open an issue to improve this library.

## License
This project is licensed under the MIT License. See the LICENSE file for details.
