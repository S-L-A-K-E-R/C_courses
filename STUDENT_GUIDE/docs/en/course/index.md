# C — Core Course

> An original study guide organized to cover the topics in the supplied C programming exercises. It follows the topic scope of Tatiana Aubonnet's course without reproducing her slides.


## 0. Programming and compiling

A typical workflow: understand the problem, define inputs and outputs, choose an algorithm, write code, compile, test, and debug.

```bash
gcc -std=c11 -Wall -Wextra -Wpedantic -g main.c -o main
./main
```
- `-std=c11`: use the C11 standard.
- `-Wall -Wextra -Wpedantic`: enable useful warnings.
- `-g`: debugging information.

A minimal program:
```c
#include <stdio.h>
int main(void) {
    printf("Hello, world!\n");
    return 0;
}
```

## 1. Variables, types, and expressions

A variable has a type, name, value, and lifetime. Common C types include `char`, `int`, `long`, `float`, `double`, and derived types. Use `sizeof(type)` to get its byte size (platform-dependent).

```c
int age = 18;
double average = 14.25;
char letter = 'A';
```

### Input and output

`printf` prints; `scanf` reads and must receive addresses for variables it fills.
```c
int n;
if (scanf("%d", &n) != 1) {
    fprintf(stderr, "Invalid input\n");
    return 1;
}
printf("n = %d\n", n);
```
Common formats: `%d` int, `%u` unsigned, `%ld` long, `%f` float/double with `printf`, `%lf` double with `scanf`, `%c` character, `%s` string. With `printf`, format a `double` using `%f`. Never mismatch a format specifier and its argument type.

### Operators
- Arithmetic: `+ - * / %` (`%` is for integers).
- Comparison: `== != < <= > >=` (comparison yields 0 or 1).
- Logical: `&& || !` (short-circuit evaluation).
- Assignment: `=`, `+=`, `-=`, `*=`, `/=`.
- Increment: `++i`, `i++` (expression values differ in some contexts).
- Cast: `int x = (int)3.8;` truncates toward zero.

Integer division: `7 / 2` is `3`; `7.0 / 2` is `3.5`. Avoid integer overflow and division by zero. Use parentheses when precedence is unclear.

## 2. Conditions and loops

```c
if (x < 0) { /* ... */ }
else if (x == 0) { /* ... */ }
else { /* ... */ }
```
`switch` suits discrete choices; each `case` typically ends with `break`.

```c
for (int i = 0; i < n; ++i) { /* known repetition */ }
while (condition) { /* repeat while true */ }
do { /* runs at least once */ } while (condition);
```
`break` exits the current loop or switch; `continue` moves to the next iteration. Check termination conditions to avoid infinite loops.

[Exercise sheet — Variables, conditions, and loops](../exercises/sheets/01_Variables_IF_Loops.md)

## 3. Elementary algorithms

### Accumulate and count
```c
int sum = 0;
for (int i = 1; i <= n; ++i) sum += i;
```

### Minimum, maximum, and average
For a non-empty array, initialize min and max from its first element, then scan the remainder. Compute the average using an appropriate sum type and floating-point division: `(double)sum / n`. Do not assume an `int` sum can never overflow.

### Swap two values
```c
void swap_int(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
```

### Integer digits
The last digit of a positive integer is `n % 10`; remove it using `n /= 10`. Handle zero and negative numbers, especially `INT_MIN`, which cannot simply be negated in an `int`.

## 4. Arrays

A static array contains elements of the same type stored contiguously. Indices range from `0` to `n-1`.
```c
int values[5] = {4, 8, 1, 6, 3};
for (size_t i = 0; i < 5; ++i) printf("%d\n", values[i]);
```
C does not automatically check bounds. Accessing outside the array is undefined behavior. A function receiving an array should also receive its length:
```c
void print_array(const int a[], size_t n);
```

### Multidimensional arrays
```c
int matrix[2][3] = {{1,2,3},{4,5,6}};
```
Loop over rows, then columns. C arrays are stored row-major. A square matrix flattened into a 1D array of dimension `N` stores element `(i,j)` at `a[i * N + j]`.

## 5. Functions and procedures

A function encapsulates a task and has a return type. A `void` function returns no value. Prototypes declare a signature before use.
```c
int max3(int a, int b, int c);
int max3(int a, int b, int c) {
    int m = (a > b) ? a : b;
    return (m > c) ? m : c;
}
```
Arguments are passed by value: changing a simple parameter does not change the caller's variable. To modify the caller's variable, pass a pointer. Local variables are scoped to their block. Avoid globals for ordinary program state.

### Multiple outputs
C returns one value directly. To produce multiple results, use output pointer parameters, return a structure, or use an appropriate array.
```c
void minmax(const int a[], size_t n, int *min, int *max);
```
Check preconditions (for example, `n > 0` and valid pointers).

[Exercise sheet — Functions](../exercises/sheets/02_Functions.md)

## 6. Recursion

A recursive function calls itself. It needs a base case, a call on a smaller problem, and progress toward the base case.
```c
unsigned long long factorial(unsigned n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}
```
Recursion consumes the call stack; excessive depth can overflow it. Naive recursive Fibonacci demonstrates recursion but is very expensive; iteration is usually better for efficient computation.

## 7. Pointers and addresses

A pointer stores an object address (or `NULL`). `&x` gives the address of `x`; `*p` accesses the pointed-to object.
```c
int x = 42;
int *p = &x;
*p = 50; // x becomes 50
```
Only dereference valid, properly aligned pointers to live objects. `NULL` is a sentinel, not a usable address. `%p` prints an address; pass `(void *)p`.

### Pointer arithmetic
If `p` points to an array element, `p + 1` refers to the next element. Arithmetic is only valid within the array or one past its end (without dereferencing that one-past position). `a[i]` is equivalent to `*(a + i)`.
```c
const int *p = a;
for (size_t i = 0; i < n; ++i, ++p) { /* read *p */ }
```

### `const` and pointers
- `const int *p`: cannot modify the int through `p`.
- `int *const p`: the pointer value stored in `p` cannot change.
- `const int *const p`: neither the pointer nor the pointed value can be changed through this name.

[Exercise sheet — Pointers](../exercises/sheets/03_Pointers.md)

## 8. Strings

A C string is a `char` array terminated by `\0`. Capacity must include the terminator.
```c
char name[16] = "Ada";
```
`strlen` counts characters before `\0`; `strcmp` compares lexicographically; `strcpy` copies but requires a large enough destination; `strcat` also requires enough capacity. Prefer size-controlled operations and check input results.

Read a line:
```c
char line[128];
if (fgets(line, sizeof line, stdin) != NULL) { /* process */ }
```
`fgets` may keep `\n`; a line may be truncated if the buffer is too small. In-place string algorithms can use read/write pointers, with the write position never ahead of the read position.

## 9. Dynamic allocation

`malloc` reserves bytes; `calloc` reserves and zero-initializes; `realloc` resizes; `free` releases. Allocation functions return `NULL` on failure.
```c
size_t n = 10;
int *a = malloc(n * sizeof *a);
if (a == NULL) return 1;
/* use a */
free(a);
a = NULL;
```
Check size calculations (overflow risk), allocation success, and free each allocation exactly once. Use a temporary pointer with `realloc` so failure does not lose the old block.
```c
int *tmp = realloc(a, new_n * sizeof *a);
if (tmp != NULL) a = tmp;
else { /* a remains valid: handle failure */ }
```
A dynamic 2D array can use an array of pointers (separate allocations) or one contiguous block. A contiguous block simplifies cleanup and improves locality.

## 10. Structures and `typedef`

A structure groups fields of different types.
```c
typedef struct {
    char name[32];
    double grade;
} Student;
Student s = {"Sam", 15.5};
```
Use `s.grade`; through a pointer, use `p->grade` (equivalent to `(*p).grade`). Structures can be passed by value or address. Use a pointer when modifying an object or avoiding a copy.
Common exercise structures: point, rectangle, complex number, fraction, date, time, student, book, account, statistics. Check invariants (e.g. nonzero fraction denominator, valid balances and amounts).

[Exercise sheet — Structures](../exercises/sheets/04_Functions-Structures.md)

## 11. Library functions, callbacks, and `qsort`

A function can receive a pointer to another function (callback). Typical signature:
```c
int apply_one(int value, int (*f)(int));
```
`qsort` from `<stdlib.h>` takes a comparator:
```c
int compare_ints(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;
    return (x > y) - (x < y); // avoids x-y overflow
}
```
The comparator returns a negative value, zero, or positive. Do not return `x-y` for extreme values. Implement descending order without overflow.

[Exercise sheet — Callbacks and qsort](../exercises/sheets/03_Pointers.md)

## 12. Linked lists

A singly linked list consists of nodes with data and a pointer to the next node. The head may be `NULL`.
```c
typedef struct Node {
    int value;
    struct Node *next;
} Node;
```
- push-front: new node points to old head, then head changes;
- push-back: traverse to last node or keep a tail pointer;
- deletion: connect predecessor to successor and free removed node;
- length: count nodes during traversal;
- reversal: maintain `prev`, `current`, `next`;
- merge sorted lists: advance two cursors, choosing the smaller;
- cycle detection: Floyd's tortoise-and-hare, pointers at different speeds.

Functions that change the head should receive `Node **head` or return the new head. Never use a node after `free`.

[Exercise sheet — Linked lists](../exercises/sheets/06_Sort-Search-Lists.md)

## 13. Searching and sorting

### Searching
- Linear: scan elements, `O(n)`.
- Binary: requires sorted data; halve the interval each step, `O(log n)`.
- Min/max: one scan, `O(n)`.
- Two-sum with two pointers: on sorted data, move left/right based on the sum.

### Basic sorts
- Selection: choose minimum of unsorted part, `O(n²)`.
- Insertion: insert each element into sorted prefix, worst-case `O(n²)`, stable.
- Bubble: swap adjacent elements; early stop if no swap, worst-case `O(n²)`.

### Advanced sorts in the exercise scope
- Merge sort: divide, sort, merge; `O(n log n)`, stable, auxiliary memory.
- Quicksort: partition around pivot; average `O(n log n)`, worst `O(n²)`.
- Counting sort: for a limited integer range `[0,k]`; `O(n+k)`.
- LSD radix: process digits right-to-left with a stable sort; simple form supports nonnegative integers.
- Heap sort: build max-heap and extract; `O(n log n)`, in-place, unstable.
- Quickselect: partition to find kth element without sorting the entire array.
- Deduplication: compact unique values in a sorted array in-place.

[Exercise sheet — Sorting and searching](../exercises/sheets/06_Sort-Search-Lists.md)

## 14. Files

Standard streams: `stdin`, `stdout`, `stderr`. Files use `FILE *` and `fopen`.
```c
FILE *f = fopen("data.txt", "r");
if (f == NULL) { perror("data.txt"); return 1; }
/* read */
if (fclose(f) != 0) { /* handle error */ }
```
Modes: `r` read, `w` write/truncate, `a` append; add `b` for binary (`rb`, `wb`, etc.); `+` enables reading/writing. Check open, read, write, and close operations.
- Text: `fgets`, `fprintf`, `fputs`, `fgetc`.
- Binary: `fread`, `fwrite`; these transfer bytes, not a universally portable struct format (padding, endianness, type sizes).
- Copy: read with a buffer, then write.
- Simple CSV: parse a line and convert with error checks; real CSV can contain quoted fields and escaped delimiters, so plain `strtok` is insufficient.
- `fseek`, `ftell`: reposition and query position, subject to file type and mode.
- Errors: check `ferror`, use `feof` correctly, and inspect function return values.

[Exercise sheet — Files](../exercises/sheets/05_Files.md)

## 15. Coverage checklist

- [x] Variables, conversions, expressions, I/O, conditions, loops
- [x] 1D/2D arrays, sums, averages, min/max, matrices, trace/transpose
- [x] Functions, procedures, output parameters, recursion
- [x] Pointers, double pointers, `const`, arithmetic, callbacks
- [x] Strings, length, copy, search, tokenization, in-place editing
- [x] Allocation, reallocation, freeing, dynamic arrays
- [x] Structures, arrays of structures, structure pointers
- [x] Linked lists: operations, merge, reverse, cycles
- [x] Searching, sorting, selection, deduplication
- [x] Text and binary files, simple CSV, copy, transform, statistics

## 16. Additional calculation and string exercises

### GCD, LCM, and primes

Euclid's algorithm computes GCD: while `b != 0`, replace `(a,b)` with `(b,a%b)`. The final nonzero `a` is the GCD. LCM (when handled without overflow) is `a / gcd(a,b) * b`; dividing before multiplying reduces overflow risk.

To test whether `n` is prime, handle `n < 2`, then try divisors until `d*d > n` (or use an equivalent overflow-safe condition). The next-prime problem increments candidates and tests them.

### Quadratic roots

For `ax² + bx + c = 0`, if `a == 0`, handle the linear equation. Otherwise compute `Δ = b² - 4ac`. `Δ > 0` gives two real roots, `Δ == 0` one repeated root, and `Δ < 0` no real roots. Check division and numeric limits.

### Variance and standard deviation

For `n` population values, mean `μ = Σxᵢ/n`; population variance is `Σ(xᵢ-μ)²/n`, and standard deviation is the square root of variance. A two-pass formula is easy to understand. For large data or values close together, a more numerically stable method may be preferable.

### Palindrome and string reversal

Compare characters from both ends, moving toward the center. If spaces and case are ignored, normalize each character before comparing. To reverse in place, swap endpoint characters until the cursors cross; the string must be mutable.

[Exercise sheet — Calculations and strings](../exercises/sheets/01_Variables_IF_Loops.md)

## 17. Common structures: rules and validation

- **Point / rectangle / circle / box**: geometry; validate nonnegative dimensions and radii.
- **Complex number**: add fields; modulus `sqrt(re*re + im*im)`.
- **Fraction**: denominator must not be zero; normalize using GCD; use a consistent sign convention (e.g. positive denominator).
- **Date**: check leap year; validate month days; calculate day of year by summing preceding months.
- **Time**: normalize seconds/minutes by carrying overflow; define whether hours wrap modulo 24.
- **RGB**: each channel is in 0–255; grayscale conversion should specify its formula/approximation.
- **Polynomial**: evaluate `a*x*x + b*x + c`.
- **Statistics**: compute min/max/mean/variance while scanning; handle `n == 0`.
- **Bank account**: validate positive amounts, sufficient funds for withdrawals, and report success/failure. For real currency, avoid naive `double` calculations.

## 18. Matrices and dynamic arrays: additional operations

The trace of a square matrix is the sum of its diagonal `A[i][i]`. Transposition swaps `A[i][j]` and `A[j][i]` for `j > i` in-place for a square matrix. Matrix-vector multiplication computes a sum of products for each row. For flattened matrices, use one consistent index formula and document the dimension.

For dynamic-array `push_back`, when capacity is full, increase capacity (often doubling), call `realloc` through a temporary pointer, then append and update the size. Distinguish `size` (used elements) from `capacity` (reserved storage).

## 19. Detailed exercise coverage

This checklist gathers the topics visible in the six exercise PDFs: output and arithmetic, Celsius/Fahrenheit conversion, maxima, even/odd, quadratic roots, multiplication tables, factorial, Fibonacci, sum to n, digit reversal/count, primality, GCD/LCM, functions and recursion, sum/average/min/max, linear and binary search, selection/insertion/bubble/merge/quick/counting/radix/heap sorts, quickselect, deduplication, two-sum, pointers and output parameters, strings (length/copy/vowels/whitespace/palindrome/reverse/tokenization), matrices (trace/transpose/multiplication/flattened indexing), callbacks and `qsort`, structures (point, rectangle, complex, fraction, student, time, date, RGB, polynomial, circle, matrix, book, box, statistics, person, account), linked lists (push-front/back, deletion, length, reversal, merge, cycle), and files (text, append, binary copy, counters, patterns, replacement, sorted merge, CSV, binary arrays, binary structures, splitting, sorting/deduplication, comparison, tail, CRLF/LF, checksum, byte histogram, reverse, and prefix/header).

[Practice with the exercises](../exercises/index.md)


---

## Credits and Sources

This study guide is based on **Tatiana Aubonnet's** original C course (2008), drawing primarily from the exercises shared by [**S-L-A-K-E-R**](https://github.com/S-L-A-K-E-R), which played a particularly important role in defining the topics covered and the structure of this guide.

Adaptation, organization, and writing: [**1KuMo**](https://github.com/1KuMo).

AI tools were also used to assist with translation, layout, and content organization.

Special thanks to **Tatiana Aubonnet** for her original course, which served as the foundation for this work.