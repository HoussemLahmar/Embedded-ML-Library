#ifndef SVM_H
#define SVM_H

#include <stddef.h> // Pour size_t
#include <cstdint> 

// Structure pour stocker le modèle SVM linéaire
typedef struct {
    int32_t* weights;   // Poids du modèle (point fixe, Q15)
    int32_t bias;       // Biais du modèle (point fixe, Q15)
    size_t num_features; // Nombre de caractéristiques (features)
} SVMModel;

// Initialiser le modèle SVM avec un tableau de poids et un biais
void svm_init(SVMModel* model, int32_t* weights, int32_t bias, size_t num_features);

// Effectuer une prédiction avec le modèle SVM
int32_t svm_predict(const SVMModel* model, const int32_t* features);

#endif // SVM_H