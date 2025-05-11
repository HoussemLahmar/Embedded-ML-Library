#include "linear_regression.h"
#include "fixed_point.h" // Pour les opérations sur les nombres en point fixe

// Initialiser le modèle avec un tableau de poids et un biais
void linear_regression_init(LinearRegressionModel* model, int32_t* weights, int32_t bias, size_t num_features) {
    model->weights = weights;
    model->bias = bias;
    model->num_features = num_features;
}

// Effectuer une prédiction avec le modèle
int32_t linear_regression_predict(const LinearRegressionModel* model, const int32_t* features) {
    int32_t result = model->bias; // Initialisez avec le biais
    for (size_t i = 0; i < model->num_features; ++i) {
        result += fixed_point_multiply(model->weights[i], features[i]);
    }
    return result;
}

// Mettre à jour les poids du modèle avec une seule étape de descente de gradient
void linear_regression_update(LinearRegressionModel* model, const int32_t* features, int32_t target, int32_t learning_rate) {
    // Prédiction actuelle
    int32_t prediction = linear_regression_predict(model, features);

    // Calcul de l'erreur
    int32_t error = target - prediction;

    // Mise à jour des poids et du biais
    for (size_t i = 0; i < model->num_features; ++i) {
        model->weights[i] += fixed_point_multiply(learning_rate, fixed_point_multiply(error, features[i]));
    }
    model->bias += fixed_point_multiply(learning_rate, error);
}