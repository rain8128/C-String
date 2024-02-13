#include <stdint.h>
#include <string.h>
#include <malloc.h>

#include "String.h"

#define BUFUNIT 16


String newString(void){
    const String emptyString = {
        .ptr = NULL,
        .len = 0, 
        .capacity = 0
    };
    return emptyString;
}

String from(char* s){
    uint64_t len = strlen(s);
    uint64_t cap = (len + BUFUNIT - 1)/BUFUNIT * BUFUNIT;
    String str;
    str.ptr = (char*)malloc(cap);
    memcpy(str.ptr, s, len);
    str.len = len;
    str.capacity = cap;
    return str;
}

String concat(String str1, String str2){
    uint64_t len = str1.len + str2.len;
    uint64_t cap = (len + BUFUNIT - 1)/BUFUNIT * BUFUNIT;
    String str;
    str.ptr = (char*)malloc(cap);
    memcpy(str.ptr, str1.ptr, str1.len);
    memcpy(&str.ptr[str1.len], str2.ptr, str2.len);
    str.len = len;
    str.capacity = cap;
    return str;
}

void freeString(String str){
    free(str.ptr);
    return;
}

char At(String str, int index){
    if(index < 0 || index >= str.len) return -1;
    else return str.ptr[index];
}