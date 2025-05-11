#include "io_library.h"
#include "ml_library.h"
#include "fixed_point.h"

#define NUM_FEATURES 1 // Number of input features

int32_t weights[NUM_FEATURES] = {float_to_fixed_point(0.5)};
int32_t bias = float_to_fixed_point(0.1);
LinearRegressionModel model;

void main() {
    // Initialize I/O and the model
    io_init();
    linear_regression_init(&model, weights, bias, NUM_FEATURES);

    // Main loop
    while (1) {
        // Read sensor data
        int32_t sensor_data = read_sensor_data();

        // Prepare features (example: normalize sensor data)
        int32_t features[NUM_FEATURES] = {sensor_data};

        // Train the model (example: use actuator command as target)
        int32_t target = sensor_data * 2; // Example target
        int32_t learning_rate = float_to_fixed_point(0.01);
        linear_regression_train(&model, features, target, learning_rate);

        // Predict actuator command
        int32_t prediction = linear_regression_predict(&model, features);

        // Write actuator data
        write_actuator_data(prediction);
    }
}