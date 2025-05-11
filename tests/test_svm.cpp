#include <iostream>
#include "svm.h"
#include "fixed_point.h"
#include <cassert>

void test_svm_predict() {
    int32_t weights[2] = {float_to_fixed_point(0.5), float_to_fixed_point(-0.5)};
    int32_t bias = float_to_fixed_point(0.0);
    SVMModel model;
    svm_init(&model, weights, bias, 2);

    int32_t features[2] = {float_to_fixed_point(1.0), float_to_fixed_point(1.0)};
    int32_t prediction = svm_predict(&model, features);

    assert(prediction == 0); // (0.5*1 - 0.5*1 + 0.0) = 0, hence class 0
    std::cout << "Test svm_predict passed!" << std::endl;
}

int main() {
    test_svm_predict();
    return 0;
}