#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "string.h"

bool test_constructor()
{
    char* str_cmp = "This is a string";
    string new_str = string_ctor(str_cmp, 10);

    if (strcmp(new_str.str, str_cmp) != 0)
    {
        printf("Expected string: %s\n", str_cmp);
        printf("Actual string: %s\n", new_str.str);
        return false;
    }

    string other_str = string_ctor("Do input strings like this work?", 10);
    if (strcmp(other_str.str, "Do input strings like this work?"))
    {
        printf("Expected string: Do input strings like this work?\n");
        printf("Actual string: %s\n", other_str.str);
        return false;
    }

    clear(&new_str);
    clear(&other_str);

    return true;
}

bool test_length()
{
    string new_str = string_ctor("Oh yes pls!", 20);
    unsigned int length = str_len(&new_str);
    if (length != 11) 
    {
        printf("Expected length: 11\n");
        printf("Actual length: %d", length);
    }

    clear(&new_str);
}



int main()
{
    if (!test_constructor())
    {
        printf("Test failed for constructor method\n");
    }
    else
    {
        printf("Constructor_Test: PASSED\n");
    }

    if (!test_length())
    {
        printf("Test failed for length method");
    }
    else
    {
        printf("Length_Test: PASSED\n");
    }
}

