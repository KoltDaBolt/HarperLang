#ifndef harperlang_compiler_h
#define harperlang_compiler_h

#include "../vm/vm.h"

bool compile(const char* source, Chunk* chunk);

#endif