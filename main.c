#include "common.h"
#include "./chunk/chunk.h"
#include "./debug/debug.h"
#include "./vm/vm.h"

int main(int argc, char* argv[]){
    initVM();

    Chunk chunk;
    initChunk(&chunk);

    int constantIndex = addConstant(&chunk, 1.2);
    writeChunk(&chunk, OP_CONSTANT, 1);
    writeChunk(&chunk, constantIndex, 1);

    constantIndex = addConstant(&chunk, 3.4);
    writeChunk(&chunk, OP_CONSTANT, 123);
    writeChunk(&chunk, constantIndex, 123);

    writeChunk(&chunk, OP_ADD, 123);

    writeChunk(&chunk, OP_RETURN, 3);

    // disassembleChunk(&chunk, "test chunk");

    interpret(&chunk);

    freeChunk(&chunk);

    freeVM();

    return 0;
}