# Fonctions & Procédures (Algo + C)

> **Prérequis du cours** : [1. Variables, types et expressions](../../cours/index.md#1-variables-types-et-expressions) · [4. Tableaux](../../cours/index.md#4-tableaux) · [5. Fonctions et procédures](../../cours/index.md#5-fonctions-et-procedures) · [6. Récursivité](../../cours/index.md#6-recursivite) · [7. Pointeurs](../../cours/index.md#7-pointeurs-et-adresses) · [8. Chaînes](../../cours/index.md#8-chaines-de-caracteres) · [13. Recherche et tri](../../cours/index.md#13-recherche-et-tri).

> Énoncés sans corrigé fourni. [PDF source](02_Fonctions.pdf) : mêmes énoncés, conservé comme référence.

!!! note "Préparation aux exercices 5-8 — récursivité"
    Avant d'écrire du code, complétez ce questionnaire pour `fact`, `fib`, `pow_int` et `pgcd` :

    1. Quel est le contrat de la fonction en une phrase ?
    2. Quel est son cas de base ? Est-il atteignable depuis tout appel valide ?
    3. Quelle mesure diminue strictement à chaque appel ? Voir [§6.3 Progression et terminaison](../../cours/index.md#63-progression-et-terminaison).
    4. Quelle opération reste en attente pendant la descente ? Voir [§6.4 Pile d'appels](../../cours/index.md#64-pile-dappels-descente-et-retour).
    5. Tracez ensuite `fact(3)` sur papier, sans écrire le corps de la fonction.

    Pièges à repérer sans les corriger ici : `fact(n)` qui appelle `fact(n)`, un test `n != 1` avec `n == 0`, un appel récursif dont le résultat est ignoré, et une récurrence à deux appels qui recalcule les mêmes sous-problèmes. Méthode complète : [§6.9 Erreurs fréquentes et méthode de débogage](../../cours/index.md#69-erreurs-frequentes-et-methode-de-debogage).

## Exercice 1 — Fonction linéaire

Énoncé. Écrire une fonction `f (x)` = 3x + 2 qui retourne la valeur pour un entier x.

## Exercice 2 — Procédure d’échange (swap)

Énoncé. Écrire une procédure qui échange deux entiers.

## Exercice 3 — Prédicat pair

Énoncé. Écrire `est_pair(n)` qui renvoie 1 si n est pair, 0 sinon (ou un `bool` avec `<stdbool.h>`).

## Exercice 4 — Maximum de trois (fonction)

Énoncé. Écrire `max3(a,b,c)`.

## Exercice 5 — Factorielle (récursif)

Énoncé. Écrire `fact(n)` récursive (n ≥ 0).

## Exercice 6 — Fibonacci (récursif)

Énoncé. Écrire `fib(n)` avec `fib(0) = 0`, `fib(1) = 1` puis `fib(n) = fib(n-1) + fib(n-2)`.

## Exercice 7 — Puissance rapide (exponentiation dichotomique)

Énoncé. Écrire `pow_int(a,n)` pour entiers a, n ≥ 0. Récurrence : `pow_int(a,0) = 1` ; si n est pair, `pow_int(a,n) = pow_int(a*a,n/2)` ; sinon `a * pow_int(a,n-1)`.

## Exercice 8 — PGCD (Euclide récursif)

Énoncé. Écrire `pgcd(a,b)` récursif.

## Exercice 9 — PPCM via PGCD

Énoncé. Écrire `ppcm(a,b)` utilisant pgcd.

## Exercice 10 — Somme et moyenne d’un tableau

Énoncé. Fonctions `somme(T,n)` et `moyenne(T,n)`.

## Exercice 11 — Min & Max par paramètres de sortie (procédure)

Énoncé. Procédure `minmax(T,n, min, max)`.

## Exercice 12 — Recherche séquentielle

Énoncé. `index_of(T,n,x)` renvoie l’indice ou −1.

## Exercice 13 — Recherche dichotomique (tableau trié)

Énoncé. `bsearch_int(T,n,x)` renvoie l’indice ou −1.

## Exercice 14 — Tri à bulles (procédure)

Énoncé. Procédure `bubble_sort(T,n)`.

## Exercice 15 — Compte de voyelles (fonction chaîne)

Énoncé. `nb_voyelles(s)` ignore la casse.

## Exercice 16 — Palindrome (fonction)

Énoncé. `est_palindrome(s)` (on ignore espaces et casse).

## Exercice 17 — Inversion de chaîne (procédure)

Énoncé. `inverser(s)` inverse une chaîne en place.

## Exercice 18 — Matrice : trace (fonction) et transposition (procédure)

Énoncé. Pour une matrice carrée N × N , écrire `trace(A,N)` et `transpose(A,N)`.

## Exercice 19 — Variance (fonction)

Énoncé. Écrire `variance(T,n)` (variance population) et ecart_type.

## Exercice 20 — Test de primalité & prochain premier

Énoncé. Écrire `est_premier(n)` et `prochain_premier(n)`.
