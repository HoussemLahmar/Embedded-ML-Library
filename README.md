# ML Embedded Library

A lightweight, header-only machine learning library designed for embedded systems such as ESP32 and STM32. This library enables real-time training, ultra-light inference, and sensor/actuator integration directly on microcontrollers. The library is optimized for memory-constrained environments.

---

## Features

### Core Capabilities
- **Real-Time Training**: Update linear models (e.g., linear regression, logistic regression, SVM) directly on microcontrollers with data collected from sensors.
- **Ultra-Light Inference**: Designed to work without dynamic memory allocation, relying only on fixed-point arithmetic to ensure minimal CPU and memory usage.
- **Sensor/Actuator Integration**: Provides utilities to interface with ADC, DAC, PWM, GPIO, and timers for seamless integration with sensors and actuators.

### Supported Models
1. Linear Regression
2. Logistic Regression
3. Support Vector Machine (SVM) with a linear kernel

### Performance Highlights
- Binary size ≤ 20 KB (optimized with `-Os`).
- No heap allocation, no `dynamic_cast`, no exceptions.
- C99/C++11 compatible API.

---

## Project Structure

```
ml_embedded_library/
├── include/                         # Public headers
│   ├── ml_library.h                 # Main API for ML models
│   ├── linear_regression.h          # Linear regression
│   ├── logistic_regression.h        # Logistic regression
│   ├── svm.h                        # SVM (Support Vector Machine)
│   ├── fixed_point.h                # Fixed-point arithmetic utilities
│   ├── preprocess.h                 # Data preprocessing utilities
│   ├── io_library.h                 # Utilities for sensor/actuator integration
│   └── microcontroller_config.h     # Microcontroller-specific configuration
├── src/                             # Implementations
│   ├── ml_library.c                 # ML library implementation (C)
│   ├── linear_regression.cpp        # Linear regression implementation
│   ├── logistic_regression.cpp      # Logistic regression implementation
│   ├── svm.cpp                      # SVM implementation
│   ├── fixed_point.cpp              # Fixed-point arithmetic utilities implementation
│   ├── preprocess.cpp               # Data preprocessing utilities
│   └── io_library.cpp               # Sensor/actuator integration utilities
├── examples/                        # Integration examples
│   ├── imu_classification/          # Example: IMU-based classification
│   │   ├── src/
│   │   │   ├── main.cpp             # Example main file
│   │   ├── platformio.ini           # PlatformIO configuration for ESP32
├── tests/                           # Unit tests
│   ├── test_linear_regression.cpp   # Tests for linear regression
│   ├── test_logistic_regression.cpp # Tests for logistic regression
│   ├── test_svm.cpp                 # Tests for SVM
│   ├── test_fixed_point.cpp         # Tests for fixed-point arithmetic
│   └── test_preprocess.cpp          # Tests for data preprocessing
├── CMakeLists.txt                   # CMake configuration
├── Makefile                         # Simple Makefile for building
└── README.md                        # Documentation
```

---

## Installation and Setup

### Prerequisites
1. **C/C++ Compiler**: `arm-none-eabi-gcc` for cross-compilation.
2. **PlatformIO**: For deploying examples to microcontrollers like ESP32.

### Build the Library
#### Using CMake:
```bash
mkdir build && cd build
cmake ..
make
```

#### Using Makefile:
```bash
make
```

### Deploy to ESP32:
Navigate to the `examples/imu_classification` directory and use PlatformIO:
```bash
pio run --target upload
```

---

## Usage

### 1. Training and Predicting on the Microcontroller

#### Step 1: Initialize the Model
Define the model weights and bias, initialize the model, and configure the number of features:
```cpp
#include "linear_regression.h"

int32_t weights[3] = {float_to_fixed_point(0.5), float_to_fixed_point(-0.25), float_to_fixed_point(0.1)};
int32_t bias = float_to_fixed_point(0.05);
LinearRegressionModel model;
linear_regression_init(&model, weights, bias, 3);
```

#### Step 2: Collect Sensor Data
Use the `io_library` to interface with sensors and actuators:
```cpp
#include "io_library.h"

io_init();
int32_t sensor_data[3];
sensor_data[0] = read_sensor_data();  // Example: Read ADC data
sensor_data[1] = read_sensor_data();
sensor_data[2] = read_sensor_data();
```

#### Step 3: Train the Model
Update the model parameters using real-time data collected from the sensors:
```cpp
int32_t target = float_to_fixed_point(1.0);  // Example target value
int32_t learning_rate = float_to_fixed_point(0.01);
linear_regression_train(&model, sensor_data, target, learning_rate);
```

#### Step 4: Make Predictions
Predict actuator commands or outputs using the trained model:
```cpp
int32_t prediction = linear_regression_predict(&model, sensor_data);
write_actuator_data(prediction);  // Example: Write prediction to PWM or DAC
```

---

## Example: IMU-Based Classification on ESP32

### Setup
1. Open the `examples/imu_classification` directory.
2. Modify `main.cpp` to include your model and data.
3. Build and upload:
   ```bash
   pio run --target upload
   ```

### Expected Output
In the serial monitor:
```
Prediction (Q15): 15678
Prediction (float): 0.478
```

---

## Optimization Guide

Refer to the [Optimization Guide](OPTIMIZATION_GUIDE.md) for tips on reducing binary size, optimizing memory usage, and maximizing CPU performance.

---

## Contributing

1. Fork this repository.
2. Create a new branch:
   ```bash
   git checkout -b feature/your-feature
   ```
3. Commit your changes and push:
   ```bash
   git push origin feature/your-feature
   ```
4. Open a pull request.

---

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.