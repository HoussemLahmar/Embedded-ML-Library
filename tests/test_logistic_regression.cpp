#include <iostream>
#include "logistic_regression.h"
#include "fixed_point.h"
#include <cassert>

void test_logistic_regression_predict() {
    int32_t weights[1] = {float_to_fixed_point(1.0)};
    int32_t bias = float_to_fixed_point(0.0);
    LogisticRegressionModel model;
    logistic_regression_init(&model, weights, bias, 1);

    int32_t features[1] = {float_to_fixed_point(0.0)};
    int32_t prediction = logistic_regression_predict(&model, features);

    float prediction_float = fixed_point_to_float(prediction);
    assert(prediction_float == 0.5f); // Sigmoid(0) = 0.5
    std::cout << "Test logistic_regression_predict passed!" << std::endl;
}

int main() {
    test_logistic_regression_predict();
    return 0;
}