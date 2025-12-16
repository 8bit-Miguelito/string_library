#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "string.h"

bool test_constructor()
{
    char* str_cmp = "This is a string";
    string* new_str = new_string(&str_cmp, 10);
    if (new_str != NULL)
    {
        printf("Expected NULL return; Capacity is less than str_cmp size.\n");
        return false;
    }

    new_str = new_string(&str_cmp, 20);
    if (new_str == NULL)
    {
        printf("Expected normal return; NULL returned on valid capacity.\n");
        return false;
    }
    if (strcmp(new_str->string, str_cmp) != 0)
    {
        printf("Expected string: %s\n", str_cmp);
        printf("Actual string: %s\n", new_str->string);
    }

    return false;
}

int main()
{
    if (!test_constructor())
    {
        printf("Test failed for constructor method\n");
    }
}

