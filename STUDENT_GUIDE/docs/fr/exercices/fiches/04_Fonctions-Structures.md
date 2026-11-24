# Structures, fonctions & procédures (Algo + C)

> Énoncés uniquement. Consulter le PDF original pour les compléments.

## Exercice 1 — Point 2D et distance à l’origine

Énoncé. Définir `typedef struct {double x,y;} Point;` et écrire double `dist0(Point p)`.

## Exercice 2 — Translation d’un point (procédure)

Énoncé. Procédure `translater(Point* p, dx, dy)` qui modifie p.

## Exercice 3 — Rectangle : aire et périmètre

Énoncé. `typedef struct {double L,l;} Rect;` Fonctions `aire(r)`, `peri(r)`.

## Exercice 4 — Complexes : addition et module

Énoncé. `typedef struct {double re,im;} Cx;` `add(a,b)`, `module(a)`.

## Exercice 5 — Fraction : normaliser et additionner

Énoncé. `typedef struct {int num,den;} Frac;` pgcd, normalize, addf.

## Exercice 6 — Étudiant : init et affichage

Énoncé. `typedef struct {char nom[32]; double note;} Etu;` init, affiche.

## Exercice 7 — Meilleur étudiant (retour pointeur)

Énoncé. Retourner l’adresse de l’étudiant de note max `best(E,n)`.

## Exercice 8 — Tri d’étudiants par note (procédure)

Énoncé. `sort_note(E,n)` (bulle) croissant.

## Exercice 9 — Temps hh :mm :ss : normaliser et ajouter des secondes

Énoncé. `typedef struct {int h,m,s;} Time;` norm, addsec.

## Exercice 10 — Date : bissextile et jour de l’année

Énoncé. `typedef struct {int j,m,a;} Date;` isLeap, dayOfYear.

## Exercice 11 — RGB → niveaux de gris

Énoncé. `typedef struct {unsigned char r,g,b;} RGB;` toGray.

## Exercice 12 — Polynôme du second degré : évaluation

Énoncé. `typedef struct {double a,b,c;} Poly2;` `eval(p,x)`.

## Exercice 13 — Cercle : surface et appartenance d’un point

Énoncé. `typedef struct {Point c; double r;} Cercle;` aire, contient.

## Exercice 14 — Matrice 2×2 et produit matrice–vecteur

Énoncé. `typedef struct {double a11,a12,a21,a22;} Mat2;` `mul(Mat2,Point)`.

## Exercice 15 — Livre : recherche par auteur

Énoncé. `typedef struct {char titre[64], auteur[48]; int an;} Livre;` findByAuthor.

## Exercice 16 — Boîte 3D : volume et emboîtement

Énoncé. `typedef struct {double L,l,h;} Box;` volume, `can_nest(a,b)` (a dans b sans rotation).

## Exercice 17 — Statistiques : min, max, moyenne, variance

Énoncé. `typedef struct {double min,max,moy,var;} Stats;` `compute(T,n)`.

## Exercice 18 — Liste chaînée : insertion en tête et comptage

Énoncé. `typedef struct Node {int v; struct Node* next;} Node;` push_front, length.

## Exercice 19 — Personne avec date de naissance : âge

Énoncé. `typedef struct {char nom[32]; Date dn;} Person;` fonction `age(Person p, Date ref)`.

## Exercice 20 — Compte bancaire : dépôt/retrait sécurisés

Énoncé. `typedef struct {int id; double solde;} Compte;` depot, retrait (renvoie succès/échec).
