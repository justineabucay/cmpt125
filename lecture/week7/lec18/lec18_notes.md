# 2D Array Data Structure Array
**the building blocks (constructs) we use to build data structures**
- arrays
- pointers
- struct's 

## data structure
- data management that allows access and modification of data, which involves functions designed to manipulate the data in the structure

## arrays
**characteristcs**
- advantage: provide direct access to any element in constant time O(1) b/c elements are stored in contiguous memory locations
- disadvantage: arrays do not know their own size, all elements must be the same type and C does not check if you are accessing valid indices

**concepts**
- often not completely filled and therefore, we need to track both array size and number of actual elements
- elements can be sorted/unsorted and unique/duplicated

**operations**
- insert: add elements to the end if there is space
- remove: find the element and replace it w/ the last element to avoid shifting
- search: look for specific elements
- traverse: go through all elements

## removal algorithm explained
1. find the elemnt to remove 
2. replace it with the last element in the array
3. decrease the count of elements 