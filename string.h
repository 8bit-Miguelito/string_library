#include<stdio.h>
#include<stdlib.h>

#ifndef STRING_FILE_H
#define STRING_FILE_H

typedef struct //total 16 bytes with 4 bytes of padding
{
    char* string; //8 bytes
    size_t capacity; //4 bytes 
} string; 

//Copy string into char array inside of struct
string* new_string(char** str, size_t new_cap)
{
    size_t str_size = 0;
    while (*str[str_size] != '\0')
    {
        str_size++;
    }

    if (new_cap < str_size) return NULL;
    string* new_str = (string*)malloc(sizeof(string));
    if (!new_str) return NULL;

    new_str->capacity = new_cap;
    new_str->string = (char*)malloc(sizeof(char) * new_str->capacity);
    if (!(new_str->string)) return NULL;

    for (size_t i = 0; i < new_str->capacity; i++)
    {
        if (*str[i] == '\0') 
        {
            new_str->string[i] = '\0';
            break;
        }
        new_str->string[i] = *str[i];
    }

    return new_str;
}



#endif