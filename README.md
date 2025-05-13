# ft\_printf

**ft\_printf** est une ré-implémentation de la fonction standard `printf` en C, réalisée dans le cadre du cursus 42.

---

## Table des matières

1. [Description](#description)
2. [Fonctionnalités](#fonctionnalités)
3. [Installation & Compilation](#installation--compilation)
4. [Utilisation](#utilisation)
5. [Structure du projet](#structure-du-projet)
6. [Principales fonctions](#principales-fonctions)
7. [Gestion des erreurs](#gestion-des-erreurs)
8. [Partie Bonus](#partie-bonus)
9. [Tests](#tests)
---

## Description

ft\_printf reproduit le comportement de `printf`, en gérant :

* Les conversions : `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, et `%%`.
* Flags : `-`, `0`, `+`, ` ` (espace), `#`.
* Champ de largeur (width) et précision (precision).
* Modificateurs de longueur : `hh`, `h`, `l`, `ll`, `j`, `z`, `t`.
* Gestion des `NULL` et des caractères spéciaux comme `\0`.

---

## Fonctionnalités

* **Conforme** à la norme 42 et aux spécifications de `printf`.
* **Modulaire** : parsing, handlers, utilitaires séparés.
* **Bonus** : support de tous les flags, width, precision et length.
* **Robuste** : prise en charge des cas d’erreur (allocation, format invalide).

---

## Installation & Compilation

1. Cloner ce dépôt :

   ```bash
   git clone https://github.com/<votre-utilisateur>/ft_printf.git
   cd ft_printf
   ```

2. Compiler sans la partie bonus :

   ```bash
   make
   ```

3. Compiler avec la partie bonus :

   ```bash
   make bonus
   ```

4. Générer l’exécutable de test :

   ```bash
   make program
   ```

5. Nettoyer la compilation :

   ```bash
   make clean    # supprime les .o
   make fclean   # supprime .o, la libftprintf.a et l’exécutable
   make re       # fclean + all
   ```

---

## Utilisation

```bash
# Exemple basique :
./program
```

Le binaire `program` exécute un `main.c` de test qui affiche tous les cas de figure :

* Caractères simples et spéciaux
* Chaînes (NULL, précision, alignment)
* Pointeurs
* Entiers signés et non signés
* Hexadécimal, majuscules/minuscules
* Literaux `%`
* Modificateurs de longueur

---

## Structure du projet

```
ft_printf/
├── parsing/                  # Analyseur de format
│   ├── parse_format.c
│   └── parse_*.c
├── handles/                  # Handlers pour chaque spécificateur
│   ├── handle_char.c
│   └── handle_*.c
├── get_value/                # Extraction des valeurs varargs
├── applys/                   # Application de width, precision, flags
├── utils/                    # Fonctions utilitaires (itoa, ft_mem*, ft_calloc…)
├── ft_printf.c               # Point d’entrée de la lib
├── ft_printf_bonus.h         # Prototypes pour la partie bonus
├── Makefile                  # Règles de compilation
└── main.c                    # Programme de démonstration/tests
```

---

## Principales fonctions

* **`parse_format`** : lit la chaîne de format et remplit une structure `t_printf`.
* **Handlers** : fonctions `handle_*` qui gèrent chaque conversion.
* **`apply_width`**, **`apply_precision`**, **`apply_length`** : adaptent la chaîne résultante.
* **Utilitaires** : `ft_itoa`, `ft_ulltoa_base`, `ft_calloc`, `ft_memcpy`, `ft_print_char`, etc.

---

## Gestion des erreurs

* Retourne le nombre de caractères affichés.
* En cas d’erreur d’allocation, arrête l’affichage et met `data->error`.
* Les handlers vérifient `data->error` avant de poursuivre.

---

## Partie Bonus

Activable via le flag `BONUS` dans le Makefile. Inclut le support complet de :

* Flags supplémentaires
* Champ de largeur et précision
* Modificateurs de longueur (`h`, `hh`, `l`, `ll`)

Pour compiler avec bonus :  `make bonus`.

---

## Tests

Le fichier `main.c` fournit un panel complet de cas de test. Tu peux l’exécuter :

```bash
./program
```

Pour ajouter tes propres tests, modifie `main.c` ou crée un nouveau script de test.

---
