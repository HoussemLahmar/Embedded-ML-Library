# Guide d'Optimisation

Ce guide fournit des conseils pratiques pour optimiser la taille binaire, la mémoire, et les performances de la bibliothèque ML embarquée sur des microcontrôleurs tels que l'ESP32 ou STM32.

---

## 1. Réduction de la Taille Binaire

### a. Utilisation de l'option `-Os`
- Activez l'optimisation pour la taille dans votre compilateur.
- Pour GCC/Clang :
  ```bash
  -Os
  ```
- Dans **PlatformIO** :
  Ajoutez ceci à votre fichier `platformio.ini` :
  ```ini
  build_flags = -Os
  ```

### b. Supprimer les fonctions inutilisées
- Utilisez l'option `--gc-sections` pour supprimer les sections de code inutilisées.
- Exemple avec GCC :
  ```bash
  -ffunction-sections -fdata-sections -Wl,--gc-sections
  ```
- Dans **PlatformIO** :
  ```ini
  build_flags = -ffunction-sections -fdata-sections -Wl,--gc-sections
  ```

### c. Désactiver `printf` complet
- Les fonctions comme `printf` occupent beaucoup d'espace.
- Remplacez-les par des alternatives légères comme `Serial.print` ou `snprintf`.

---

## 2. Optimisation de la Mémoire

### a. Utilisation du Point Fixe
- Toutes les opérations mathématiques sont réalisées en **point fixe (Q15)** pour réduire l'utilisation de la mémoire et du CPU.
- Assurez-vous que vos données d'entrée sont normalisées pour rester dans la plage de -1 à +1 (Q15).

### b. Éliminer les allocations dynamiques
- La bibliothèque n'utilise pas de `malloc` ou d'autres allocations dynamiques. Si vous ajoutez du code, **évitez** également les allocations dynamiques.
- Pré-allouez toutes les structures de données au moment de l'initialisation.

### c. Réduire la taille des buffers
- Si vous utilisez des capteurs (comme IMU), limitez la taille des buffers à ce qui est strictement nécessaire.

---

## 3. Optimisation des Performances CPU

### a. Précalculer les constantes
- Si votre modèle a des poids fixes (par ex. pas de mise à jour en ligne), précalculez les résultats fréquents ou constants.
- Exemple :
  ```cpp
  const int32_t precalculated_bias = fixed_point_multiply(weight1, feature1);
  ```

### b. Utilisation d'opérations en ligne
- Préférez les macros ou les fonctions `inline` pour les opérations critiques comme les multiplications et divisions en point fixe.
- Exemple dans `fixed_point.h` :
  ```cpp
  static inline int32_t fixed_point_multiply_inline(int32_t a, int32_t b) {
      return (a * b) >> FIXED_POINT_FRACTIONAL_BITS;
  }
  ```

### c. Limiter les boucles
- Réduisez les boucles imbriquées autant que possible.
- Exemple : pour des modèles avec un faible nombre de caractéristiques, déroulez manuellement les boucles.

---

## 4. Gestion de l'Énergie

### a. Réduction de la fréquence CPU
- Diminuez la fréquence de l'horloge du microcontrôleur si les performances sont suffisantes.
- Exemple pour un ESP32 :
  ```cpp
  setCpuFrequencyMhz(80); // Réduit la fréquence à 80 MHz
  ```

### b. Mise en veille entre les prédictions
- Si votre application effectue des prédictions peu fréquentes, mettez le microcontrôleur en veille entre les cycles.
- Exemple pour un ESP32 :
  ```cpp
  esp_deep_sleep(1000000); // Mise en veille pendant 1 seconde
  ```

---

## 5. Gestion des Données

### a. Normalisation
- Normalisez vos données d'entrée pour qu'elles se situent dans la plage de -1 à 1 (convient au Q15).
- Utilisez des fonctions de prétraitement comme :
  ```cpp
  int32_t normalized_value = fixed_point_divide(raw_value - min_value, max_value - min_value);
  ```

### b. Extraction de Features
- Limitez le nombre de caractéristiques (features) utilisées par votre modèle pour réduire la charge CPU.
- Exemple : Si vous utilisez un IMU, concentrez-vous uniquement sur les données nécessaires (par ex. uniquement l'accélération sur X et Y).

---

## 6. Tests et Validation

### a. Tests unitaires
- Validez chaque fonction mathématique, comme `fixed_point_multiply`, avec des tests unitaires pour éviter les erreurs d'arrondi.

### b. Profiling
- Utilisez un profiler ou des outils comme **ESP-IDF Performance Monitor** pour mesurer le temps d'exécution de chaque fonction critique.

### c. Validation des modèles
- Vérifiez que les prédictions sur le microcontrôleur correspondent aux résultats obtenus lors de l'entraînement.

---

## 7. Cas Pratiques

### Exemple : Optimisation pour un ESP32
1. Activez les optimisations dans `platformio.ini` :
   ```ini
   build_flags = -Os -ffunction-sections -fdata-sections -Wl,--gc-sections
   monitor_speed = 115200
   ```
2. Limitez la fréquence CPU pour économiser l'énergie :
   ```cpp
   setCpuFrequencyMhz(80);
   ```
3. Utilisez des données normalisées en Q15 :
   ```cpp
   int32_t imu_data[3] = {float_to_fixed_point(0.5), float_to_fixed_point(-0.2), float_to_fixed_point(0.8)};
   ```

---

En suivant ce guide, vous pouvez minimiser la taille binaire, réduire la consommation mémoire et CPU, et maximiser la durée de vie de la batterie dans vos projets embarqués.

---