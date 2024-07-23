#ifndef harperlang_compiler_h
#define harperlang_compiler_h

#include "../vm/vm.h"
#include "../object/object.h"

bool compile(const char* source, Chunk* chunk);

#endif