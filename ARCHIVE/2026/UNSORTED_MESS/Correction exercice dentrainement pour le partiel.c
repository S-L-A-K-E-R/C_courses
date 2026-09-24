#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define NAME 256
#define CODEBARRE 11

// PRODUIT
// Un nom d'au plus 255 caractères
// Un code barre (chaîne de caractères) de 1 à 10 chiffres
// Une rangée
typedef struct {
    char nom[NAME];
    char codeBarre[CODEBARRE];
    int rangee;
    int stock;
} Produit;

Produit* creerProduit() {
    Produit* p = malloc(sizeof(Produit));
    printf("Nom :\n");
    fflush(stdin);
    fgets(p->nom, NAME, stdin); // permet les espaces
    if(p->nom[strlen(p->nom) - 1] == '\n') { // enlève le \n qui est rajouté par fgets
        p->nom[strlen(p->nom) - 1] = '\0';
    }
    int nbCharCodeBarre = rand() % (10 - 5 + 1) + 5; // rand()%(max-min+1)+min
    for (int i = 0; i < nbCharCodeBarre; i++) {
        p->codeBarre[i] = rand() % ('9' - '0' + 1) + '0'; // cast implicité de '0' en 48 (ASCII)
    }
    p->codeBarre[nbCharCodeBarre] = '\0'; // toute chaîne doit finir par \0
    printf("Rangee :\n");
    scanf(" %d", &(p->rangee));
    p->stock = rand()%101; // on va dire qu'on n'a jamais plus de 100 fois le même article en stock
    return p;
}

Produit** creerTableauDePointeursSurProduits(int* pTaillePhysique, int* pTailleLogique) {
    printf("Taille physique ?\n");
    scanf(" %d", &*pTaillePhysique); // &*pTaillePhysique <=> pTaillePhysique
    printf("Taille logique ?\n");
    scanf(" %d", pTailleLogique); // ou &*pTailleLogique ou &*&*&*&*pTailleLogique
    Produit** tab = calloc(*pTaillePhysique, sizeof(Produit*)); // calloc pour mettre tous les pointeurs du tableau à NULL
    for (int i = 0; i < *pTailleLogique; i++) {
        tab[i] = creerProduit();
        // on accède maintenant aux produits grâce au tableau
        // il a la responsabilité de les détruire
    }
    return tab;
}

void libererTableauDePointeursSurProduitsV1(Produit*** ptrSurTab, int* tailleLogique, int* taillePhysique) {
    for (int i = 0; i < *tailleLogique; i++) {
        free((*ptrSurTab)[i]);
    }
    free(*ptrSurTab);
    *ptrSurTab = NULL; // on remet le pointeur du main à NULL
    *tailleLogique = 0; // idem pour les tailles du main
    *taillePhysique = 0;
}
void libererTableauDePointeursSurProduitsV2(Produit** tableau, int* tailleLogique, int* taillePhysique) {
    for (int i = 0; i < *tailleLogique; i++) {
        free(tableau[i]);
    }
    free(tableau);
    tableau = NULL; // il faudra mettre le pointeur du programme appelant à NULL ! Ceci est une copie
    *tailleLogique = 0;
    *taillePhysique = 0;
}

void sauvegarder(Produit** tab, int tailleLogique) {
    FILE* pf = fopen("../produits.bin", "w");
    if(pf != NULL) {
        // 1/ en binaire :
        fwrite(&tailleLogique, 1, sizeof(int), pf);
        // fwrite(tab, tailleLogique, sizeof(Produit*), pf); // pas bien car sauvegarde les adresses !!!!
        // on va sauvegarder les produits un par un du coup :
        for (int i = 0; i < tailleLogique; i++) {
            fwrite(tab[i], 1, sizeof(Produit), pf);
        }

        // 2/ en texte :
        /*fprintf(pf, "\n%d\n", tailleLogique);
        for (int i = 0; i < tailleLogique; ++i) {
            fprintf(pf, "%s\n%s\n%d %d\n", tab[i]->nom, tab[i]->codeBarre, tab[i]->rangee, tab[i]->stock);
        }*/

        fclose(pf);
    }
    else {
        printf("Erreur de sauvegarde\n");
    }
}

int main() {
    srand(time(NULL));
    int taillePhys = 0, tailleLog = 0;

    Produit** tab = creerTableauDePointeursSurProduits(&taillePhys, &tailleLog);
    for (int i = 0; i < tailleLog; ++i) {
        printf("%s\n", tab[i]->nom);
    }
    sauvegarder(tab, tailleLog);
    libererTableauDePointeursSurProduitsV1(&tab, &tailleLog, &taillePhys);
    // ou
    // libererTableauDePointeursSurProduitsV2(tab, &tailleLog, &taillePhys);
    // tab = NULL;

    /*
     * Exemple d'utilisation de la fonction creerProduit
     Produit* prod = creerProduit();
     // on utilise le produit ici (printf...)...
     free(prod); // quand on n'en a plus besoin
    */
    return 0;
}