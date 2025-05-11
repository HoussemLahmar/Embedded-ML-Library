#ifndef PREPROCESS_H
#define PREPROCESS_H

#include <cstdint> // Pour int32_t

// Fonction de normalisation en point fixe Q15
int32_t normalize(int32_t value, int32_t min_value, int32_t max_value);

#endif // PREPROCESS_H