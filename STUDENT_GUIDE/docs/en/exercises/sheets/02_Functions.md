# Functions & Procedures (Algo + C)

> **Course prerequisites**: [1. Variables, types, and expressions](../../course/index.md#1-variables-types-and-expressions) · [4. Arrays](../../course/index.md#4-arrays) · [5. Functions and procedures](../../course/index.md#5-functions-and-procedures) · [6. Recursion](../../course/index.md#6-recursion) · [7. Pointers](../../course/index.md#7-pointers-and-addresses) · [8. Strings](../../course/index.md#8-strings) · [13. Searching and sorting](../../course/index.md#13-searching-and-sorting).

> Statements only; no solutions are provided. [Source PDF](02_Functions.pdf) keeps the same statements as a reference.

!!! note "Preparation for exercises 5-8 — recursion"
    Before writing code, answer these questions for `fact`, `fib`, `pow_int` and `gcd`:

    1. What is the function contract in one sentence?
    2. What is its base case? Is it reachable from every valid call?
    3. Which measure strictly decreases at each call? See [§6.3 Progress and termination](../../course/index.md#63-progress-and-termination).
    4. Which operation is pending during descent? See [§6.4 Call stack](../../course/index.md#64-call-stack-descent-and-return).
    5. Then trace `fact(3)` on paper, without writing the function body.

    Traps to identify without solving them here: `fact(n)` calling `fact(n)`, a test `n != 1` when `n == 0`, a recursive call whose result is ignored, and a two-call recurrence that recomputes the same subproblems. Full routine: [§6.9 Common mistakes and a debugging routine](../../course/index.md#69-common-mistakes-and-a-debugging-routine).

## Exercise 1 — Linear function

Statement. Write a function `f (x)` = 3x + 2 that returns the value for an integer x.

## Exercise 2 — Swap procedure

Statement. Write a procedure that swaps two integers.

## Exercise 3 — Even predicate

Statement. Write `is_even(n)` returning 1 if n is even, 0 otherwise (or a `bool` with `<stdbool.h>`).

## Exercise 4 — Maximum of three (function)

Statement. Write `max3(a,b,c)`.

## Exercise 5 — Factorial (recursive)

Statement. Write a recursive `fact(n)` (n ≥ 0).

## Exercise 6 — Fibonacci (recursive)

Statement. Write `fib(n)` with `fib(0) = 0`, `fib(1) = 1` and `fib(n) = fib(n-1) + fib(n-2)`.

## Exercise 7 — Fast exponentiation (binary exponentiation)

Statement. Write `pow_int(a,n)` for integers a, n ≥ 0. Recurrence: `pow_int(a,0) = 1`; if n is even, `pow_int(a,n) = pow_int(a*a,n/2)`; otherwise `a * pow_int(a,n-1)`.

## Exercise 8 — GCD (recursive Euclid)

Statement. Write a recursive `gcd(a,b)`.

## Exercise 9 — LCM using GCD

Statement. Write `lcm(a,b)` using gcd.

## Exercise 10 — Sum and average of an array

Statement. Functions `sum(T,n)` and `average(T,n)`.

## Exercise 11 — Min & Max with output parameters (procedure)

Statement. Procedure `minmax(T,n, min, max)`.

## Exercise 12 — Sequential search

Statement. `index_of(T,n,x)` returns the index or −1.

## Exercise 13 — Binary search (sorted array)

Statement. `bsearch_int(T,n,x)` returns the index or −1.

## Exercise 14 — Bubble sort (procedure)

Statement. Procedure `bubble_sort(T,n)`.

## Exercise 15 — Vowel count (string function)

Statement. `nb_vowels(s)` ignoring case.

## Exercise 16 — Palindrome (function)

Statement. `is_palindrome(s)` (ignore spaces and case).

## Exercise 17 — String reversal (procedure)

Statement. `reverse(s)` reverses a string in place.

## Exercise 18 — Matrix: trace (function) and transposition (procedure)

Statement. For a square N × N matrix, write `trace(A,N)` and `transpose(A,N)`.

## Exercise 19 — Variance (function)

Statement. Write `variance(T,n)` (population variance) and std_dev.

## Exercise 20 — Primality test & next prime

Statement. Write `is_prime(n)` and `next_prime(n)`.
