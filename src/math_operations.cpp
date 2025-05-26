#include "../include/math_operations.h"
#include <cstdio>

int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }

DivisionResult divide(int a, int b) {
    DivisionResult result;
    result.quotient = a / b;
    result.remainder = a % b;
    return result;
}

const char* get_author_info() {
    static char info[256];
    snprintf(info, sizeof(info), "Автор: %s\nКонтакт: %s", AUTHOR, CONTACT);
    return info;
}