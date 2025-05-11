# Structure des fichiers et architecture

## 1. Architecture globale

```
ml_embedded_library/
├── include/                         # Headers publics de la bibliothèque
│   ├── ml_library.h                 # API principale pour les modèles ML
│   ├── linear_regression.h          # Modèle : Régression linéaire
│   ├── logistic_regression.h        # Modèle : Régression logistique
│   ├── svm.h                        # Modèle : SVM linéaire
│   ├── fixed_point.h                # Fonctions pour point fixe
│   ├── preprocess.h                 # Prétraitement des données
│   └── io_library.h                 # Bibliothèque d'E/S pour capteurs/actionneurs
├── src/                             # Implémentations
│   ├── ml_library.c                 # Implémentation principale (C uniquement)
│   ├── linear_regression.cpp        # Implémentation de la régression linéaire
│   ├── logistic_regression.cpp      # Implémentation de la régression logistique
│   ├── svm.cpp                      # Implémentation du SVM
│   ├── fixed_point.cpp              # Fonctions pour point fixe (add/mul/div)
│   ├── preprocess.cpp               # Normalisation et extraction de features
│   └── io_library.cpp               # Communication avec capteurs/actionneurs
├── examples/                        # Exemples d'intégration sur microcontrôleur
│   ├── imu_classification/          # Exemple : classification avec IMU
│   │   ├── src/
│   │   │   ├── main.cpp             # Exemple principal
│   │   ├── platformio.ini           # Configuration PlatformIO pour ESP32
├── tests/                           # Tests unitaires
│   ├── test_linear_regression.cpp   # Tests pour la régression linéaire
│   ├── test_logistic_regression.cpp # Tests pour la régression logistique
│   ├── test_svm.cpp                 # Tests pour le SVM
│   ├── test_fixed_point.cpp         # Tests pour les fonctions de point fixe
│   └── test_preprocess.cpp          # Tests pour le prétraitement
├── CMakeLists.txt                   # Configuration CMake pour cross-compilation
├── Makefile                         # Alternative : Makefile simple
└── README.md                        # Documentation de la bibliothèque et procédure
```

---

## 2. Rôles des composants principaux

### Headers publics (`include/`)
- **ml_library.h** : Interface principale pour charger les modèles, exécuter l'inférence, et entraîner en temps réel.
- **linear_regression.h** : Interface pour la régression linéaire (entraînement et inférence).
- **logistic_regression.h** : Interface pour la régression logistique (entraînement et inférence).
- **svm.h** : Interface pour le SVM linéaire (entraînement et inférence).
- **fixed_point.h** : Fonctions mathématiques optimisées pour les calculs en point fixe.
- **preprocess.h** : Fonctions pour la normalisation et l'extraction de features.
- **io_library.h** : Bibliothèque pour interagir avec les capteurs et les actionneurs (ADC, PWM, GPIO, etc.).

---

### Implémentations (`src/`)
- **ml_library.c** : Implémentation principale en C, compatible avec les microcontrôleurs à mémoire limitée.
- **linear_regression.cpp** : Algorithme de régression linéaire, optimisé pour les calculs en point fixe.
- **logistic_regression.cpp** : Algorithme de régression logistique, avec une approximation sigmoid simple.
- **svm.cpp** : Algorithme de SVM linéaire, optimisé pour la classification binaire avec des valeurs en point fixe.
- **fixed_point.cpp** : Fonctions mathématiques pour la multiplication, la division et la conversion en point fixe.
- **preprocess.cpp** : Fonctions de normalisation et de traitement des données.
- **io_library.cpp** : Lecture des capteurs (via ADC) et écriture vers les actionneurs (via PWM/DAC).

---

### Exemples (`examples/`)
- **imu_classification/** : Exemple d'intégration pour une classification basée sur des données IMU (accéléromètre, gyroscope).
  - **main.cpp** : Exécute la collecte de données depuis un capteur IMU, entraîne un modèle en temps réel, et utilise la prédiction pour contrôler un actionneur.
  - **platformio.ini** : Configuration pour ESP32 avec PlatformIO.

---

### Tests (`tests/`)
- Tests unitaires pour chaque module de la bibliothèque :
  - **test_linear_regression.cpp** : Vérifie l'entraînement et l'inférence pour la régression linéaire.
  - **test_logistic_regression.cpp** : Vérifie l'entraînement et l'inférence pour la régression logistique.
  - **test_svm.cpp** : Vérifie l'entraînement et l'inférence pour le SVM.
  - **test_fixed_point.cpp** : Vérifie les fonctions mathématiques en point fixe.
  - **test_preprocess.cpp** : Vérifie les fonctions de normalisation et de traitement des données.

---

### Build scripts
- **CMakeLists.txt** :
  - Configure la compilation croisée pour les microcontrôleurs comme ARM Cortex-M ou ESP32.
  - Permet de compiler les tests et les exemples de manière modulaire.
- **Makefile** :
  - Build simple pour les utilisateurs qui préfèrent un script Make classique.

---

### Documentation
- **README.md** :
  - Guide pour installer, utiliser et déployer la bibliothèque.
  - Instructions pour entraîner des modèles en temps réel sur des microcontrôleurs.
- **OPTIMIZATION_GUIDE.md** (fichier suggéré) :
  - Conseils pour réduire la taille binaire, optimiser l'utilisation de la mémoire, et maximiser les performances CPU.

---

## 3. Flux de travail recommandé

1. **Configuration de la bibliothèque** :
   - Configurez les fichiers `microcontroller_config.h` pour votre architecture (ESP32, STM32, etc.).
   - Définissez les tailles de mémoire maximales, la résolution ADC/PWM, etc.

2. **Développement sur microcontrôleur** :
   - Intégrez les capteurs et les actionneurs avec `io_library.h`.
   - Utilisez les modèles ML (régression linéaire, SVM, etc.) pour collecter des données, entraîner, et prédire.

3. **Test unitaire** :
   - Validez chaque module avec les fichiers de tests unitaires dans `tests/`.

4. **Exemple pratique** :
   - Exécutez les exemples dans le répertoire `examples/` pour valider l'intégration complète avec un microcontrôleur.

---

Prochaine étape : Mettre à jour le `Makefile` et les fichiers de configuration pour refléter cette architecture. Si vous avez des besoins spécifiques, n'hésitez pas à les mentionner !