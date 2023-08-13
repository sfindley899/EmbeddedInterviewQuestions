#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#define IS_DIGIT(c) ((c >= '0') && (c <= '9'))
#define TO_DIGIT(c) (c - '0')
/******************
 * my_atoi
 * 
 * @brief Converts string into integer
 * 
 * @param s string input
 * 
 * @return int32_t
*/
int32_t my_atoi(const char * s)
{
    if (s == NULL)
    {
        return 0ULL;
    }
    // Check for whitespace
    while ((*s != '\0') && ((*s == ' ') || (*s == '\t') || (*s == '\r') || (*s == '\n')))
    {
        s++;
    }

    // If the char ptr is positioned at the end of the 
    // string we need to return nothing
    if (*s == '\0')
    {
        return 0ULL;
    }

    int sign = 1;
    if (*s == '+')
    {
        /* do nothing */
        s++;
    }
    else if (*s == '-')
    {
        sign = -1;
        s++;
    }
    else
    {
        /* do nothing */
    }
    uint64_t value = 0;

    while ((*s != '\0') && IS_DIGIT(*s))
    {
        value = (value * 10) + TO_DIGIT(*s);
        s++;
    }
    return value * sign;
}

struct test_case
{
    const char *test_string;
    int32_t expected_result;
};

int main(void)
{
    struct test_case test_cases[13] = {
        {"-12345", -12345},
        {"   987", 987},
        {"+54321", 54321},
        {"0", 0},
        {"+0", 0},
        {"-0", 0},
        {"+", 0},
        {"       -54321    ", -54321},
        {"-", 0},
        {"", 0},
        {"1234abc", 1234},
        {"HelloWorld", 0},
        {NULL, 0},
    };

    size_t test_case_count = sizeof(test_cases) / sizeof(test_cases[0]); 

    for (int i = 1; i <= test_case_count; i++)
    {
        int index = i - 1;
        const char * test_string = test_cases[index].test_string;
        int32_t expected_result = test_cases[index].expected_result;
        int32_t actual_result = my_atoi(test_string);

        printf("Test %d: %s\nresult: %d %s\n\n", i, test_string, actual_result,(actual_result == expected_result) ? "PASS" : "FAIL");
    }
}
