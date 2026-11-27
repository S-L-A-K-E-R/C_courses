# Sorting, Searching & Lists (Algo + C)

> **Course prerequisites**: [6. Recursion, §6.7 Arrays and intervals](../../course/index.md#67-recursion-on-arrays-and-intervals) · [11. Callbacks and qsort](../../course/index.md#11-library-functions-callbacks-and-qsort) · [12. Linked lists](../../course/index.md#12-linked-lists) · [13. Searching and sorting](../../course/index.md#13-searching-and-sorting).
> Exercises 8-20: read [Beyond the core §§3-7](../../beyond-core/index.md#3-choosing-a-sort) first (sorts, partition, heaps, selection, lists).
> Statements only; no solutions are provided. [Source PDF](06_Sort-Search-Lists.pdf) keeps the same statements as a reference.

## Exercise 1 — Sequential search (index or -1)

Task. Read n, an array of integers, and a key x. Return the index of the first occurrence or −1.

## Exercise 2 — Binary search (sorted array)

Task. On a strictly increasing sorted array, search for x.

## Exercise 3 — Min & Max in one pass

Task. Find the minimum and maximum values of an integer array in a single pass.

## Exercise 4 — Selection sort

Task. Sort an array of integers using selection sort.

## Exercise 5 — Insertion sort

Task. Implement insertion sort.

## Exercise 6 — Bubble sort (optimized)

Task. Bubble sort with early stopping if no swap occurs during a pass.

## Exercise 7 — Merge two sorted arrays

Task. Merge sorted arrays A and B into a sorted array C.

Hint: merging is the "combine" step of merge sort, traced in [§13 Searching and sorting](../../course/index.md#13-searching-and-sorting).

## Exercise 8 — Merge sort

Task. Implement recursive merge sort (stable).

Hint: before writing the recursive split, reread [§6.7 Recursion on arrays and intervals](../../course/index.md#67-recursion-on-arrays-and-intervals); the decreasing measure is the interval length.

## Exercise 9 — Quicksort (Lomuto partition)

Task. Implement quicksort using Lomuto’s partition scheme (pivot at the end).

## Exercise 10 — Counting sort (integers in [0..k])

Task. Count occurrences and reconstruct the sorted array.

## Exercise 11 — Radix sort LSD (base 10, integers ≥ 0)

Task. Apply stable counting sort digit by digit (least significant first).

## Exercise 12 — Heap sort

Task. Build a max-heap then extract the elements.

## Exercise 13 — Quickselect (k-th smallest, 1-indexed)

Task. Find the k-th order statistic without fully sorting the array.

## Exercise 14 — Remove duplicates from a sorted array (inplace)

Task. Compact the array so that each value appears once. Return the new size.

## Exercise 15 — Target sum (two-pointer)

Task. Given an array sorted in increasing order, determine whether there exist i < j such that a[i] + a[j] = S.

## Exercise 16 — Linked list : insert at head & tail

Task. Implement push_front and push_back, then print the list.

## Exercise 17 — Linked list : remove first occurrence

Task. Implement `remove_first(&H, x)`.

## Exercise 18 — Linked list : iterative reversal

Task. Implement `reverse(&H)` to reverse the list.

## Exercise 19 — Merge two sorted linked lists

Task. Merge two sorted singly linked lists into one sorted list (ascending).

## Exercise 20 — Cycle detection (Floyd)

Task. Detect whether a cycle exists in a list using the tortoise–hare algorithm.
