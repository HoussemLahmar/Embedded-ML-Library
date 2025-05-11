#include "svm.h"
#include "fixed_point.h" // Pour les opérations sur les nombres en point fixe

// Initialiser le modèle SVM avec un tableau de poids et un biais
void svm_init(SVMModel* model, int32_t* weights, int32_t bias, size_t num_features) {
    model->weights = weights;
    model->bias = bias;
    model->num_features = num_features;
}

// Effectuer une prédiction avec le modèle SVM
int32_t svm_predict(const SVMModel* model, const int32_t* features) {
    int32_t result = model->bias;

    // Produit scalaire entre les poids et les caractéristiques
    for (size_t i = 0; i < model->num_features; ++i) {
        result += fixed_point_multiply(model->weights[i], features[i]);
    }

    // Retourne le signe du résultat : +1 ou -1
    return (result >= 0) ? (1 << FIXED_POINT_FRACTIONAL_BITS) : 0; // +1 ou 0 en Q15
}