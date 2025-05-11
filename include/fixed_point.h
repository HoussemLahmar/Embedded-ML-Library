#ifndef FIXED_POINT_H
#define FIXED_POINT_H

#include <stdint.h> // Pour les types entiers
#include <cstdint> 

// Définit le nombre de bits pour la fraction dans le format Q15
#define FIXED_POINT_FRACTIONAL_BITS 15

// Multiplie deux nombres en point fixe Q15
int32_t fixed_point_multiply(int32_t a, int32_t b);

// Divise un nombre en point fixe Q15 par un autre
int32_t fixed_point_divide(int32_t a, int32_t b);

// Convertit un flottant en point fixe Q15
int32_t float_to_fixed_point(float value);

// Convertit un point fixe Q15 en flottant
float fixed_point_to_float(int32_t value);

#endif // FIXED_POINT_H