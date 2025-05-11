import os
import argparse

TEMPLATE_HEADER = """\
#ifndef GENERATED_MODEL_H
#define GENERATED_MODEL_H

#include <stdint.h>

// Modèle généré automatiquement
typedef struct {{
    int32_t weights[{num_features}];
    int32_t bias;
    size_t num_features;
}} GeneratedModel;

extern const GeneratedModel {model_name}_model;

#endif // GENERATED_MODEL_H
"""

TEMPLATE_SOURCE = """\
#include "{model_name}.h"

// Poids et biais générés
const GeneratedModel {model_name}_model = {{
    .weights = {{{weights}}},
    .bias = {bias},
    .num_features = {num_features}
}};
"""

def generate_header(model_name, num_features, output_dir):
    """
    Génère le fichier .h pour le modèle.
    """
    header_content = TEMPLATE_HEADER.format(
        model_name=model_name,
        num_features=num_features
    )
    header_path = os.path.join(output_dir, f"{model_name}.h")
    with open(header_path, "w") as f:
        f.write(header_content)
    print(f"[INFO] Fichier header généré : {header_path}")


def generate_source(model_name, weights, bias, num_features, output_dir):
    """
    Génère le fichier .cpp pour le modèle.
    """
    weights_str = ", ".join(map(str, weights))
    source_content = TEMPLATE_SOURCE.format(
        model_name=model_name,
        weights=weights_str,
        bias=bias,
        num_features=num_features
    )
    source_path = os.path.join(output_dir, f"{model_name}.cpp")
    with open(source_path, "w") as f:
        f.write(source_content)
    print(f"[INFO] Fichier source généré : {source_path}")


def main():
    parser = argparse.ArgumentParser(description="Générateur de code C/C++ pour modèles ML")
    parser.add_argument("--model_name", type=str, required=True, help="Nom du modèle (e.g., linear_regression)")
    parser.add_argument("--weights", type=str, required=True, help="Poids du modèle, séparés par des virgules (e.g., 123,456,-789)")
    parser.add_argument("--bias", type=int, required=True, help="Biais du modèle (e.g., 1024)")
    parser.add_argument("--num_features", type=int, required=True, help="Nombre de caractéristiques (e.g., 3)")
    parser.add_argument("--output_dir", type=str, default=".", help="Répertoire de sortie pour les fichiers générés (par défaut : courant)")

    args = parser.parse_args()

    # Extraire les poids sous forme de liste d'entiers
    weights = list(map(int, args.weights.split(",")))
    
    # Vérification de cohérence
    if len(weights) != args.num_features:
        print("[ERREUR] Le nombre de poids ne correspond pas au nombre de caractéristiques spécifié.")
        return

    # Génération des fichiers
    generate_header(args.model_name, args.num_features, args.output_dir)
    generate_source(args.model_name, weights, args.bias, args.num_features, args.output_dir)


if __name__ == "__main__":
    main()