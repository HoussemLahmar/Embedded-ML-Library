#include <iostream>
#include "fixed_point.h"
#include <cassert>

void test_fixed_point_multiply() {
    int32_t a = float_to_fixed_point(0.5); // Q15 representation of 0.5
    int32_t b = float_to_fixed_point(-0.25); // Q15 representation of -0.25
    int32_t result = fixed_point_multiply(a, b);
    float result_float = fixed_point_to_float(result);
    assert(result_float == -0.125f); // 0.5 * -0.25 = -0.125
    std::cout << "Test fixed_point_multiply passed!" << std::endl;
}

void test_fixed_point_divide() {
    int32_t a = float_to_fixed_point(0.5); // Q15 representation of 0.5
    int32_t b = float_to_fixed_point(0.25); // Q15 representation of 0.25
    int32_t result = fixed_point_divide(a, b);
    float result_float = fixed_point_to_float(result);
    assert(result_float == 2.0f); // 0.5 / 0.25 = 2.0
    std::cout << "Test fixed_point_divide passed!" << std::endl;
}

void test_float_to_fixed_point() {
    float value = 0.75f;
    int32_t fixed_point = float_to_fixed_point(value);
    assert(fixed_point == 24576); // 0.75 * 2^15 = 24576
    std::cout << "Test float_to_fixed_point passed!" << std::endl;
}

void test_fixed_point_to_float() {
    int32_t fixed_point = 16384; // Q15 representation of 0.5
    float value = fixed_point_to_float(fixed_point);
    assert(value == 0.5f);
    std::cout << "Test fixed_point_to_float passed!" << std::endl;
}

int main() {
    test_fixed_point_multiply();
    test_fixed_point_divide();
    test_float_to_fixed_point();
    test_fixed_point_to_float();
    return 0;
}