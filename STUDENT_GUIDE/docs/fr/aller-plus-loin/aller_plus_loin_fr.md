# C — Aller plus loin

> Extensions au cours de base. Ces sujets servent à renforcer la qualité, la performance, la conception et l'autonomie. Ils sont complémentaires, pas nécessaires à chaque exercice de base.


## 1. Complexité : raisonner sur le coût

La complexité décrit l'évolution du travail ou de la mémoire avec la taille `n` des données. On se concentre souvent sur le terme dominant :

| Classe | Exemple | Intuition |
|---|---|---|
| `O(1)` | accès `a[i]` | coût constant |
| `O(log n)` | recherche dichotomique | réduire le problème par facteur |
| `O(n)` | parcours, min/max | chaque élément une fois |
| `O(n log n)` | merge sort, heap sort | diviser + traitement linéaire |
| `O(n²)` | double boucle, tri insertion/selection au pire | paires d'éléments |
| `O(2^n)` | certains parcours exhaustifs | explosion combinatoire |

Distinguer meilleur, moyen et pire cas; distinguer complexité temporelle et espace. Une complexité asymptotique n'indique pas exactement le temps réel : constantes, cache, allocations et données comptent.

## 2. Récursion : arbre d'appels, coût et alternatives

Pour chaque fonction récursive, identifier le cas de base, la taille du sous-problème, la profondeur et le nombre d'appels. La récursion peut être naturelle (parcours d'arbre) mais coûte parfois plus de mémoire qu'une boucle.

### Diviser pour régner

1. Diviser les données en sous-problèmes.
2. Résoudre chaque sous-problème.
3. Combiner leurs résultats.

Merge sort en est un exemple : les divisions ont une profondeur logarithmique et chaque niveau fusionne `n` éléments, ce qui donne `O(n log n)`.

## 3. Choisir un tri

| Algorithme | Temps typique / pire | Stable | Mémoire auxiliaire |
|---|---|---|---|
| Insertion | `O(n²)` / `O(n²)` | oui | `O(1)` |
| Sélection | `O(n²)` / `O(n²)` | non (version classique) | `O(1)` |
| Bulles | `O(n²)` / `O(n²)` | oui | `O(1)` |
| Merge sort | `O(n log n)` / `O(n log n)` | oui | `O(n)` |
| Quicksort | `O(n log n)` moyen / `O(n²)` | non | pile de récursion |
| Heap sort | `O(n log n)` / `O(n log n)` | non | `O(1)` |
| Counting | `O(n+k)` | stable si reconstruit correctement | `O(k)` |
| Radix LSD | dépend du nombre de chiffres et de la base | stable par passe | buffers |

Le choix dépend des données, de la stabilité requise, de la mémoire, et de la facilité de mise en œuvre. Tester sur tableaux vides, singleton, déjà triés, inversés, avec doublons et valeurs extrêmes.

## 4. Quicksort et partition

La partition organise les éléments relativement au pivot. Le pivot final (Lomuto) est simple à comprendre mais peut produire des partitions déséquilibrées avec des données déjà ordonnées ou beaucoup de doublons. Une version robuste peut choisir un pivot aléatoire ou médian de trois et gérer les valeurs égales en partition trois voies. Toujours vérifier les indices et la condition de récursion.

## 5. Tas (heap)

Un tas max est un arbre binaire complet où chaque parent est supérieur ou égal à ses enfants. Représentation en tableau (indices à partir de zéro) :
- parent de `i` : `(i-1)/2` (si `i>0`)
- enfant gauche : `2*i+1`
- enfant droit : `2*i+2`

Construire le tas en descendant depuis le dernier parent. `sift_down` restaure la propriété après échange. Heapsort extrait répétitivement le maximum vers la fin. Le tas permet aussi de maintenir efficacement un top-k.

## 6. Recherche et sélection avancées

- Recherche binaire : invariants de l'intervalle; utiliser `lo + (hi-lo)/2` pour éviter le débordement de `lo+hi`.
- Quickselect : partition puis continuer uniquement dans le côté contenant le rang demandé. Rang 1-indexé et indice 0-indexé doivent être clairement distingués.
- Two pointers : utile pour tableaux triés, fenêtres ou rapprochement; expliquer pourquoi le déplacement choisi ne peut pas éliminer la solution.
- Déduplication : invariant de compactage — le préfixe écrit contient déjà les valeurs distinctes.

## 7. Listes chaînées : variantes et invariants

### Insertion et suppression

Privilégier les fonctions qui reçoivent `Node **head` pour pouvoir modifier la tête. Chaque opération doit préserver :
- tous les nœuds accessibles depuis la tête;
- aucune perte de chaîne;
- liens cohérents;
- libération exactement une fois des nœuds supprimés.

### Fusion de listes triées

Maintenir un pointeur de queue du résultat et deux curseurs de lecture. Choisir le plus petit élément, l'attacher, puis avancer son curseur. Réutiliser les nœuds (fusion destructive) ou créer une copie (fusion non destructive); préciser le choix.

### Inversion

Invariant : `prev` représente la partie déjà inversée; `current` est le prochain nœud à traiter; `next` est sauvegardé avant modification du lien.

### Détection de cycle

Floyd : avancer lentement d'un pas et rapidement de deux. S'ils se rencontrent, un cycle existe. Si le rapide atteint `NULL` (ou son prochain), la liste est acyclique. Ne pas dereferencer `NULL`.

## 8. Mémoire et robustesse

### Ownership

Pour chaque allocation, documenter qui en est responsable, qui la libère, et si une fonction transfère la propriété. Éviter les pointeurs pendants, double-free, fuites et accès après libération.

### Réallocation sans perte

```c
void *tmp = realloc(ptr, new_size);
if (tmp == NULL && new_size != 0) {
    // ptr reste utilisable; traiter l'échec
} else {
    ptr = tmp;
}
```
En pratique, clarifier le cas `new_size == 0` selon la version du standard et préférer une libération explicite. Vérifier que `new_count * sizeof *ptr` ne déborde pas `SIZE_MAX`.

### Débogage

Compiler avec avertissements, puis utiliser un débogueur et des outils de vérification mémoire disponibles sur le système. Tester chaque fonction avec cas limites et assertions de préconditions. Ne pas ignorer les warnings.

## 9. Chaînes et parsing

Une chaîne reçue n'est pas forcément complète, bien formée ou assez longue. Définir les règles de parsing : séparateur, espaces, lignes vides, champs manquants, valeurs invalides, limites de buffer, encodage. `strtok` modifie la chaîne et ne traite pas les CSV complexes. Pour un format CSV complet, gérer les guillemets, les séparateurs dans les champs, les échappements et les lignes.

Pour tokeniser avec pointeurs : identifier chaque début de token, remplacer le séparateur par `\0` si la chaîne est modifiable, puis stocker les adresses des tokens; vérifier la capacité du tableau de sortie.

## 10. Fichiers : stratégie de traitement

- Pour copier : tampon fixe, vérifier le nombre d'octets lus et écrits, puis les erreurs.
- Pour comparer : comparer blocs d'octets, repérer la première différence et tenir compte des tailles distinctes.
- Pour compter lignes/mots/octets : définir précisément la convention de comptage (ligne terminée par LF ou dernière ligne sans LF; mot défini par espaces).
- Pour remplacer un texte : streaming avec tampon de recouvrement si motif peut traverser deux blocs; ou charger en mémoire en vérifiant la taille.
- Pour `tail` : stratégie simple en mémoire ou stratégie de lecture à rebours; choisir selon la taille du fichier.
- Pour découper : compteur de lignes et nommage déterministe des morceaux.
- Pour normaliser CRLF : traiter `\r\n` comme une unité, éviter de transformer les CR isolés sans décision explicite.
- Pour checksum : distinguer hash pédagogique (djb2) et fonction cryptographique; un checksum simple ne protège pas contre les adversaires.

## 11. Données binaires et portabilité

`fwrite(&object, sizeof object, 1, file)` peut sauvegarder une structure pour un usage local, mais n'est pas un format durable universel. Les différences de padding, d'endianness, de largeur de type, de représentation et de version de structure peuvent rendre un fichier incompatible. Pour un format portable, définir un format explicite (types de largeur fixe, ordre des octets, version, validation) et sérialiser les champs.

## 12. Fonctions de rappel

Un pointeur de fonction permet de paramétrer une opération : transformation, comparaison, intégration numérique. Vérifier la signature et ne jamais appeler un pointeur de fonction nul.

Exemple de contrat :
```c
typedef int (*Transform)(int);
void map_ints(int *array, size_t n, Transform fn);
```
Un callback doit avoir un contrat clair : effets de bord permis, valeur de retour, validité des arguments et durée de vie des données.

## 13. Exercices de synthèse proposés

1. Tableau dynamique avec push, pop, capacité doublée, erreurs d'allocation.
2. Bibliothèque de tri générique avec comparateur et tests.
3. Liste de contacts (struct) avec recherche, suppression, tri et sauvegarde.
4. CSV de notes : parsing contrôlé, statistiques, classement et rapport.
5. Comparateur de fichiers affichant le premier octet différent.
6. Mini `tail` avec gestion des très longues lignes.
7. Fusion non destructive de listes triées.
8. Vérificateur de liste (longueur, cycle, ordre).
9. Top-k avec tas.
10. Benchmark de tris sur données variées, mesures et analyse de complexité.

## 14. À retenir

La progression ne consiste pas à mémoriser des algorithmes isolés. Pour chaque solution, savoir expliquer : son invariant, ses préconditions, ses cas limites, sa complexité, la gestion de la mémoire, et comment le tester.


---

## Crédit et provenance

Support de révision réalisé à partir du cours de **Tatiana Aubonnet** (C, 2008), en s'appuyant principalement sur les exercices partagés par [**S-L-A-K-E-R**](https://github.com/S-L-A-K-E-R), qui ont particulièrement contribué à définir les notions abordées et la structure de ce support.

Adaptation, organisation et rédaction : [**1KuMo**](https://github.com/1KuMo).

Des outils d'intelligence artificielle ont également été utilisés pour assister la traduction, la mise en page et l'organisation du contenu.

Merci à **Tatiana Aubonnet** pour son cours original, qui a servi de base à ce travail.
