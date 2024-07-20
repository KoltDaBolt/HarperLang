#include "common.h"
#include "./chunk/chunk.h"
#include "./debug/debug.h"

int main(int argc, char* argv[]){
    Chunk chunk;
    initChunk(&chunk);

    int constantIndex = addConstant(&chunk, 1.2);
    writeChunk(&chunk, OP_CONSTANT, 1);
    writeChunk(&chunk, constantIndex, 1);

    constantIndex = addConstant(&chunk, 5);
    writeChunk(&chunk, OP_CONSTANT, 2);
    writeChunk(&chunk, constantIndex, 2);

    writeChunk(&chunk, OP_RETURN, 3);

    disassembleChunk(&chunk, "test chunk");

    freeChunk(&chunk);

    return 0;
}