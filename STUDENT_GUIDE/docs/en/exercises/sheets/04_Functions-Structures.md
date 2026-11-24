# Structures, Functions & Procedures (Algo + C)

> Exercise statements only. Refer to the original PDF for the accompanying material.

## Exercise 1 — 2D Point and Distance to the Origin

Statement. Define `typedef struct {double x,y;} Point;` and write double `dist0(Point p)`.

## Exercise 2 — Translation of a Point (Procedure)

Statement. Procedure `translater(Point* p, dx, dy)` that modifies p.

## Exercise 3 — Rectangle: Area and Perimeter

Statement. `typedef struct {double L,l;} Rect;` Functions `aire(r)`, `peri(r)`.

## Exercise 4 — Complex Numbers: Addition and Modulus

Statement. `typedef struct {double re,im;} Cx;` `add(a,b)`, `module(a)`.

## Exercise 5 — Fraction: Normalize and Add

Statement. `typedef struct {int num,den;} Frac;` pgcd, normalize, addf.

## Exercise 6 — Student: Init and Display

Statement. `typedef struct {char nom[32]; double note;} Etu;` init, affiche.

## Exercise 7 — Best Student (Pointer Return)

Statement. Return the address of the student with the highest grade `best(E,n)`.

## Exercise 8 — Sorting Students by Grade (Procedure)

Statement. `sort_note(E,n)` (bubble sort) ascending.

## Exercise 9 — Time hh:mm:ss: Normalize and Add Seconds

Statement. `typedef struct {int h,m,s;} Time;` norm, addsec.

## Exercise 10 — Date: Leap Year and Day of the Year

Statement. `typedef struct {int j,m,a;} Date;` isLeap, dayOfYear.

## Exercise 11 — RGB →-> Grayscale Levels

Statement. `typedef struct {unsigned char r,g,b;} RGB;` toGray.

## Exercise 12 — Quadratic Polynomial: Evaluation

Statement. `typedef struct {double a,b,c;} Poly2;` `eval(p,x)`.

## Exercise 13 — Circle: Surface and Point Inclusion

Statement. `typedef struct {Point c; double r;} Cercle;` aire, contient.

## Exercise 14 — 2×2 Matrix and Matrix–Vector Product

Statement. `typedef struct {double a11,a12,a21,a22;} Mat2;` `mul(Mat2,Point)`.

## Exercise 15 — Book: Search by Author

Statement. `typedef struct {char titre[64], auteur[48]; int an;} Livre;` findByAuthor.

## Exercise 16 — 3D Box: Volume and Nesting

Statement. `typedef struct {double L,l,h;} Box;` volume, `can_nest(a,b)` (a inside b without rotation).

## Exercise 17 — Statistics: Min, Max, Mean, Variance

Statement. `typedef struct {double min,max,moy,var;} Stats;` `compute(T,n)`.

## Exercise 18 — Linked List: Push Front and Count

Statement. `typedef struct Node {int v; struct Node* next;} Node;` push_front, length.

## Exercise 19 — Person with Birth Date: Age

Statement. `typedef struct {char nom[32]; Date dn;} Person;` function `age(Person p, Date ref)`.

## Exercise 20 — Bank Account: Secure Deposit/Withdrawal

Statement. `typedef struct {int id; double solde;} Compte;` depot, retrait (returns success/failure).
