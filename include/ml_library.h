#ifndef ML_LIBRARY_H
#define ML_LIBRARY_H

#include <stdint.h>
#include <stddef.h>

// Linear Regression Model
typedef struct {
    int32_t* weights;   // Weights (fixed-point Q15)
    int32_t bias;       // Bias (fixed-point Q15)
    size_t num_features; // Number of features
} LinearRegressionModel;

// Initialize the model
void linear_regression_init(LinearRegressionModel* model, int32_t* weights, int32_t bias, size_t num_features);

// Train the model
void linear_regression_train(LinearRegressionModel* model, const int32_t* features, int32_t target, int32_t learning_rate);

// Predict using the model
int32_t linear_regression_predict(const LinearRegressionModel* model, const int32_t* features);

// Logistic Regression Model (inherits from Linear Regression)
typedef LinearRegressionModel LogisticRegressionModel;

// Predict using logistic regression
int32_t logistic_regression_predict(const LogisticRegressionModel* model, const int32_t* features);

// Support Vector Machine Model (inherits from Linear Regression)
typedef LinearRegressionModel SVMModel;

// Predict using SVM
int32_t svm_predict(const SVMModel* model, const int32_t* features);

#endif // ML_LIBRARY_H