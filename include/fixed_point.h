#ifndef FIXED_POINT_H
#define FIXED_POINT_H

#include <stdint.h>

#define FIXED_POINT_FRACTIONAL_BITS 15

// Convert float to fixed-point Q15
int32_t float_to_fixed_point(float value);

// Convert fixed-point Q15 to float
float fixed_point_to_float(int32_t value);

// Multiply two fixed-point Q15 numbers
int32_t fixed_point_multiply(int32_t a, int32_t b);

// Divide two fixed-point Q15 numbers
int32_t fixed_point_divide(int32_t a, int32_t b);

#endif // FIXED_POINT_H