#include "ml_library.h"
#include "fixed_point.h"

void linear_regression_init(LinearRegressionModel* model, int32_t* weights, int32_t bias, size_t num_features) {
    model->weights = weights;
    model->bias = bias;
    model->num_features = num_features;
}

void linear_regression_train(LinearRegressionModel* model, const int32_t* features, int32_t target, int32_t learning_rate) {
    int32_t prediction = linear_regression_predict(model, features);
    int32_t error = target - prediction;

    // Update weights and bias using gradient descent
    for (size_t i = 0; i < model->num_features; ++i) {
        model->weights[i] += fixed_point_multiply(learning_rate, fixed_point_multiply(error, features[i]));
    }
    model->bias += fixed_point_multiply(learning_rate, error);
}

int32_t linear_regression_predict(const LinearRegressionModel* model, const int32_t* features) {
    int32_t result = model->bias;
    for (size_t i = 0; i < model->num_features; ++i) {
        result += fixed_point_multiply(model->weights[i], features[i]);
    }
    return result;
}

int32_t logistic_regression_predict(const LogisticRegressionModel* model, const int32_t* features) {
    int32_t linear_prediction = linear_regression_predict(model, features);
    return (linear_prediction >= 0) ? 1 : 0; // Sigmoid approximation
}

int32_t svm_predict(const SVMModel* model, const int32_t* features) {
    int32_t result = linear_regression_predict(model, features);
    return (result >= 0) ? 1 : -1; // Binary classification
}