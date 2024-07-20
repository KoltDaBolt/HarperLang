#include <stdlib.h>
#include "memory.h"

void* reallocate(void* dataPointer, size_t oldSize, size_t newSize){
    if(newSize == 0){
        free(dataPointer);
        return NULL;
    }

    void* result = realloc(dataPointer, newSize);
    if(result == NULL) exit(1);
    return result;
}