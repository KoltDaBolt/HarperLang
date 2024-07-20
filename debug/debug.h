#ifndef harperlang_debug_h
#define harperlang_debug_h

#include "../chunk/chunk.h"

void disassembleChunk(Chunk* chunk, const char* name);
int disassembleInstruction(Chunk* chunk, int offset);

#endif