#ifndef LINEAR_REGRESSION_H
#define LINEAR_REGRESSION_H

#include <stddef.h> // Pour size_t
#include <cstdint> 

// Structure pour stocker le modèle de régression linéaire
typedef struct {
    int32_t* weights;   // Poids du modèle (point fixe, Q15)
    int32_t bias;       // Biais du modèle (point fixe, Q15)
    size_t num_features; // Nombre de caractéristiques (features)
} LinearRegressionModel;

// Initialiser le modèle avec un tableau de poids et un biais
void linear_regression_init(LinearRegressionModel* model, int32_t* weights, int32_t bias, size_t num_features);

// Effectuer une prédiction avec le modèle
int32_t linear_regression_predict(const LinearRegressionModel* model, const int32_t* features);

// Mettre à jour les poids du modèle avec une seule étape de descente de gradient
void linear_regression_update(LinearRegressionModel* model, const int32_t* features, int32_t target, int32_t learning_rate);

#endif // LINEAR_REGRESSION_H