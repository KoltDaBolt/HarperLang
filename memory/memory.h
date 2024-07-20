#ifndef harperlang_memory_h
#define harperlang_memory_h

#include "../common.h"

#define GROW_CAPACITY(capacity) \
    ((capacity) < 8 ? 8 : (capacity) * 2)

#define GROW_ARRAY(dataType, dataPointer, oldCount, newCount) \
    (dataType*)reallocate(dataPointer, sizeof(dataType) * (oldCount), sizeof(dataType) * (newCount))

#define FREE_ARRAY(dataType, dataPointer, dataSize) \
    reallocate(dataPointer, sizeof(dataType) * (dataSize), 0)

void* reallocate(void* dataPointer, size_t oldSize, size_t newSize);

#endif 