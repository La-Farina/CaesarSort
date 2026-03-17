# CaesarSort

**CaesarSort** is a sorting algorithm I created, inspired by the divide-and-conquer approach of QuickSort, with a unique pivot selection strategy.

---

## How CaesarSort Works

CaesarSort works in **three main steps**:

1. **Divide**  
   The array is recursively divided into smaller arrays, similar to QuickSort.  
   However, the **pivot** is chosen using the `findPivotClosestToAverage` function.  
   Recursion continues until each sub-array has **20 or fewer items**.

2. **Sort Micro-Blocks**  
   Each small array is sorted by comparing elements from both the **first and last positions**, iteratively, until the array is completely sorted.  
   This “micro-battle” sorting is very fast for small arrays.

3. **Merge**  
   All sorted sub-arrays and pivots are merged back in the correct order to produce the final sorted array.

---

## The `findPivotClosestToAverage` Function

- Calculates the **average value** of the array.  
- Finds the element **closest to this average** to use as the pivot.  
- If multiple elements are equally close, **one is chosen as the pivot**, and the others are placed in the less-or-equal sub-array.  

This strategy helps produce **balanced partitions**, reducing the chance of very unbalanced recursion.

---

## Supported Versions

- **C**: raw code and library format.  
- **Python**: raw code and library format.  

In the future, additional versions in other languages may be added if the algorithm proves useful.

---

## Best and Worst Cases

|   Scenario     | Time Complexity |
|----------------|-----------------|
| **Best case**  | O(n log n)      |
| **Worst case** | O(n²)           |

> The worst case occurs if the pivot selection repeatedly produces unbalanced partitions.

---

## Notes

- CaesarSort is intended primarily for **educational purposes**.  
- Its hybrid divide-and-conquer + micro-battle approach demonstrates concepts like **pivot selection, small-array optimization, and recursive merging**.  
- It can occasionally compete with classic algorithms like MergeSort in real-world performance, thanks to cache-friendly small-array sorting.
