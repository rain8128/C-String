#include <stdint.h>

typedef struct String{
    char* ptr;
    uint64_t len;
    uint64_t capacity;
} String;

String newString(void);
String from(char* s);
String concat(String str1, String str2);
void freeString(String str);
int at(String str, int index);

