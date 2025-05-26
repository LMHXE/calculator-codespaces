#ifndef MATH_OPERATIONS_H
#define MATH_OPERATIONS_H

const char* AUTHOR = "Непорожнев Егор Сергеевич";
const char* CONTACT = "yxgurt77@yandex.ru";

struct DivisionResult {
    int quotient;
    int remainder;
};

extern "C" {
    int add(int a, int b);
    int subtract(int a, int b);
    int multiply(int a, int b);
    DivisionResult divide(int a, int b);
    const char* get_author_info();
}

#endif 