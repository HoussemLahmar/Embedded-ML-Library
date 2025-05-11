#include <iostream>
#include "preprocess.h"
#include "fixed_point.h"
#include <cassert>

void test_normalization() {
    int32_t raw_value = 5;
    int32_t min_value = 0;
    int32_t max_value = 10;

    int32_t normalized = normalize(raw_value, min_value, max_value);
    float normalized_float = fixed_point_to_float(normalized);

    assert(normalized_float == 0.5f); // (5 - 0) / (10 - 0) = 0.5
    std::cout << "Test normalization passed!" << std::endl;
}

int main() {
    test_normalization();
    return 0;
}