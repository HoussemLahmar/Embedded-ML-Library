#include <iostream>
#include "linear_regression.h"
#include "fixed_point.h"
#include <cassert>

void test_linear_regression_predict() {
    int32_t weights[2] = {float_to_fixed_point(0.5), float_to_fixed_point(-0.25)};
    int32_t bias = float_to_fixed_point(0.1);
    LinearRegressionModel model;
    linear_regression_init(&model, weights, bias, 2);

    int32_t features[2] = {float_to_fixed_point(1.0), float_to_fixed_point(2.0)};
    int32_t prediction = linear_regression_predict(&model, features);

    float prediction_float = fixed_point_to_float(prediction);
    assert(prediction_float == 0.1f); // (0.5*1 - 0.25*2 + 0.1) = 0.1
    std::cout << "Test linear_regression_predict passed!" << std::endl;
}
int main() {
    test_linear_regression_predict();
    return 0;
}