#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

bool is_hex(char c) {
    return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F');
}

int32_t increment_hex_string(char * s, size_t buf_size) {
    if (s == NULL) {
        return -1;
    }

    int len = strlen(s);

    for (int i = 0; i < len; i++) {
        if (!is_hex(s[i])) {
            return -1;
        }
    }

    bool carry = true;
    for (int i = len - 1; (i >= 0) && carry; i--) 
    {
        if (s[i] == '9') 
        {
            s[i] = 'A';
            carry = false;
        } 
        else if (((s[i] >= '0') && (s[i] < '9')) || ((s[i] >= 'A') && (s[i] < 'F')) || ((s[i] >= 'a') && (s[i] < 'f')))
        {
            s[i]++;
            carry = false;
        } 
        else if ((s[i] == 'F') || (s[i] == 'f')) 
        {
            s[i] = '0';
            carry = true;
        } 
    }

    if (carry) {
        if (len + 1 >= buf_size) {
            return -1;
        }

        memmove(s + 1, s, len);
        s[0] = '1';
        s[len + 1] = '\0';
    }

    return 0;
}

struct test_case {
    char test_string[10];
    const char *expected_result;
    const int expected_status;
};

int main(void) {
    struct test_case tests[] = {
        {"0", "1", 0},
        {"9", "A", 0},
        {"A", "B", 0},
        {"F", "10", 0},
        {"1F", "20", 0},
        {"9F", "A0", 0},
        {"FF", "100", 0},
        {"1A3F", "1A40", 0},
        {"ABCDE", "ABCDF", 0},
        {"F9A89", "F9A8A", 0},
        {"89ABC", "89ABD", 0},
        {"F9FFF", "FA000", 0},
        {"FFFFFF", "1000000", 0},
    };

    size_t test_case_count = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < test_case_count; i++) {
        int32_t result = increment_hex_string(tests[i].test_string, sizeof(tests[i].test_string));

        if (tests[i].expected_result && strcmp(tests[i].expected_result, tests[i].test_string) == 0) {
            printf("Test Case %d, %s | Expected %s: Actual %s\n", i+1, "PASS", tests[i].expected_result, tests[i].test_string);
        } else if(result == tests[i].expected_status) {
            printf("Test Case %d, %s | Expected %d: Actual %d\n", i+1, "FAIL", tests[i].expected_status, result);
        } else {
            printf("Test Case %d, %s | Expected %d: Actual %d\n", i+1, "FAIL", tests[i].expected_status, result);
        }
    }

    return 0;
}
