#include <stdio.h>
#include <stdbool.h>

#include "string.h"

typedef struct string //total 16 bytes
{
    char* str; //8 bytes
    unsigned int capacity; //4 bytes
    unsigned int length; //4 bytes
} string;

string* my_str(char* s, unsigned int cap)
{
    string* new_s = (string*)malloc(sizeof(string));
    new_s->length = 0;
    new_s->capacity = 0;

    unsigned int size = 0;
    while(s[size] != '\0') size++;

    if (cap < size) 
    {
        new_s->capacity = size;
    }
    else 
    {
        new_s->capacity = cap;
    }

    new_s->str = (char*)malloc(1 * new_s->capacity);
    for(unsigned int i = 0; i < new_s->capacity; i++)
    {
        if (s[i] == '\0')
        {
            new_s->str[i] = '\0';
            break;
        }

        new_s->str[i] = s[i];
        new_s->length++;
    }
    return new_s;
}
unsigned int length(string* s)
{
    return s->length;
}

bool empty(string* s)
{
    return s->length == 0;
}

//Checks if two strings are equal in elements and size;
//Returns true if strings are equal
bool equal(string* a, string *b)
{
    if (a->length != b->length) return false;

    unsigned int i = 0;
    while (a->str[i] != '\0' && b->str[i] != '\0')
    {
        if (a->str[i] != b->str[i]) return false;
        i++;
    }

    if (a->str[i] == '\0' && b->str[i] == '\0')
    {
        return true;
    }

    return false;
}

//Same idea as equal method but compares a char array and a string type
bool c_equal(string* a, char* b)
{
    return false;
}

char at(string* s, const unsigned int idx)
{
    if (idx > s->length)
    {
        return '\0';
    }

    return s->str[idx];
}

char replace(string* s, char a, unsigned int idx)
{
    if (idx > s->length)
    {
        return '\0';
    }

    char out = s->str[idx];
    s->str[idx] = a;
    return out;
}
char* get_string(string* s)
{
    return s->str;
}

void destroy(string* s)
{
    free(s->str);
    free(s);
}

