# Tri, Recherche & Listes (Algo + C)

> **Prérequis du cours** : [6. Récursivité, §6.7 Tableaux et intervalles](../../cours/index.md#67-recursivite-sur-les-tableaux-et-les-intervalles) · [11. Callbacks et qsort](../../cours/index.md#11-fonctions-de-bibliotheque-callbacks-et-qsort) · [12. Listes chaînées](../../cours/index.md#12-listes-chainees) · [13. Recherche et tri](../../cours/index.md#13-recherche-et-tri).
> Exercices 8-20 : lire d'abord [Aller plus loin §§3-7](../../aller-plus-loin/index.md#3-choisir-un-tri) (tri, partition, tas, sélection, listes).
> Énoncés sans corrigé fourni. [PDF source](06_Tri-Recherche-Listes.pdf) : mêmes énoncés, conservé comme référence.

## Exercice 1 — Recherche séquentielle (index ou -1)

Énoncé. Lire n, un tableau d’entiers, et une clé x. Retourner l’indice (première occurrence) ou −1.

## Exercice 2 — Recherche dichotomique (tableau trié)

Énoncé. Sur un tableau trié croissant, chercher x.

## Exercice 3 — Min & Max en une passe

Énoncé. Trouver min et max d’un tableau d’entiers en une seule passe.

## Exercice 4 — Tri par sélection

Énoncé. Trier un tableau d’entiers par sélection.

## Exercice 5 — Tri par insertion

Énoncé. Implémenter l’insertion sort.

## Exercice 6 — Tri à bulles (optimisé)

Énoncé. Bubble sort avec arrêt anticipé si aucune permutation.

## Exercice 7 — Fusion de deux tableaux triés

Énoncé. Fusionner A et B triés en C trié.

Repère : la fusion est l'étape « combiner » du tri fusion, tracée en [§13 Recherche et tri](../../cours/index.md#13-recherche-et-tri).

## Exercice 8 — Tri fusion (merge sort)

Énoncé. Implémenter tri fusion récursif (stable).

Repère : avant d'écrire la division récursive, relire [§6.7 Récursivité sur les tableaux et les intervalles](../../cours/index.md#67-recursivite-sur-les-tableaux-et-les-intervalles) ; la mesure qui diminue est la taille de l'intervalle.

## Exercice 9 — Quicksort (partition de Lomuto)

Énoncé. Implémenter tri rapide avec pivot final.

## Exercice 10 — Tri par comptage (entiers dans [0..k])

Énoncé. Compter et reconstruire.

## Exercice 11 — Tri radix LSD (base 10, entiers ≥ 0)

Énoncé. Appliquer un comptage stable chiffre par chiffre.

## Exercice 12 — Tri par tas (heap sort)

Énoncé. Construire un tas max puis extraire.

## Exercice 13 — Quickselect (k-ième plus petit, 1-indexé)

Énoncé. Trouver l’élément d’ordre k sans trier tout.

## Exercice 14 — Retirer les doublons d’un tableau trié (inplace)

Énoncé. Compacter pour que chaque valeur apparaisse une seule fois. Retourner la nouvelle taille.

## Exercice 15 — Somme cible (two-sum) par deux pointeurs

Énoncé. Dans un tableau trié croissant, dire s’il existe i < j tel que a[i] + a[j] = S.

## Exercice 16 — Liste chaînée : insertion tête & queue

Énoncé. Implémenter push_front et push_back puis afficher.

## Exercice 17 — Liste : supprimer la première occurrence d’une valeur

Énoncé. `remove_first(&H, x)`.

## Exercice 18 — Liste : inversion (itérative)

Énoncé. `reverse(&H)` inverse la liste.

## Exercice 19 — Fusion de deux listes triées

Énoncé. Fusionner deux listes simplement chaînées triées (croissant).

## Exercice 20 — Détection de cycle (Floyd)

Énoncé. Détecter s’il existe un cycle dans une liste (tortue-lièvre).
