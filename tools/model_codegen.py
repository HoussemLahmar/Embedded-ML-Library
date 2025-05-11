import argparse
import os

# Convert a floating-point number to Q15 representation
def float_to_q15(value):
    return int(value * (1 << 15))

# Generate a header file for the model
def generate_model_header(model_name, weights, bias, num_features, output_dir):
    header_content = f"""
#ifndef {model_name.upper()}_H
#define {model_name.upper()}_H

#include <stdint.h>

// Model parameters
#define NUM_FEATURES {num_features}

static const int32_t {model_name}_weights[NUM_FEATURES] = {{
    {", ".join(map(str, weights))}
}};

static const int32_t {model_name}_bias = {bias};

#endif // {model_name.upper()}_H
"""
    os.makedirs(output_dir, exist_ok=True)
    header_path = os.path.join(output_dir, f"{model_name}.h")
    with open(header_path, "w") as header_file:
        header_file.write(header_content)
    print(f"Header file generated: {header_path}")

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Generate pre-trained model headers.")
    parser.add_argument("--model_name", type=str, required=True, help="Name of the model")
    parser.add_argument("--weights", type=str, required=True, help="Comma-separated weights")
    parser.add_argument("--bias", type=float, required=True, help="Bias of the model")
    parser.add_argument("--num_features", type=int, required=True, help="Number of input features")
    parser.add_argument("--output_dir", type=str, default="generated", help="Output directory")

    args = parser.parse_args()
    weights = list(map(float_to_q15, map(float, args.weights.split(","))))
    bias = float_to_q15(args.bias)

    generate_model_header(args.model_name, weights, bias, args.num_features, args.output_dir)