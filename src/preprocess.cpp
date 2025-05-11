#include "preprocess.h"
#include "fixed_point.h" // Pour les fonctions en point fixe

int32_t normalize(int32_t value, int32_t min_value, int32_t max_value) {
    // Normalisation en point fixe Q15 : (value - min) / (max - min)
    int32_t range = max_value - min_value;
    return fixed_point_divide(value - min_value, range);
}