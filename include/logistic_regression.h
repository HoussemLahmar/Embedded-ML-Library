#ifndef LOGISTIC_REGRESSION_H
#define LOGISTIC_REGRESSION_H

#include <stddef.h> // Pour size_t
#include <cstdint> 

// Structure pour stocker le modèle de régression logistique
typedef struct {
    int32_t* weights;   // Poids du modèle (point fixe, Q15)
    int32_t bias;       // Biais du modèle (point fixe, Q15)
    size_t num_features; // Nombre de caractéristiques (features)
} LogisticRegressionModel;

// Initialiser le modèle avec un tableau de poids et un biais
void logistic_regression_init(LogisticRegressionModel* model, int32_t* weights, int32_t bias, size_t num_features);

// Effectuer une prédiction avec le modèle
int32_t logistic_regression_predict(const LogisticRegressionModel* model, const int32_t* features);

// Fonction sigmoïde optimisée pour le point fixe Q15
int32_t fixed_point_sigmoid(int32_t x);

#endif // LOGISTIC_REGRESSION_H