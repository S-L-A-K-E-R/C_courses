# C — Cours de base

> Ce document est un support de révision original, organisé pour couvrir les thèmes des exercices de programmation C fournis. Il s'appuie sur les sujets du cours de Tatiana Aubonnet, sans reproduire ses diapositives.


## 0. Programmer et compiler

Un programme suit généralement ce cycle : comprendre le problème, définir les entrées/sorties, choisir un algorithme, coder, compiler, tester et corriger.


```bash
gcc -std=c11 -Wall -Wextra -Wpedantic -g main.c -o main
./main
```

- `-std=c11` : utiliser C11 pour la compatibilité ; `-std=c23` convient avec un compilateur compatible C23.
- `-Wall -Wextra -Wpedantic` : activer les avertissements utiles.
- `-g` : informations de débogage.

Le premier exemple est un programme complet. Les suivants sont des extraits : ajouter les en-têtes nécessaires (`<stdio.h>`, `<stdlib.h>`, `<stddef.h>`, `<stdint.h>`, `<string.h>`, `<limits.h>`) et placer les instructions dans une fonction.

Un programme minimal :

```c
#include <stdio.h>

int main(void) {
    printf("Hello, world!\n");
    return 0;
}
```

## 1. Variables, types et expressions

Une variable possède un type, un nom, une valeur et une durée de vie. En C, les types courants sont `char`, `int`, `long`, `float`, `double` et les types dérivés. Utiliser `sizeof(type)` pour connaître la taille en octets (elle dépend de la plateforme).

```c
int age = 18;
double moyenne = 14.25;
char lettre = 'A';
```

### Entrée et sortie

`printf` affiche ; `scanf` lit et doit recevoir l'adresse des variables à remplir.

```c
int n;
if (scanf("%d", &n) != 1) {
    fprintf(stderr, "Entrée invalide\n");
    return 1;
}
printf("n = %d\n", n);
```
Formats fréquents : `%d` / `%i` int, `%u` unsigned, `%ld` long, `%f` float/double à `printf`, `%lf` double à `scanf`, `%c` caractère, `%s` chaîne. Pour `printf`, un `double` se formate avec `%f`. Ne pas utiliser un format incompatible avec le type.

### Opérateurs

- Arithmétiques : `+ - * / %` (`%` pour entiers).
- Comparaison : `== != < <= > >=` (une comparaison produit 0 ou 1).
- Logiques : `&& || !` (court-circuit).
- Affectation : `=`, `+=`, `-=`, `*=`, `/=`.
- Incrément : `++i`, `i++` (la valeur de l'expression diffère dans certains contextes).
- Conversion : `int x = (int)3.8;` tronque vers zéro.

Attention à la division entière : `7 / 2` vaut `3`; `7.0 / 2` vaut `3.5`. Éviter les dépassements d'entiers et les divisions par zéro. Les priorités peuvent être rendues explicites avec des parenthèses.

## 2. Conditions et boucles

```c
if (x < 0) { /* ... */ }
else if (x == 0) { /* ... */ }
else { /* ... */ }
```

`switch` convient à une sélection parmi des valeurs discrètes; chaque `case` se termine généralement par `break`.

```c
for (int i = 0; i < n; ++i) { /* répétition connue */ }
while (condition) { /* répéter tant que vrai */ }
do { /* corps exécuté au moins une fois */ } while (condition);
```
`break` quitte la boucle ou le switch courant; `continue` passe à l'itération suivante. Vérifier les conditions d'arrêt pour éviter les boucles infinies.

[Fiche d'exercices — Variables, conditions et boucles](../exercices/fiches/01_Variables_Si_Boucles.md)

## 3. Algorithmes élémentaires

### Accumuler et compter

```c
int sum = 0;
for (int i = 1; i <= n; ++i) sum += i;
```

### Minimum, maximum et moyenne

Pour un tableau non vide, initialiser `min` et `max` à son premier élément, puis parcourir le reste. La moyenne se calcule avec une somme de type approprié et une division flottante : `(double)sum / n`. Ne jamais supposer que la somme tient forcément dans `int`.

### Échanger deux valeurs

```c
void swap_int(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
```

### Chiffres d'un entier

Le dernier chiffre d'un entier positif est `n % 10`; retirer ce chiffre avec `n /= 10`. Prévoir le cas zéro et les nombres négatifs, notamment `INT_MIN` qui ne peut pas être simplement nié dans un `int`.

## 4. Tableaux

Un tableau statique contient des éléments du même type contigus en mémoire. Ses indices vont de `0` à `n-1`.

```c
int values[5] = {4, 8, 1, 6, 3};
for (size_t i = 0; i < 5; ++i) printf("%d\n", values[i]);
```

Le C ne vérifie pas automatiquement les bornes. Tout accès hors limites est un comportement indéfini. Une fonction recevant un tableau doit aussi recevoir sa taille :

```c
void print_array(const int a[], size_t n);
```

### Tableaux multidimensionnels

```c
int matrix[2][3] = {{1,2,3},{4,5,6}};
```
Parcours : boucle sur les lignes, puis les colonnes. En mémoire, un tableau C est rangé en ordre row-major (ligne par ligne). Pour une matrice carrée aplatie de dimension `N`, l'élément `(i,j)` correspond à `a[i * N + j]`.

## 5. Fonctions et procédures

Une fonction encapsule une tâche et possède un type de retour. Une fonction `void` ne retourne pas de valeur. Les prototypes annoncent la signature avant utilisation.

```c
int max3(int a, int b, int c);

int max3(int a, int b, int c) {
    int m = (a > b) ? a : b;
    return (m > c) ? m : c;
}
```

Les arguments sont transmis par valeur : modifier un paramètre simple ne modifie pas la variable appelante. Pour modifier une variable de l'appelant, transmettre un pointeur. Les variables locales sont limitées à leur bloc. Éviter les variables globales pour l'état ordinaire.

### Plusieurs résultats

Le C retourne une valeur unique directement. Pour produire plusieurs résultats, utiliser des paramètres pointeurs de sortie, une structure retournée, ou remplir un tableau de sortie (le C ne retourne pas de tableau par valeur).

```c
void minmax(const int a[], size_t n, int *min, int *max);
```
Toujours vérifier les préconditions (par exemple `n > 0` et pointeurs valides).

[Fiche d'exercices — Fonctions](../exercices/fiches/02_Fonctions.md)

## 6. Récursivité

Une fonction récursive s'appelle elle-même. Elle doit avoir :
1. un cas de base qui s'arrête;
2. un appel sur un problème plus petit;
3. une progression vers le cas de base.

```c
unsigned long long factorial(unsigned n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}
```
Avec un `unsigned long long` de 64 bits, seules les factorielles de 0 à 20 sont représentables ; rejeter les valeurs supérieures ou utiliser une représentation plus grande. L'arithmétique non signée fonctionne modulo la plage du type. La récursion consomme la pile d'appels. Une profondeur trop grande peut épuiser la pile. Fibonacci naïf illustre la récursion, mais sa version récursive simple est très coûteuse; une version itérative est préférable pour calculer efficacement.

## 7. Pointeurs et adresses

Un pointeur contient une adresse d'objet (ou vaut `NULL`). `&x` donne l'adresse de `x`; `*p` accède à l'objet pointé.

```c
int x = 42;
int *p = &x;
*p = 50; // x devient 50
```

Ne déréférencer qu'un pointeur valide, correctement aligné et pointant vers un objet vivant. `NULL` est une valeur sentinelle, pas une adresse utilisable. `%p` affiche une adresse : passer `(void *)p`.

### Arithmétique de pointeurs

Si `p` pointe sur un élément d'un tableau, `p + 1` désigne l'élément suivant. L'arithmétique n'est valide qu'à l'intérieur du tableau ou juste après sa fin (sans déréférencer cette dernière position). L'indice `a[i]` équivaut à `*(a + i)`.

```c
const int *p = a;
for (size_t i = 0; i < n; ++i, ++p) { /* lire *p */ }
```

### `const` avec pointeurs

- `const int *p` : on ne modifie pas l'int via `p`.
- `int *const p` : l'adresse stockée dans `p` ne change pas.
- `const int *const p` : ni l'adresse ni la valeur pointée ne changent via ce nom.

[Fiche d'exercices — Pointeurs](../exercices/fiches/03_Pointeurs.md)

## 8. Chaînes de caractères

Une chaîne C est un tableau de `char` terminé par `\0`. Sa capacité doit inclure ce caractère terminal.

```c
char name[16] = "Ada";
```
`strlen` compte les octets avant `\0` (pas les caractères Unicode en UTF-8) (sans compter le terminateur). `strcmp` compare lexicographiquement; `strcpy` copie mais exige que la destination soit assez grande; `strcat` ajoute et exige aussi une capacité suffisante. Préférer des opérations dont la taille est contrôlée, et vérifier les retours des fonctions d'entrée.

Pour lire une ligne :
```c
char line[128];
if (fgets(line, sizeof line, stdin) != NULL) { /* traiter */ }
```
Attention : `fgets` peut conserver le `\n`; la ligne peut être tronquée si le tampon est trop petit. Les chaînes manipulées en place peuvent utiliser deux pointeurs : lecture et écriture, avec l'écriture toujours à une position ≤ lecture.

## 9. Allocation dynamique

`malloc` réserve des octets; `calloc` réserve et initialise à zéro; `realloc` ajuste une réservation; `free` libère. Les fonctions d'allocation retournent `NULL` en cas d'échec.

```c
size_t n = 10;
int *a = malloc(n * sizeof *a);
if (a == NULL) return 1;
/* utiliser a */
free(a);
a = NULL;
```

Toujours vérifier les calculs de taille (risque de débordement), la réussite de l'allocation et libérer chaque allocation exactement une fois. `realloc` : utiliser un pointeur temporaire pour ne pas perdre l'ancien bloc en cas d'échec.

```c
/* a vaut NULL ou possède un bloc ; new_n est de type size_t. */
if (new_n == 0) {
    free(a);
    a = NULL;
} else if (new_n > SIZE_MAX / sizeof *a) {
    /* Gérer le débordement ; a reste inchangé. */
} else {
    int *tmp = realloc(a, new_n * sizeof *a);
    if (tmp != NULL) {
        a = tmp;
    } else {
        /* Gérer l'échec ; a reste valide. */
    }
}
```

Inclure `<stdlib.h>` et `<stdint.h>`. Mettre à jour la taille/capacité logique uniquement après réussite. Un `realloc` de taille nulle a un comportement indéfini en C23.

Un tableau dynamique à deux dimensions peut être représenté par un tableau de pointeurs (allocations séparées) ou par un bloc contigu. Le bloc contigu simplifie la libération et la localité mémoire.

## 10. Structures et `typedef`

Une structure regroupe des champs de types différents.

```c
typedef struct {
    char name[32];
    double grade;
} Student;
Student s = {"Sam", 15.5};
```
Accéder aux champs avec `s.grade`; via un pointeur, utiliser `p->grade` (équivalent à `(*p).grade`). Les structures peuvent être passées par valeur ou par adresse. Utiliser un pointeur quand la fonction doit modifier l'objet ou éviter une copie.

Structures courantes en exercices : point, rectangle, complexe, fraction, date, temps, étudiant, livre, compte, statistiques. Vérifier les invariants (ex. dénominateur non nul pour une fraction, solde et montants cohérents).

[Fiche d'exercices — Structures](../exercices/fiches/04_Fonctions-Structures.md)

## 11. Fonctions de bibliothèque, callbacks et `qsort`

Une fonction peut recevoir un pointeur vers une autre fonction (callback). Signature typique :

```c
int apply_one(int value, int (*f)(int));
```

`qsort` de `<stdlib.h>` prend une fonction de comparaison :

```c
int compare_ints(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;
    return (x > y) - (x < y); // éviter x-y, qui peut déborder
}
```
Le comparateur retourne un nombre négatif, zéro ou positif. Ne pas retourner `x-y` pour des valeurs extrêmes. Pour ordre décroissant, inverser la logique de comparaison sans risque de débordement.

[Fiche d'exercices — Callbacks et qsort](../exercices/fiches/03_Pointeurs.md)

## 12. Listes chaînées

Une liste simplement chaînée est constituée de nœuds contenant une donnée et un pointeur vers le nœud suivant. La tête peut être `NULL`.

```c
typedef struct Node {
    int value;
    struct Node *next;
} Node;
```

- insertion en tête : nouveau nœud pointe vers l'ancienne tête, puis la tête change;
- insertion en queue : parcourir jusqu'au dernier nœud, ou conserver un pointeur de queue;
- suppression : relier le précédent au suivant et libérer le nœud retiré;
- longueur : parcourir en comptant;
- inversion : maintenir `prev`, `current`, `next`;
- fusion de listes triées : avancer les deux curseurs en choisissant le plus petit;
- cycle : tortue-lièvre de Floyd, deux pointeurs avançant à vitesses différentes.

Les fonctions qui modifient la tête doivent recevoir `Node **head` ou retourner la nouvelle tête. Ne jamais utiliser un nœud après `free`.

[Fiche d'exercices — Listes chaînées](../exercices/fiches/06_Tri-Recherche-Listes.md)

## 13. Recherche et tri

### Recherches
- Séquentielle : parcourir chaque élément, `O(n)`.
- Dichotomique : tableau trié requis; réduire l'intervalle à chaque étape, `O(log n)`.
- Min/max : un seul parcours, `O(n)`.
- Two-sum par deux pointeurs : sur tableau trié, déplacer gauche/droite selon la somme.

### Tris de base
- Sélection : choisir le minimum de la partie non triée, `O(n²)`.
- Insertion : insérer chaque élément dans le préfixe trié, `O(n²)` au pire, stable.
- Bulles : échanges adjacents; arrêt anticipé si aucune permutation, `O(n²)` au pire.

### Tris avancés vus dans le périmètre
- Merge sort : diviser, trier, fusionner; `O(n log n)`, stable, mémoire auxiliaire.
- Quicksort : partitionner autour d'un pivot; moyenne `O(n log n)`, pire `O(n²)`.
- Counting sort : adapté à une plage entière limitée `[0,k]`; `O(n+k)`.
- Radix LSD : traiter les chiffres de droite à gauche avec un tri stable; adapté aux entiers non négatifs dans sa forme simple.
- Heap sort : construire un tas max, extraire; `O(n log n)`, en place, non stable.
- Quickselect : partitionner pour trouver le k-ième élément, sans trier tout le tableau.
- Déduplication : compacter les valeurs uniques d'un tableau trié en place.

[Fiche d'exercices — Tri et recherche](../exercices/fiches/06_Tri-Recherche-Listes.md)

## 14. Fichiers

Les flux standard : `stdin`, `stdout`, `stderr`. Un fichier se manipule avec `FILE *` et `fopen`.

```c
FILE *f = fopen("data.txt", "r");
if (f == NULL) { perror("data.txt"); return 1; }
/* lecture */
if (fclose(f) != 0) { /* gérer erreur */ }
```
Modes : `r` lecture, `w` écriture/écrasement, `a` ajout; suffixe `b` pour binaire (`rb`, `wb`, etc.); `+` pour lecture/écriture. Vérifier chaque ouverture, lecture, écriture et fermeture.

- Texte : `fgets`, `fprintf`, `fputs`, `fgetc`.
- Binaire : `fread`, `fwrite`; ces opérations transfèrent des octets, pas un format portable universel pour structures (padding, endianness, tailles des types).
- Copier : boucle de lecture avec tampon puis écriture.
- CSV simple : parser une ligne et convertir en vérifiant les erreurs; CSV réel peut contenir guillemets et séparateurs échappés, donc un simple `strtok` ne gère pas tout.
- `fseek`, `ftell` : déplacement et position dans les fichiers, sous réserve du mode et du type de fichier.
- Gestion d'erreurs : vérifier `ferror`, `feof` dans la bonne logique, et les retours des fonctions.

[Fiche d'exercices — Fichiers](../exercices/fiches/05_Fichiers.md)

## 15. Checklist : domaines couverts

- [x] Variables, conversions, expressions, I/O, conditions, boucles
- [x] Tableaux 1D/2D, somme, moyenne, min/max, matrice, trace/transposition
- [x] Fonctions, procédures, paramètres de sortie, récursivité
- [x] Pointeurs, pointeurs doubles, `const`, arithmétique, callbacks
- [x] Chaînes, longueur, copie, recherche, tokenisation, manipulation en place
- [x] Allocation, réallocation, libération, tableaux dynamiques
- [x] Structures, tableaux de structures, pointeurs sur structures
- [x] Listes chaînées : opérations, fusion, inversion, cycle
- [x] Recherche, tris, sélection, déduplication
- [x] Fichiers texte et binaires, CSV simple, copie, transformation, statistiques


## 16. Exercices de calcul et de chaînes à connaître

### PGCD, PPCM et nombres premiers

Le PGCD peut se calculer par l'algorithme d'Euclide : tant que `b != 0`, remplacer `(a,b)` par `(b,a%b)`. Le dernier `a` non nul est le PGCD. Le PPCM (si les valeurs sont traitées sans débordement) est `a / pgcd(a,b) * b` ; diviser avant de multiplier réduit le risque de dépassement.

Pour tester la primalité de `n`, traiter les cas `n < 2`, puis essayer les diviseurs tant que `d <= n / d`, en partant de 2 (évite le débordement de multiplication). Le prochain premier consiste à avancer et retester.

### Racines d'un trinôme

Pour `ax² + bx + c = 0`, si `a == 0`, traiter une équation linéaire. Sinon calculer `Δ = b² - 4ac`. `Δ > 0` donne deux racines réelles, `Δ == 0` une racine double, `Δ < 0` aucune racine réelle. Vérifier les divisions et les limites numériques.

### Variance et écart-type

Pour une population de `n` valeurs, la moyenne est `μ = Σxᵢ/n`; la variance population est `Σ(xᵢ-μ)²/n`, et l'écart-type est la racine carrée de la variance. Une formule en deux passes est simple à comprendre. Pour de grandes données ou valeurs très proches, une méthode numérique plus stable peut être préférable.

### Palindrome et inversion de chaîne

Comparer les caractères depuis les deux extrémités en progressant vers le centre. Si l'exercice ignore espaces et casse, normaliser chaque caractère avant comparaison. Pour inverser en place, échanger les caractères aux extrémités jusqu'à ce que les curseurs se croisent; la chaîne doit être modifiable.

[Fiche d'exercices — Calculs et chaînes](../exercices/fiches/01_Variables_Si_Boucles.md)

## 17. Structures courantes : règles et validations

- **Point / rectangle / cercle / boîte** : calculs géométriques; vérifier dimensions et rayons non négatifs.
- **Complexe** : addition champ par champ; module `sqrt(re*re + im*im)`.
- **Fraction** : dénominateur non nul; normaliser avec PGCD; garder un signe cohérent (par exemple dénominateur positif).
- **Date** : tester année bissextile; valider le nombre de jours du mois; calculer le jour de l'année par somme des mois précédents.
- **Temps** : normaliser secondes/minutes en reportant les dépassements; définir si les heures sont modulo 24.
- **RGB** : chaque canal sur 8 bits est compris entre 0 et 255 (`unsigned char` n'a pas nécessairement 8 bits ; utiliser `uint8_t` si disponible ou valider la plage); conversion en gris doit préciser la formule/approximation utilisée.
- **Polynôme** : évaluer `a*x*x + b*x + c`.
- **Statistiques** : calculer min/max/moyenne/variance en parcourant les données et traiter `n == 0`.
- **Compte bancaire** : vérifier montants positifs, fonds suffisants pour retrait, et succès/échec clairement signalé. Pour de vrais montants monétaires, éviter les calculs naïfs en `double`.

## 18. Matrices et tableaux dynamiques : opérations supplémentaires

La trace d'une matrice carrée est la somme de sa diagonale `A[i][i]`. La transposition échange `A[i][j]` avec `A[j][i]` pour `j > i` dans une matrice carrée en place. Le produit matrice-vecteur calcule chaque ligne par somme des produits. Pour une matrice aplatie, toujours utiliser une formule d'indexation unique et documenter la dimension.

Pour `push_back` sur un tableau dynamique, si la capacité est pleine, augmenter la capacité (souvent par doublement), utiliser `realloc` via un pointeur temporaire, puis ajouter l'élément et mettre à jour la taille. Distinguer `size` (éléments utilisés) de `capacity` (espace réservé).

## 19. Liste de vérification détaillée des exercices

Cette liste regroupe les sujets visibles dans les six PDF d'exercices : affichage et calculs, conversion Celsius/Fahrenheit, maxima, pair/impair, racines, tables, factorielle, Fibonacci, somme de 1 à n, chiffres inversés/compte des chiffres, primalité, PGCD/PPCM, fonctions et récursivité, somme/moyenne/min/max, recherches séquentielle et dichotomique, tris sélection/insertion/bulles/fusion/rapide/comptage/radix/tas, quickselect, déduplication, two-sum, pointeurs et paramètres de sortie, chaînes (longueur/copie/voyelles/espaces/palindrome/inversion/tokenisation), matrices (trace/transposition/produit/indexation aplatie), callbacks et `qsort`, structures (point, rectangle, complexe, fraction, étudiant, temps, date, RGB, polynôme, cercle, matrice, livre, boîte, statistiques, personne, compte), listes (insertion tête/queue, suppression, longueur, inversion, fusion, cycle), fichiers (texte, append, copie binaire, compteurs, motifs, remplacement, fusion triée, CSV, données binaires, structures binaires, découpage, tri/dédoublonnage, comparaison, tail, CRLF/LF, checksum, histogramme octets, reverse et préfixe).

[Pratiquer avec les exercices](../exercices/index.md)


---

## Crédit et provenance

Support de révision réalisé à partir du cours de **Tatiana Aubonnet** (C, 2008), en s'appuyant principalement sur les exercices partagés par [**S-L-A-K-E-R**](https://github.com/S-L-A-K-E-R), qui ont particulièrement contribué à définir les notions abordées et la structure de ce support.

Adaptation, organisation et rédaction : [**1KuMo**](https://github.com/1KuMo).

Des outils d'intelligence artificielle ont également été utilisés pour assister la traduction, la mise en page et l'organisation du contenu.

Merci à **Tatiana Aubonnet** pour son cours original, qui a servi de base à ce travail.
