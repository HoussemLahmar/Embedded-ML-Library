import argparse
import os
import csv

# Generate a test file for a model
def generate_test_file(model_name, test_data, expected_results, output_dir):
    os.makedirs(output_dir, exist_ok=True)
    test_file_path = os.path.join(output_dir, f"test_{model_name}.cpp")
    with open(test_file_path, "w") as test_file:
        test_file.write(f"""
#include "{model_name}.h"
#include <iostream>
#include <cassert>

void test_{model_name}() {{
    int32_t features[][NUM_FEATURES] = {{
""")
        for row in test_data:
            test_file.write(f"        {{{', '.join(map(str, row))}}},\n")
        test_file.write(f"    }};\n\n")
        test_file.write("    int32_t expected_results[] = {\n")
        test_file.write(f"        {', '.join(map(str, expected_results))}\n")
        test_file.write("    };\n\n")
        test_file.write(f"    for (size_t i = 0; i < {len(test_data)}; ++i) {{\n")
        test_file.write("        int32_t prediction = 0;\n")  # Add prediction logic here
        test_file.write("        assert(prediction == expected_results[i]);\n")
        test_file.write("    }\n")
        test_file.write("    std::cout << \"All tests passed!\" << std::endl;\n")
        test_file.write("}\n\n")
        test_file.write("int main() {\n")
        test_file.write(f"    test_{model_name}();\n")
        test_file.write("    return 0;\n")
        test_file.write("}\n")
    print(f"Generated test file: {test_file_path}")

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Generate test files for a model.")
    parser.add_argument("--model_name", type=str, required=True, help="Name of the model")
    parser.add_argument("--test_data", type=str, required=True, help="Path to CSV file containing test data (features)")
    parser.add_argument("--expected_results", type=str, required=True, help="Comma-separated expected results")
    parser.add_argument("--output_dir", type=str, required=True, help="Output directory for the test file")

    args = parser.parse_args()
    with open(args.test_data, "r") as csvfile:
        reader = csv.reader(csvfile)
        test_data = [list(map(int, row)) for row in reader]
    expected_results = list(map(int, args.expected_results.split(",")))

    generate_test_file(args.model_name, test_data, expected_results, args.output_dir)