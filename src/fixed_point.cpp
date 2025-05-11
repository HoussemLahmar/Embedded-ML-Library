#include "fixed_point.h"

// Multiplie deux nombres en point fixe Q15
int32_t fixed_point_multiply(int32_t a, int32_t b) {
    // La multiplication de deux Q15 produit un Q30, il faut donc décaler le résultat de 15 bits
    return (a * b) >> FIXED_POINT_FRACTIONAL_BITS;
}

// Divise un nombre en point fixe Q15 par un autre
int32_t fixed_point_divide(int32_t a, int32_t b) {
    // Évite la division par zéro
    if (b == 0) {
        return 0; // Ou une autre valeur de sécurité
    }
    // La division de deux Q15 produit un Q15, il faut donc ajuster la précision
    return (a << FIXED_POINT_FRACTIONAL_BITS) / b;
}

// Convertit un flottant en point fixe Q15
int32_t float_to_fixed_point(float value) {
    return (int32_t)(value * (1 << FIXED_POINT_FRACTIONAL_BITS));
}

// Convertit un point fixe Q15 en flottant
float fixed_point_to_float(int32_t value) {
    return (float)value / (1 << FIXED_POINT_FRACTIONAL_BITS);
}