# Structure des fichiers et architecture

## 1. Architecture globale
```
ml_embedded_library/
├── include/                         # Headers publics de la bibliothèque
│   ├── ml_embedded.h                # API principale
│   ├── linear_regression.h          # Modèle : Régression linéaire
│   ├── logistic_regression.h        # Modèle : Régression logistique
│   ├── svm.h                        # Modèle : SVM linéaire
│   ├── fixed_point.h                # Fonctions pour point fixe
│   └── preprocess.h                 # Prétraitement des données
├── src/                             # Implémentations
│   ├── ml_embedded.cpp              # Implémentation principale
│   ├── linear_regression.cpp        # Implémentation de la régression linéaire
│   ├── logistic_regression.cpp      # Implémentation de la régression logistique
│   ├── svm.cpp                      # Implémentation du SVM
│   ├── fixed_point.cpp              # Fonctions pour point fixe (add/mul)
│   └── preprocess.cpp               # Normalisation et extraction de features
├── tools/                           # Scripts Python pour entraînement et codegen
│   ├── train.py                     # Script d'entraînement (en Python)
│   ├── codegen.py                   # Générateur de code C/C++
│   └── data_acquisition.py          # Collecte de données depuis capteurs
├── examples/                        # Exemples d'intégration sur ESP32
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

## 2. Rôles des composants principaux

### Headers publics (`include/`)
- **ml_embedded.h** : Interface principale pour charger les modèles, exécuter l'inférence, etc.
- **linear_regression.h** : Interface pour la régression linéaire.
- **logistic_regression.h** : Interface pour la régression logistique.
- **svm.h** : Interface pour le SVM linéaire.
- **fixed_point.h** : Opérations mathématiques optimisées pour le point fixe.
- **preprocess.h** : Normalisation, extraction de features, etc.

### Implémentations (`src/`)
- Contient les définitions des algorithmes et des fonctions d'inférence.
- Les fonctions sont optimisées pour être légères (pas d'allocation dynamique, utilisation du point fixe).

### Scripts Python (`tools/`)
- **train.py** : Entraîne les modèles (régression linéaire, logistique, SVM).
- **codegen.py** : Génère des fichiers `.h` et `.cpp` contenant les poids appris pour les modèles.
- **data_acquisition.py** : Collecte les données depuis des capteurs (IMU, etc.).

### Exemples (`examples/`)
- Démonstration pratique pour ESP32 avec PlatformIO.
- Exemple d'utilisation pour classification d'activités avec un capteur IMU.

### Tests (`tests/`)
- Tests unitaires pour chaque module de la bibliothèque.
- Validation des performances et vérification des résultats.

### Build scripts
- **CMakeLists.txt** : Configuration pour cross-compilation (ARM Cortex-M, ESP32, etc.).
- **Makefile** : Build simple pour les utilisateurs n'utilisant pas CMake.

### Documentation
- **README.md** : Instructions pour l'installation, l'entraînement et l'inférence.
- Guide pour optimiser les performances sur microcontrôleurs (point fixe, pas de heap).

---

Prochaine étape : Implémenter le moteur d'inférence pour la régression linéaire.