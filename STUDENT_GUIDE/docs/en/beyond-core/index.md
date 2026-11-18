# C — Beyond the Core

> Extensions to the core course. These topics strengthen quality, performance, design, and independence. They are supplementary, not required for every core exercise.


## 1. Complexity: reason about cost

Complexity describes how work or memory grows with input size `n`. Focus on the dominant term:

| Class | Example | Intuition |
|---|---|---|
| `O(1)` | `a[i]` access | constant cost |
| `O(log n)` | binary search | shrink problem by a factor |
| `O(n)` | scan, min/max | visit each item once |
| `O(n log n)` | merge sort, heap sort | divide + linear work |
| `O(n²)` | nested loops, worst-case insertion/selection sort | item pairs |
| `O(2^n)` | some exhaustive searches | combinatorial explosion |

Distinguish best, average, and worst case; time complexity from space complexity. Big-O does not give exact runtime: constants, cache, allocation, and input shape matter.

## 2. Recursion: call trees, cost, and alternatives

For each recursive function, identify the base case, subproblem size, depth, and number of calls. Recursion is natural for trees but can use more memory than loops.

### Divide and conquer
1. Divide data into subproblems.
2. Solve each subproblem.
3. Combine their results.

Merge sort is an example: logarithmic division depth and `n` items merged per level yields `O(n log n)`.

## 3. Choosing a sort

| Algorithm | Typical / worst time | Stable | Extra memory |
|---|---|---|---|
| Insertion | `O(n²)` / `O(n²)` | yes | `O(1)` |
| Selection | `O(n²)` / `O(n²)` | no (classic version) | `O(1)` |
| Bubble | `O(n²)` / `O(n²)` | yes | `O(1)` |
| Merge sort | `O(n log n)` / `O(n log n)` | yes | `O(n)` |
| Quicksort | average `O(n log n)` / `O(n²)` | no | recursion stack |
| Heap sort | `O(n log n)` / `O(n log n)` | no | `O(1)` |
| Counting | `O(n+k)` | stable if reconstructed properly | `O(k)` |
| LSD radix | depends on digits and base | stable per pass | buffers |

The choice depends on input, stability, memory, and implementation complexity. Test empty, singleton, sorted, reverse-sorted, duplicate-heavy, and extreme-value arrays.

## 4. Quicksort and partitioning

Partition organizes elements relative to a pivot. Lomuto's final-element pivot is easy to learn but may produce unbalanced partitions on sorted or duplicate-heavy inputs. A robust version can use a random or median-of-three pivot and a three-way partition for equal values. Check index boundaries and recursive ranges.

## 5. Heaps

A max-heap is a complete binary tree where every parent is at least as large as its children. Zero-based array representation:
- parent of `i`: `(i-1)/2` (when `i>0`)
- left child: `2*i+1`
- right child: `2*i+2`

Build the heap by sifting down from the last parent. `sift_down` restores the property after swaps. Heapsort repeatedly moves the maximum to the end. Heaps also support efficient top-k selection.

## 6. Advanced search and selection

- Binary search: maintain a clear interval invariant; use `lo + (hi-lo)/2` to avoid overflow in `lo+hi`.
- Quickselect: partition and continue only in the side containing the desired rank. Keep 1-based rank distinct from 0-based index.
- Two pointers: useful on sorted arrays, windows, or matching; explain why each movement cannot discard a solution.
- Deduplication: invariant—the written prefix already contains distinct values.

## 7. Linked lists: variants and invariants

### Insert and delete
Prefer functions receiving `Node **head` when the head may change. Each operation should preserve reachability, avoid losing links, maintain consistent pointers, and free removed nodes exactly once.

### Merge sorted lists
Keep an output tail and two read cursors. Attach the smaller item, then advance its cursor. Reuse nodes (destructive merge) or copy nodes (non-destructive merge); state which approach is used.

### Reverse
Invariant: `prev` is the reversed prefix; `current` is the next node; save `next` before changing the link.

### Cycle detection
Floyd: advance slow by one and fast by two. If they meet, a cycle exists. If fast reaches `NULL` (or its next does), the list is acyclic. Never dereference `NULL`.

## 8. Memory and reliability

### Ownership
For every allocation, document who owns it, who frees it, and whether a function transfers ownership. Avoid dangling pointers, double-free, leaks, and use-after-free.

### Reallocation safely
```c
void *tmp = realloc(ptr, new_size);
if (tmp == NULL && new_size != 0) {
    // ptr is still valid; handle failure
} else {
    ptr = tmp;
}
```
Clarify the `new_size == 0` case according to the standard/version and prefer explicit freeing. Check `new_count * sizeof *ptr` against `SIZE_MAX`.

### Debugging
Compile with warnings, use a debugger and available memory-checking tools. Test edge cases and assert preconditions. Do not ignore warnings.

## 9. Strings and parsing

Input may be incomplete, malformed, or too long. Define parsing rules: delimiter, whitespace, blank lines, missing fields, invalid values, buffer limits, and encoding. `strtok` modifies the string and does not parse complex CSV. A full CSV parser must handle quotes, delimiters inside fields, escapes, and line endings.

For pointer tokenization: identify token starts, replace separators with `\0` in a mutable string, store token addresses, and check output capacity.

## 10. File processing strategies

- Copy: fixed-size buffer, check bytes read/written and errors.
- Compare: compare byte blocks, locate first mismatch, and account for different lengths.
- Count lines/words/bytes: define conventions (LF-terminated line vs final unterminated line; what constitutes a word).
- Replace text: use streaming with overlap handling if matches may cross block boundaries, or load into memory with size checks.
- `tail`: either buffer in memory or read backward; choose according to file size.
- Split: count lines and use deterministic filenames.
- Normalize CRLF: treat `\r\n` as a pair; decide explicitly how to handle standalone CR.
- Checksum: distinguish educational hash (djb2) from cryptographic hash; a simple checksum is not adversarial protection.

## 11. Binary data and portability

`fwrite(&object, sizeof object, 1, file)` can store a structure for local use, but it is not a universal durable format. Padding, endianness, type width, representation, and structure version can differ. For portable files, define explicit serialization (fixed-width types, byte order, version, validation) and serialize fields.

## 12. Callbacks

Function pointers let an operation be parameterized: transformation, comparison, numerical integration. Check signatures and never call a null function pointer.

```c
typedef int (*Transform)(int);
void map_ints(int *array, size_t n, Transform fn);
```
A callback contract should specify side effects, return value, valid arguments, and data lifetime.

## 13. Suggested synthesis projects

1. Dynamic array with push, pop, doubling capacity, and allocation failure handling.
2. Generic sorting library with comparator and tests.
3. Contact book (struct) with search, delete, sort, and save.
4. Grade CSV: validated parsing, statistics, ranking, and report.
5. File comparator that reports first differing byte.
6. Mini `tail` supporting very long lines.
7. Non-destructive merge of sorted lists.
8. Linked-list validator (length, cycle, order).
9. Top-k using a heap.
10. Sort benchmark on varied data, measurements, and complexity analysis.

## 14. Final principle

Progress is not memorizing isolated algorithms. For every solution, explain its invariant, preconditions, edge cases, complexity, memory handling, and test strategy.


---

## Credits and Sources

This study guide is based on **Tatiana Aubonnet's** original C course (2008), drawing primarily from the exercises shared by [**S-L-A-K-E-R**](https://github.com/S-L-A-K-E-R), which played a particularly important role in defining the topics covered and the structure of this guide.

Adaptation, organization, and writing: [**1KuMo**](https://github.com/1KuMo).

AI tools were also used to assist with translation, layout, and content organization.

Special thanks to **Tatiana Aubonnet** for her original course, which served as the foundation for this work.
