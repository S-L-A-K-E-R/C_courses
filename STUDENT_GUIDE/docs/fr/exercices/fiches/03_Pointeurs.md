# 20 Exercices — Pointeurs, Fonctions & Procédures (Algo + C)

> Énoncés uniquement. Consulter le PDF original pour les compléments.

## Exercice 1 — Pointeur de base et déréférencement

Énoncé. Lire un entier x, créer un pointeur p vers x, afficher x, l’adresse de x, puis incrémenter x via le pointeur et réafficher.

## Exercice 2 — Procédure d’échange (swap) par pointeurs

Énoncé. Écrire une procédure `echanger(a,b)` qui permute deux entiers.

## Exercice 3 — Min & Max par paramètres de sortie

Énoncé. Fonction qui trouve min et max d’un tableau en les retournant par paramètres de sortie.

## Exercice 4 — Somme et moyenne par itération de pointeur

Énoncé. Écrire `somme(T,n)` et `moyenne(T,n)` en avançant un pointeur.

## Exercice 5 — Inversion d’un tableau en place (deux pointeurs)

Énoncé. Inverser un tableau d’entiers en utilisant deux pointeurs gauche et droite.

## Exercice 6 — Longueur d’une chaîne (strlen maison)

Énoncé. Écrire `len(s)` qui compte jusqu’au caractère ’`\0`’.

## Exercice 7 — Copie de chaîne (strcpy maison)

Énoncé. Écrire `copier(dst,src)` qui recopie jusqu’à ’`\0`’.

## Exercice 8 — Compter les voyelles avec pointeurs

Énoncé. Retourner le nombre de voyelles dans une chaîne (sans casse).

## Exercice 9 — Retirer les espaces (deux pointeurs : lecture/écriture)

Énoncé. Supprimer tous les espaces d’une chaîne en place.

## Exercice 10 — Pointeur sur l’élément minimum

Énoncé. Retourner l’adresse du plus petit élément ; calculer ensuite son indice.

## Exercice 11 — Allocation dynamique et moyenne

Énoncé. Allouer dynamiquement n réels, les lire, calculer la moyenne, libérer.

## Exercice 12 — Matrice aplatie (indexation par pointeur)

Énoncé. Stocker une matrice N ×N dans un tableau 1D et écrire `get(A,N,i,j)` et `set(A,N,i,j,val)`.

## Exercice 13 — Ajout en fin de tableau dynamique (double pointeur)

Énoncé. Écrire `push_back(int **T,int *n,int v)` qui fait realloc et ajoute v.

## Exercice 14 — Appliquer une fonction à chaque élément (callback)

Énoncé. Écrire `appliquer(T,n,f)` où f est int `f(int)`.

## Exercice 15 — Tri avec qsort et pointeur de fonction de comparaison

Énoncé. Trier un tableau d’entiers en ordre croissant puis décroissant via deux comparateurs.

## Exercice 16 — Structure et pointeur sur structure

Énoncé. Définir struct Etudiant{nom[32]; note;} et une procédure `init(E,nom,note)`.

## Exercice 17 — Liste chaînée : insertion en tête

Énoncé. Implémenter `push_front(&tete, val)`.

## Exercice 18 — Découper une ligne par séparateur (tokens par pointeurs)

Énoncé. Transformer s en tokens séparés par ’,’ en plaçant des ’`\0`’ et stocker les adresses dans out[]. Retourner le nombre de tokens.

## Exercice 19 — Produit scalaire de deux vecteurs (pointeurs & const)

Énoncé. Écrire `dot(const int*A,const int*B,int n)` en itérant avec des pointeurs.

## Exercice 20 — Intégration trapèzes avec pointeur de fonction

Énoncé. Écrire `integrale(f,a,b,n)` (méthode des trapèzes) où f est double `f(double)`.
