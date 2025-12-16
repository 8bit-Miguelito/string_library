#include<stdio.h>
#include<stdlib.h>

#ifndef STRING_FILE_H
#define STRING_FILE_H


typedef struct //total 16 bytes with 4 bytes of padding
{
    char* str; //8 bytes
    unsigned int capacity; //4 bytes 
} string; 

string string_ctor(char* str, size_t new_cap)
{
    size_t str_size = 0;
    char* copy_str = str;
    while (copy_str[str_size] != '\0') str_size++;
    
    if (new_cap < str_size) 
    {
        size_t offset = 0;
        size_t rem = str_size % 10;
        if (rem != 0)
        {
            offset += 10 - rem;
        }
        new_cap = str_size + offset;
    }

    string new_string;
    new_string.str = (char*)malloc(1 * new_cap);
    new_string.capacity = new_cap;

    for (size_t i = 0; i < new_string.capacity; i++)
    {
        if (copy_str[i] == '\0')
        {
            new_string.str[i] = '\0';
            break;
        }
        new_string.str[i] = copy_str[i];
    }

    return new_string;
}

unsigned int str_len(string* this_str)
{
    if (this_str == NULL) return 0;

    size_t sz = 0;
    while(this_str->str[sz] != '\0') sz++;

    return sz;
}

void clear(string* this_str)
{
    free(this_str->str);
}


#endif