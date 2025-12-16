#include<stdio.h>
#include<stdlib.h>

#ifndef STRING_FILE_H
#define STRING_FILE_H

typedef struct string string;

string* my_str(char* s, const unsigned int cap);
unsigned int length(string* s);
bool empty(string* s);
bool equal(string* a, string *b);
bool c_equal(string* a, char* b);
char at(string* s, unsigned int idx);
char* get_string(string* s);
void destroy(string* s);

#endif