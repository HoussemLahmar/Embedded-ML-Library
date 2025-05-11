#include "logistic_regression.h"
#include "fixed_point.h" // Pour les opérations sur les nombres en point fixe

// Initialiser le modèle avec un tableau de poids et un biais
void logistic_regression_init(LogisticRegressionModel* model, int32_t* weights, int32_t bias, size_t num_features) {
    model->weights = weights;
    model->bias = bias;
    model->num_features = num_features;
}

// Effectuer une prédiction avec le modèle
int32_t logistic_regression_predict(const LogisticRegressionModel* model, const int32_t* features) {
    int32_t result = model->bias;

    // Produit scalaire entre les poids et les caractéristiques
    for (size_t i = 0; i < model->num_features; ++i) {
        result += fixed_point_multiply(model->weights[i], features[i]);
    }

    // Appliquer la fonction sigmoïde au résultat
    return fixed_point_sigmoid(result);
}

// Fonction sigmoïde optimisée pour le point fixe Q15
int32_t fixed_point_sigmoid(int32_t x) {
    // Approximation de la sigmoïde avec une table de recherche ou une approximation polynomiale
    // Sigmoïde : 1 / (1 + exp(-x))
    // Pour point fixe Q15, nous devons ajuster l'échelle.

    // Limiter la plage de x pour éviter les dépassements
    if (x > (8 << FIXED_POINT_FRACTIONAL_BITS)) { // Sigmoïde(8) ~ 1
        return (1 << FIXED_POINT_FRACTIONAL_BITS); // 1 en Q15
    }
    if (x < (-8 << FIXED_POINT_FRACTIONAL_BITS)) { // Sigmoïde(-8) ~ 0
        return 0; // 0 en Q15
    }

    // Approximation polynomiale pour la sigmoïde sur [-8, 8]
    // Sigmoid(x) ≈ 0.5 + 0.25 * x / (1 + |x|)
    int32_t abs_x = (x < 0) ? -x : x; // Valeur absolue de x
    int32_t denominator = (1 << FIXED_POINT_FRACTIONAL_BITS) + abs_x; // 1 + |x| en Q15
    int32_t fraction = fixed_point_divide(x, denominator); // x / (1 + |x|) en Q15
    return (1 << (FIXED_POINT_FRACTIONAL_BITS - 1)) + (fraction >> 2); // 0.5 + 0.25 * fraction
}