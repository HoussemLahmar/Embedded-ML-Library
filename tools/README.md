# Tools for ML Embedded Library Code Generation and Optimization

This directory contains Python scripts designed to support the **ML Embedded Library** project. These tools simplify model generation, optimization, testing, and documentation for machine learning models used in embedded systems like STM32 and ESP32.

---

## Objectives

The tools in this directory aim to:
1. **Generate Pre-Trained Models**: Automate the creation of C/C++ headers containing pre-trained model parameters (weights and biases) for direct integration into embedded projects.
2. **Optimize for Different Architectures**: Configure build settings (e.g., compiler flags) to ensure compatibility and performance on various microcontrollers.
3. **Generate Automated Test Files**: Create C++ test files for validating model performance on specific datasets.
4. **Generate Documentation and Visualizations**: Provide insights into the model's structure (e.g., weights, biases) and generate visualizations to assist in understanding and debugging.

---

## Scripts Overview

### 1. **Model Code Generation (`model_codegen.py`)**
- **Purpose**: Generate a C header file for a pre-trained model with parameters formatted for fixed-point arithmetic.
- **Usage**:
  ```bash
  python model_codegen.py --model_name <model_name> --weights <comma-separated_weights> \
                          --bias <bias_value> --num_features <number_of_features> \
                          --output_dir <output_directory>
  ```
- **Example**:
  ```bash
  python model_codegen.py --model_name linear_regression --weights 0.5,-0.25,0.1 \
                          --bias 0.05 --num_features 3 --output_dir src/models
  ```
  This generates a file `linear_regression.h` with weights and bias in Q15 format.

---

### 2. **Environment Optimizer (`environment_optimizer.py`)**
- **Purpose**: Generate architecture-specific compiler flags for STM32, ESP32, or other microcontroller platforms.
- **Usage**:
  ```bash
  python environment_optimizer.py --architecture <architecture_name> --output <output_file>
  ```
- **Example**:
  ```bash
  python environment_optimizer.py --architecture STM32 --output cmake/config_stm32.cmake
  ```
  This creates a CMake configuration file optimized for STM32.

---

### 3. **Test File Generator (`test_generator.py`)**
- **Purpose**: Generate C++ test files for validating machine learning models with specific datasets.
- **Usage**:
  ```bash
  python test_generator.py --model_name <model_name> --test_data <path_to_csv_data> \
                           --expected_results <comma-separated_results> --output_dir <output_directory>
  ```
- **Example**:
  ```bash
  python test_generator.py --model_name linear_regression --test_data test_data.csv \
                           --expected_results 1,0,1 --output_dir tests
  ```
  This generates a test file `test_linear_regression.cpp` in the `tests/` directory.

---

### 4. **Model Documentation Generator (`model_documentation.py`)**
- **Purpose**: Generate descriptive documentation and visualizations for a machine learning model.
- **Usage**:
  ```bash
  python model_documentation.py --model_name <model_name> --weights <comma-separated_weights> \
                                --bias <bias_value> --output_dir <output_directory>
  ```
- **Example**:
  ```bash
  python model_documentation.py --model_name svm --weights 0.5,-0.25,0.1 \
                                --bias 0.05 --output_dir docs
  ```
  This generates a text file describing the model and a bar chart visualizing the weights.

---

## Directory Structure

```
tools/
├── model_codegen.py           # Generate pre-trained model headers
├── environment_optimizer.py   # Optimize build settings for architectures
├── test_generator.py          # Generate automated test files
├── model_documentation.py     # Generate model documentation and visualizations
├── README.md                  # Documentation for these tools
```

---

## Installation and Prerequisites

1. **Python 3.x**: Ensure you have Python installed.
2. **Required Libraries**: Install dependencies using pip:
   ```bash
   pip install matplotlib
   ```

---

## Contribution and Support

If you encounter issues with these scripts or have suggestions for improvement, feel free to create an issue or submit a pull request in the main repository.
