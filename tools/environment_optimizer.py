import argparse

# Architecture-specific optimization flags
ARCHITECTURE_FLAGS = {
    "STM32": {
        "C_FLAGS": "-mcpu=cortex-m4 -mthumb -Os",
        "CXX_FLAGS": "-mcpu=cortex-m4 -mthumb -Os",
    },
    "ESP32": {
        "C_FLAGS": "-mlongcalls -Os",
        "CXX_FLAGS": "-mlongcalls -Os",
    },
    "GENERIC": {
        "C_FLAGS": "-Os",
        "CXX_FLAGS": "-Os",
    },
}

def generate_cmake_config(architecture, output_file):
    flags = ARCHITECTURE_FLAGS.get(architecture.upper(), ARCHITECTURE_FLAGS["GENERIC"])
    cmake_content = f"""
# CMake configuration for {architecture.upper()}
set(CMAKE_C_FLAGS "{flags['C_FLAGS']}")
set(CMAKE_CXX_FLAGS "{flags['CXX_FLAGS']}")
"""
    with open(output_file, "w") as cmake_file:
        cmake_file.write(cmake_content)
    print(f"Generated CMake configuration for {architecture.upper()} at {output_file}")

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Optimize build for specific environments.")
    parser.add_argument("--architecture", type=str, required=True, help="Target architecture (STM32, ESP32, etc.)")
    parser.add_argument("--output", type=str, required=True, help="Output CMake configuration file.")

    args = parser.parse_args()
    generate_cmake_config(args.architecture, args.output)