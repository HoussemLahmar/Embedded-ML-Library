# ML Embedded Library

A lightweight, header-only machine learning library designed for embedded systems such as ESP32 and STM32. This library enables real-time training, ultra-light inference, and automatic code generation for easy integration into your embedded projects.

---

## Features

### Core Capabilities
- **Real-Time Training**: Update linear models (e.g., linear regression, logistic regression, SVM) directly on microcontrollers with data collected from sensors.
- **Ultra-Light Inference**: Designed to work without dynamic memory allocation, relying only on fixed-point arithmetic to ensure minimal CPU and memory usage.
- **Code Generation**: Automatically generate C/C++ code for trained models using a Python script.

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
│   ├── ml_embedded.h                # Main API
│   ├── linear_regression.h          # Linear regression
│   ├── logistic_regression.h        # Logistic regression
│   ├── svm.h                        # SVM (Support Vector Machine)
│   ├── fixed_point.h                # Fixed-point arithmetic utilities
│   └── preprocess.h                 # Data preprocessing utilities
├── src/                             # Implementations
│   ├── ml_embedded.cpp              # Main API implementation
│   ├── linear_regression.cpp        # Linear regression implementation
│   ├── logistic_regression.cpp      # Logistic regression implementation
│   ├── svm.cpp                      # SVM implementation
│   ├── fixed_point.cpp              # Fixed-point arithmetic utilities implementation
│   └── preprocess.cpp               # Data preprocessing utilities
├── tools/                           # Python scripts for training and code generation
│   ├── train.py                     # Training script
│   ├── codegen.py                   # Code generation script
│   └── data_acquisition.py          # Data acquisition script
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
2. **Python 3.x**: Required for training and code generation scripts.
3. **PlatformIO**: For deploying examples to microcontrollers like ESP32.

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

### 1. Training a Model
1. **Collect data** using the `data_acquisition.py` script:
   ```bash
   python3 tools/data_acquisition.py --output imu_data.csv
   ```

2. **Train a model** with the `train.py` script:
   ```bash
   python3 tools/train.py --input imu_data.csv --model linear_regression --output weights.json
   ```

3. **Generate C/C++ code** from the trained model:
   ```bash
   python3 tools/codegen.py --model_name imu_model \
                            --weights 12345,-6789,23456 \
                            --bias 5432 \
                            --num_features 3 \
                            --output_dir examples/imu_classification/src/
   ```

### 2. Integration on Microcontroller
Include the generated model header (`imu_model.h`) and use it with the library's API. Example:
```cpp
#include "imu_model.h"
#include "linear_regression.h"

int32_t imu_data[3] = {1024, -512, 2048};
LinearRegressionModel model;
linear_regression_init(&model, imu_model.weights, imu_model.bias, imu_model.num_features);
int32_t prediction = linear_regression_predict(&model, imu_data);
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