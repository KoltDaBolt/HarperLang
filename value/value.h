#ifndef harperlang_value_h
#define harperlang_value_h

#include "../common.h"

typedef struct Obj Obj;
typedef struct ObjString ObjString;

typedef enum{
    VAL_BOOL,
    VAL_NULL,
    VAL_NUMBER,
    VAL_OBJ
}ValueType;

typedef struct{
    ValueType type;
    union{
        bool boolean;
        double number;
        Obj* obj;
    }as;
}Value;

#define BOOL_VAL(value)     ((Value){VAL_BOOL, {.boolean = value}})
#define NULL_VALUE          ((Value){VAL_NULL, {.number = 0}})
#define NUMBER_VAL(value)   ((Value){VAL_NUMBER, {.number = value}})
#define OBJ_VAL(object)      ((Value){VAL_OBJ, {.obj=(Obj*)object}})

#define AS_BOOL(value)      ((value).as.boolean)
#define AS_NUMBER(value)    ((value).as.number)
#define AS_OBJ(value)       ((value).as.obj)

#define IS_BOOL(value)      ((value).type == VAL_BOOL)
#define IS_NULL(value)      ((value).type == VAL_NULL)
#define IS_NUMBER(value)    ((value).type == VAL_NUMBER)
#define IS_OBJ(value)       ((value).type == VAL_OBJ)

typedef struct{
    int count;
    int capacity;
    Value* values;
}ValueArray;

void initValueArray(ValueArray* array);
void freeValueArray(ValueArray* array);
void writeValueArray(ValueArray* array, Value value);
void printValue(Value value);
bool valuesEqual(Value a, Value b);

#endif