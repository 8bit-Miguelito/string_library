#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "string.h"

bool test_constructor()
{
    char* s = "This is a string";
    string* sp = my_str(s, 20);

    char* qs = get_string(sp);

    if (strcmp(qs, s) != 0)
    {
        printf("Expected string: %s\n", s);
        printf("Actual string: %s\n", qs);
        return false;
    }

    destroy(sp);
    return true;
}

bool test_length()
{
    // string new_str = string_ctor("Oh yes pls!", 20);
    // unsigned int length = str_len(&new_str);
    // if (length != 11) 
    // {
    //     printf("Expected length: 11\n");
    //     printf("Actual length: %d", length);
    //     return false;
    // }

    // clear(&new_str);
    return true;
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

