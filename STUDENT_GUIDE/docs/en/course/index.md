# C — Core Course

> An original study guide organized to cover the topics in the supplied C programming exercises. It follows the topic scope of Tatiana Aubonnet's course without reproducing her slides.


## 0. Programming and compiling

A typical workflow: understand the problem, define inputs and outputs, choose an algorithm, write code, compile, test, and debug.

```bash
gcc -std=c11 -Wall -Wextra -Wpedantic -g main.c -o main
./main
```
- `-std=c11`: use C11 for broad compatibility; `-std=c23` is also appropriate on a C23-capable compiler.
- `-Wall -Wextra -Wpedantic`: enable useful warnings.
- `-g`: debugging information.

The first example is a complete program. Later examples are snippets: add the relevant headers (`<stdio.h>`, `<stdlib.h>`, `<stddef.h>`, `<stdint.h>`, `<string.h>`, `<limits.h>`) and place statements inside a function.

A minimal program:
```c
#include <stdio.h>
int main(void) {
    printf("Hello, world!\n");
    return 0;
}
```

!!! note "Math linking"
    If the program uses `<math.h>` (for example `sqrt`), add `-lm` after the output name: `gcc ... main.c -o main -lm`.

> **See also**: [Exercises — sheet 1](../exercises/sheets/01_Variables_IF_Loops.md).

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
Common formats: `%d` / `%i` int, `%u` unsigned, `%ld` long, `%f` float/double with `printf`, `%f` float with `scanf`, `%lf` double with `scanf`, `%c` character, `%s` string, `%zu` for `size_t`. `size_t` is the unsigned type for sizes and indices, defined in `<stddef.h>`. Never mismatch a format specifier and its argument type.

### Operators
- Arithmetic: `+ - * / %` (`%` is for integers).
- Comparison: `== != < <= > >=` (comparison yields 0 or 1).
- Logical: `&& || !` (short-circuit evaluation).
- Assignment: `=`, `+=`, `-=`, `*=`, `/=`.
- Increment: `++i`, `i++` (expression values differ in some contexts).
- Cast: `int x = (int)3.8;` truncates toward zero.

Integer division: `7 / 2` is `3`; `7.0 / 2` is `3.5`. Avoid integer overflow and division by zero. Use parentheses when precedence is unclear.

!!! warning "Common mistake — `=` vs `==`"
    `if (x = 3)` assigns 3 and then tests the value; use `if (x == 3)` to compare.
    `scanf("%d", x)` (without `&`) writes to an invalid address; the correct form is `scanf("%d", &x)`.

> **See also**: [Exercises — sheet 1](../exercises/sheets/01_Variables_IF_Loops.md).

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

The loop invariant is: before iteration `i`, `sum` holds `1 + ... + (i-1)` and `count` is `i - 1`. After the iteration, they hold the sum up to `i` and `i`. Checking this invariant explains why initialising to `0` and using `i <= n` are correct.

Here `int *a` is a pointer parameter and `*a` is the pointed-to value; details come in [chapter 7](#7-pointers-and-addresses).

> **See also**: [Exercises — sheet 1](../exercises/sheets/01_Variables_IF_Loops.md).

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

### Passing an array to a function

In `void print_array(const int a[], size_t n)`, parameter `a` is adjusted to a pointer to the first element: the caller's array length is not passed with it. Therefore `sizeof a` inside `print_array` gives the size of a pointer, not `n * sizeof(int)`. The length must always be a separate parameter.

```c
void print_array(const int a[], size_t n) {
    /* a points to a[0]; n is the only source of the length. */
    for (size_t i = 0; i < n; ++i) printf("%d\n", a[i]);
}
```

!!! warning "Common mistake — out-of-bounds index"
    An array of `n` items runs from `t[0]` to `t[n - 1]`. `t[n]` is out of bounds; the loop must use `i < n`.

> **See also**: [Exercises — sheet 1](../exercises/sheets/01_Variables_IF_Loops.md).

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
C returns one value directly. To produce multiple results, use output pointer parameters, return a structure, or write into an output array (C cannot return arrays by value).
```c
void minmax(const int a[], size_t n, int *min, int *max);
```
Check preconditions (for example, `n > 0` and valid pointers).

[Exercise sheet — Functions](../exercises/sheets/02_Functions.md)

For example, in `max3(2, 7, 5)`, `m` is first `7`, then the function returns `7`. Each call owns its parameters and local variables.

```c
void swap_wrong(int a, int b) {
    int tmp = a;
    a = b;
    b = tmp;
}
```

This function only swaps two copies: the caller's `x` and `y` do not change. The correct pointer version appears in chapter 7.

## 6. Recursion

A recursive function calls itself. It is not a disguised loop: it hands a **smaller instance of the same problem** to another call, then combines the result on the way back.

Before writing code, ask three questions:

1. What is the **base case**, the smallest instance that can be solved directly?
2. What smaller call is made?
3. What operation or value remains after that call returns?

### 6.1 The recursive idea

Start with an example that returns no value, so the self-call is visible on its own:

```c
#include <stdio.h>

void countdown(unsigned n) {
    if (n == 0) return;       /* base case */
    printf("%u ", n);
    countdown(n - 1);          /* smaller problem */
}
```

`countdown(3)` prints `3 2 1 `. Execution does not stay in one frame: each call owns its own `n`. The current call waits for the next call to finish before continuing.

**Contract of `countdown(n)`**: print the integers from `n` down to `1`, or print nothing when `n == 0`.

### 6.2 Base cases and boundary values

A base case must be **reachable** from every valid call. It can be single or multiple: `n == 0` or `n == 1` for a factorial, `n == 0` for an empty array, `lo >= hi` for an empty interval.

```c
unsigned long long factorial(unsigned n) {
    if (n <= 1) return 1;              /* base case */
    return n * factorial(n - 1);       /* smaller call + combination */
}
```

With a 64-bit `unsigned long long`, only `0!` through `20!` fit. Beyond that the result is wrong because of overflow: reject the input or use a larger representation. Unsigned arithmetic wraps around the range of the type.

### 6.3 Progress and termination

You must always be able to name a **measure that strictly decreases** from one call to the next. It is that measure, not merely the presence of an `if`, that guarantees termination.

| Function | Recursive call | Decreasing measure |
|---|---|---|
| `factorial(n)` | `factorial(n - 1)` | `n` |
| `countdown(n)` | `countdown(n - 1)` | `n` |
| `sum_prefix(a, n)` | `sum_prefix(a, n - 1)` | `n` |
| search on `[lo, hi)` | `[lo, mid)` or `[mid+1, hi)` | `hi - lo` |

!!! warning "Common mistake — no progress"
    ```c
    unsigned long long fact(unsigned n) {
        if (n <= 1) return 1;
        return fact(n);          /* n never decreases */
    }
    ```
    The base case exists but is never reached: the call stack grows until it overflows.
    Fix: `return n * fact(n - 1);`.

### 6.4 Call stack, descent and return

Each call reserves a frame on the **call stack**: its parameters, local variables and return address. Trace `factorial(4)`.

**Descent:**

| Depth | Call | `n` | Pending operation |
|---:|---|---:|---|
| 1 | `factorial(4)` | 4 | `4 * factorial(3)` |
| 2 | `factorial(3)` | 3 | `3 * factorial(2)` |
| 3 | `factorial(2)` | 2 | `2 * factorial(1)` |
| 4 | `factorial(1)` | 1 | no call, return `1` |

**Return:**

```text
factorial(2) = 2 * 1 = 2
factorial(3) = 3 * 2 = 6
factorial(4) = 4 * 6 = 24
```

The last call is the first to return a value: this is LIFO (*last in, first out*). The pending operation runs during the return phase, not during descent.

Excessive depth exhausts the stack. In C, do not assume the compiler will automatically turn tail recursion into a loop.

### 6.5 Return values and combination

The value computed by one call can be combined in three ways:

- **one multiplication with one call**: `n * factorial(n - 1)`;
- **two independent calls**: a Fibonacci-style recurrence, where the same subproblems are recomputed;
- **divide, solve, merge**: merge sort, covered later.

A result can be correct even when the cost becomes exponential. That is why [sheet 1](../exercises/sheets/01_Variables_IF_Loops.md) also asks for an iterative version of recurring sequences: recursion is first a way to reason, not a guarantee of efficiency.

### 6.6 Recursion with several parameters

Several parameters do not change the method: identify which ones carry progress, and check the invariants. An invariant describes what remains true at each call; the decreasing measure describes why the calls stop.

A function can receive an array, a length and two bounds: this is the model used in the next section. The key is not to confuse the data passed in with the measure that makes the calls smaller.

### 6.7 Recursion on arrays and intervals

Arrays were introduced in chapter 4. A prefix sum avoids pointer arithmetic and shows how to pass the length:

```c
#include <stddef.h>

unsigned long long sum_prefix(const int a[], size_t n) {
    if (n == 0) return 0;              /* empty array */
    return (unsigned long long)a[n - 1] + sum_prefix(a, n - 1);
}
```

`sum_prefix(a, 3)` handles `a[2]`, then `a[1]`, then `a[0]`. The decreasing measure is `n`.

A search over a half-open interval `[lo, hi)` uses two bounds instead of copying the array. The invariant is: “the part still to examine is exactly `[lo, hi)`”. Each call shrinks that part until it becomes empty. This is the model used by merge sort in [sheet 6](../exercises/sheets/06_Sort-Search-Lists.md).

### 6.8 Recursion or iteration

Both versions below print the same sequence, but not in the same way:

=== "Iterative"

    ```c
    void countdown_loop(unsigned n) {
        while (n > 0) {
            printf("%u ", n);
            --n;
        }
    }
    ```

=== "Recursive"

    ```c
    void countdown(unsigned n) {
        if (n == 0) return;
        printf("%u ", n);
        countdown(n - 1);
    }
    ```

Prefer recursion when the problem structure is naturally recursive (trees, intervals that split, lists). Prefer a loop when the depth may be large or the same subproblem would be recomputed. Compare readability too: a clear recursion beats a loop with hard-to-follow state, but not the reverse.

See also [Beyond the core, §2](../beyond-core/index.md#2-recursion-call-trees-cost-and-alternatives) for cost and call trees.

### 6.9 Common mistakes and a debugging routine

| Mistake | Why it fails | Fix |
|---|---|---|
| `fact(n)` with no base case | no call ever stops | add `if (n <= 1) return 1;` |
| `return fact(n);` | the measure does not decrease | call with `n - 1`, `n/2` or a shorter interval |
| `if (n != 1) return n * fact(n - 1);` | for `n == 0`, `n - 1` becomes `UINT_MAX` | test `n <= 1` **before** subtracting |
| recursive call without `return` | the computed value is discarded | explicit `return` on every path |
| naive two-call recurrence | subproblems are recomputed | trace the calls, then look for an iterative form |

Practical five-step method:

1. Write the function contract in one sentence.
2. Name the base case and check that it is reachable.
3. Name the measure that strictly decreases.
4. Trace `n = 0`, `n = 1` and `n = 2` by hand, noting the pending operation.
5. Compile with `-Wall -Wextra -Wpedantic`: a path without `return` is a warning to fix, not an opinion.

!!! warning "Common mistake — missing `return`"
    ```c
    unsigned long long fact(unsigned n) {
        if (n <= 1) return 1;
        fact(n - 1);                /* value computed then ignored */
        return 1;                   /* every n > 1 gives 1 */
    }
    ```
    Fix: `return n * fact(n - 1);`.

> **See also**: [Exercises — sheet 2, exercises 5-8 and preparation](../exercises/sheets/02_Functions.md) · [Exercises — sheet 6, merge sort](../exercises/sheets/06_Sort-Search-Lists.md) · [Beyond the core, §2](../beyond-core/index.md#2-recursion-call-trees-cost-and-alternatives).

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

Simplified picture:

```text
x: [ 50 ]      p: [ address of x ]
       ^                    |
       +---- *p ------------+
```

`&x` gives the address of the cell `x`; `*p` designates that same cell. The two operations are inverses.

!!! warning "Common mistake — uninitialised pointer"
    `int *p; *p = 3;` writes to an arbitrary address: undefined behaviour.
    Fix: initialise `p` with `&x`, `malloc`, or `NULL`, then check before dereferencing.

## 8. Strings

A C string is a `char` array terminated by `\0`. Capacity must include the terminator.
```c
char name[16] = "Ada";
```
`strlen` counts bytes before `\0` (not Unicode characters in UTF-8); `strcmp` compares lexicographically; `strcpy` copies but requires a large enough destination; `strcat` also requires enough capacity. Prefer size-controlled operations and check input results.

Read a line:
```c
char line[128];
if (fgets(line, sizeof line, stdin) != NULL) { /* process */ }
```
`fgets` may keep `\n`; a line may be truncated if the buffer is too small. In-place string algorithms can use read/write pointers, with the write position never ahead of the read position.

Removing a kept `\n` requires checking what was actually read:

```c
#include <string.h>

char line[128];
if (fgets(line, sizeof line, stdin) != NULL) {
    size_t len = strlen(line);
    if (len > 0 && line[len - 1] == '\n') line[len - 1] = '\0';
    else if (len == sizeof line - 1 && line[len - 1] != '\n') {
        /* line too long: the rest remains in the stream. */
    }
}
```

> **See also**: [Exercises — sheet 2](../exercises/sheets/02_Functions.md).

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
/* a is NULL or owns a block; new_n has type size_t. */
if (new_n == 0) {
    free(a);
    a = NULL;
} else if (new_n > SIZE_MAX / sizeof *a) {
    /* Handle size overflow; a remains unchanged. */
} else {
    int *tmp = realloc(a, new_n * sizeof *a);
    if (tmp != NULL) {
        a = tmp;
    } else {
        /* Handle allocation failure; a remains valid. */
    }
}
```
Include `<stdlib.h>` and `<stdint.h>`. Update logical size/capacity only after success. Zero-size `realloc` has undefined behavior in C23.

A dynamic 2D array can use an array of pointers (separate allocations) or one contiguous block. A contiguous block simplifies cleanup and improves locality.

Possible states of `a` after a resize attempt:

| Outcome | State of `a` |
|---|---|
| Success | new block, old block released |
| Failure (`tmp == NULL`) | old block unchanged and still valid |
| `new_n == 0` | `a` is `NULL` after release |

Ownership rule: a function that receives an allocated block must state whether it frees it or returns it to the caller. Unless stated otherwise, the caller frees the block it receives.

!!! warning "Common mistake — `realloc`"
    `p = realloc(p, n)` loses the old block if allocation fails. Use a temporary pointer, handle `n == 0`, and check overflow in `n * sizeof *p`.

> **See also**: [Exercises — sheet 3](../exercises/sheets/03_Pointers.md).

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

The four arguments of `qsort` are: address of the first element, element count, size of one element, then the comparator. The comparator must be consistent: if `cmp(a,b) < 0`, then `cmp(b,a) > 0`.

!!! warning "Common mistake — `qsort` comparator"
    After casting and dereferencing, do not return `x - y`: the result can overflow. Use `(x > y) - (x < y)`.

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

With `Node **head`, the caller's head is changed. A deletion must save the address of the next node before freeing the current one.

Useful invariant: `cur` always designates the address of the field to examine (`head` or `&(*cur)->next`); `*cur` is the current node or `NULL`. This invariant is enough to reason about insertion and deletion without leaking memory.

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

Binary-search trace on `[1, 3, 5, 7, 9, 11]` with `x = 9`:

| Step | `lo` | `hi` | `mid` | `a[mid]` | Decision |
|---:|---:|---:|---:|---:|---|
| 1 | 0 | 6 | 3 | 7 | `lo = 4` |
| 2 | 4 | 6 | 5 | 11 | `hi = 5` |
| 3 | 4 | 5 | 4 | 9 | found |

The middle is computed as `lo + (hi - lo) / 2` to avoid overflow in `lo + hi`.

Merge trace for `[4, 1, 3, 2]`: `[4,1]` and `[3,2]` become `[1,4]` and `[2,3]`, then merging gives `[1,2,3,4]`. Division depth is logarithmic and each merge is linear in the number of elements.

Exercises 8-20 in [sheet 6](../exercises/sheets/06_Sort-Search-Lists.md) assume the methods below; read [Beyond the core, §§3-7](../beyond-core/index.md#3-choosing-a-sort) first.

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

```c
FILE *f = fopen("data.txt", "r");
if (f == NULL) { perror("data.txt"); return 1; }
char line[256];
while (fgets(line, sizeof line, f) != NULL) {
    fputs(line, stdout);
}
if (ferror(f)) { perror("read"); }
if (fclose(f) != 0) { /* handle error */ }
```

The loop tests the result of the read, not `feof` before reading. `feof(f)` becomes true only after a failed read; `ferror(f)` distinguishes a real error from normal end-of-file.

!!! warning "Common mistake — `feof`"
    `while (!feof(f))` processes a failed read. Use `while (fgets(line, sizeof line, f) != NULL)` and check the result of `fopen`.

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

To test whether `n` is prime, handle `n < 2`, then try divisors while `d <= n / d`, starting at 2 (avoids multiplication overflow). The next-prime problem increments candidates and tests them.

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
- **RGB**: each 8-bit channel is in 0–255 (`unsigned char` is not necessarily 8 bits; use `uint8_t` where available or validate the range); grayscale conversion should specify its formula/approximation.
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
