import argparse
import os
import matplotlib.pyplot as plt

# Generate model documentation
def generate_model_doc(model_name, weights, bias, output_dir):
    os.makedirs(output_dir, exist_ok=True)
    doc_file_path = os.path.join(output_dir, f"{model_name}_documentation.txt")
    with open(doc_file_path, "w") as doc_file:
        doc_file.write(f"Model: {model_name}\n")
        doc_file.write(f"Number of Features: {len(weights)}\n")
        doc_file.write(f"Weights: {weights}\n")
        doc_file.write(f"Bias: {bias}\n")
    print(f"Documentation generated: {doc_file_path}")

# Plot model weights
def plot_weights(weights, output_dir):
    plt.figure()
    plt.bar(range(len(weights)), weights)
    plt.xlabel("Feature Index")
    plt.ylabel("Weight Value")
    plt.title("Model Weights")
    plot_file_path = os.path.join(output_dir, "weights_plot.png")
    plt.savefig(plot_file_path)
    print(f"Weight plot saved: {plot_file_path}")

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Generate documentation and visualizations for a model.")
    parser.add_argument("--model_name", type=str, required=True, help="Name of the model")
    parser.add_argument("--weights", type=str, required=True, help="Comma-separated weights")
    parser.add_argument("--bias", type=float, required=True, help="Bias of the model")
    parser.add_argument("--output_dir", type=str, required=True, help="Output directory for documentation and plots")

    args = parser.parse_args()
    weights = list(map(float, args.weights.split(",")))

    generate_model_doc(args.model_name, weights, args.bias, args.output_dir)
    plot_weights(weights, args.output_dir)