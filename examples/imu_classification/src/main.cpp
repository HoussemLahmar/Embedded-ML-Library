#include <Arduino.h>
#include "imu_linear_regression.h" // Modèle généré
#include "linear_regression.h"    // Implémentation de la régression linéaire

// Déclaration du modèle
extern const GeneratedModel imu_linear_regression_model;

void setup() {
    Serial.begin(115200);
    Serial.println("ESP32 Linear Regression Example");

    // Exemple de données IMU (accélération sur les axes X, Y, Z)
    int32_t imu_data[3] = {1024, -512, 2048}; // Exemple en Q15

    // Création d'un modèle de régression linéaire
    LinearRegressionModel model;
    linear_regression_init(&model,
                           imu_linear_regression_model.weights,
                           imu_linear_regression_model.bias,
                           imu_linear_regression_model.num_features);

    // Effectuer une prédiction
    int32_t prediction = linear_regression_predict(&model, imu_data);

    // Afficher le résultat
    Serial.print("Prediction (Q15): ");
    Serial.println(prediction);

    // Convertir le résultat en flottant pour affichage (optionnel)
    float prediction_float = fixed_point_to_float(prediction);
    Serial.print("Prediction (float): ");
    Serial.println(prediction_float);
}

void loop() {
    // Pas de boucle continue pour cet exemple
}