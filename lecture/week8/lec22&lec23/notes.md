, # searching
## linear searching
- examines each element in the array until it finds its target or all elements have been checked
- works for both unsorted/sorted arrays

        linearSearch(array, size, elementCount, target)
            set result to value TARGET_NOT_FOUND
            set targetNotFound to value true
            
            if array not empty
                set currentElement to first element of array
                while targetNotFound AND have not looked at every element of array
                    if currentElement == target
                        set result to current element
                        set targetNotFound to false
                    otherwise
                        set currentElement to next element of array
            
            return result

### time complexity scenarios:
- **best**: target is the first element
- **worse**: target is the last element
- **average**: traversing through each element; O(n/2) = O(n)

## binary searching (iterative)
**data must be sorted**
- find the middle element of the array
- see if the middle element is the target
- if it is the target, then target has been found
- if target < middle, search left half
- if target > middle, search right half
- repeat until found or no elements left 

        binarySearch(array, size, elementCount, target)
            set position to value TARGET_NOT_FOUND
            set targetNotFound to value true
            set first = 0
            set last = elementCount - 1
            
            if array not empty
                while targetNotFound AND have not looked or discarded every element of array
                    (first <= last)
                    
                    middleIndex = floor( (first + last) / 2 )
                    
                    if array[middleIndex] == target
                        set position to middleIndex // position of target in array
                        set targetNotFound to false
                    else
                        if target < array[middleIndex]
                            last = middleIndex – 1 // ignore second half of array
                        else
                            first = middleIndex + 1 // ignore first half of array
            
            return position

### time complexity
- **best**: O(1), target is middle element
- **worse**: O(log 2 n), continues halving until 1 element is left
- **average**: O(log 2 n)

## big O notation & complexity analysis
- describes the upper bound of an algorithm's time/space complexity as input size grows

### Big O orders (fast->slowest)
- O(1): constant 
- O(log n): log
- O(n): linear
- O(n log n): linearithmic
- O(n^2): quadratic

### big O calculation rules
- sqn: O(max(f1, f2)) - if A is O(n) and B is O(1), then total is O(n)
- nested: O(f1 * f2) - loop inside loop: O(n) * O(n) = O(n^2)
- ignore constants: O(3n) = O(n)
- ignore lower order terms: O(n^2 + n) = O(n^2)

## linear vs binary
### performance example
what is the worse case for each algorithm for 1 million elements?
- linear: comparing all elements
- binary: comparing 20 comparisons

## resursion w/ binary search

        binarySearchRecursive(array, target, left, right):
            if left > right:
                return -1  // Base case: not found
            
            middle = (left + right) / 2
            if array[middle] == target:
                return middle  // Base case: found
            else if target < array[middle]:
                return binarySearchRecursive(array, target, left, middle-1)
            else:
                return binarySearchRecursive(array, target, middle+1, right)

### concepts
- **base case**: condition that stops recursion
- **recursive case**: function calls itself, where each call works on smaller problem

## space complexity
- amt of memory space an algorithm uses relative to input size
### examples
- linear: O(1) - uses a few variables
- binary (iterative): O(1)  - uses constant extra space
- binary (recursive): O(log n) - due to call stack

===

# comprehension test
 
1. the best way to search through an array with 1000 elements is using the binary algorithm, because rather than traversing through each element of the array, it cuts the array in half and repeats until it finds the target or when all elements have been checked. 
2. the code contains a loop inside a loop which has a Big O complexity of O(n) * O(n) = O(n^2) and therefore, has a quadratic time. 
3. when we are trying to search for 67 (target) in an array, we are comparing the first index and the last index and finding the middle: 0 + 8 = 8 / 2 = 4, where index 4 is now middle. then, we check if target is equal to middle, which it is because 67 is at index 4.
4. binary search is not always better because it only works on sorted array and it is complex to maintain. 
    - when we need to sort the array first, then we need O(n log n) time
    - recursive binary search uses. O(log n) space
5. i would first sort the data first and then use binary search to search for data. 

=== 

# sorting
### selection sort - O(n^2)
- Finds the MINIMUM (or maximum) element in the unsorted section and swaps it with the FIRST element of the unsorted section. It doesn't compare adjacent elements.
- **time complexity**: comparisons = n(n-1)/2, swaps = n-1 => O(n^2)
- **stability**: unstable

        for(i = 0; j < n-1; j++)
        {
            int min = i;
            for(j = i+1; i < n; i++){
                if(arr[j] < a[min]) min = j;
            }

            if(min != i) swap(a[i]), a[min]
        }

## bubble sort - O(n^2), worse (unstable)
- repeatedly steps through the lists, compares adjacent elements + swaps them if they are in the wrong order
- **space complexity**: O(1)

        void bubbleSort(int arr[], int n) {
            for (int i = 0; i < n - 1; i++) {
                for (int j = 0; j < n - i - 1; j++) {
                    if (arr[j] > arr[j + 1]) {
                        // Swap elements
                        int temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                    }
                }
            }
        }

## insertion sort (stable)
- consider first element as already sorted
- start from second element 
    - pick first element from unsorted section
    - compare w/ sorted section elements (rt -> lt)
    - shift elements to make space
    - insert element in correct position
### comparing scenarios
- **best, O(n)**: when all is sorted and where each element only needs 1 comparison 
- **worse, O(n^2)**: when it is reverse, which means each element needs max comaprisons and must shift
### example
**array: [64, 25, 12, 22, 11]**
- sorted: [64], unsorted: [25, 12, 22, 11]
    - insert 25
    - compare: 25 < 64, shifts 64 to the right
    - comparison: 1, shifts: 1
- insert 12
    - compare 12 < 64, shifts 64 to the right
    - compare 12 < 25, shifts 12 to the right
    - comparison: 2, shifts: 2
- insert 22 
    - compare 22 < 64, shifts 64 to the right
    - compare 22 < 25, shifts to the right
    - compare 22 > 12, no shift
    - comparison: 3, shifts: 2
- insert 11
    - compare 11 < 64, shifts 64 to the right
    - compare 11 < 25, shifts 25 to the right
    - compare 11 < 22, shifts 22 to the right
    - compate 11 < 12, shifts 12 to the right
    - comparison: 4, shifts: 4

## merge sort - O(n log n), best
- divides array in half, sorts each half, then merges them back tgt

        void merge(int arr[], int left, int mid, int right) {
            int n1 = mid - left + 1;
            int n2 = right - mid;
            
            int L[n1], R[n2];
            
            // Copy data to temp arrays
            for (int i = 0; i < n1; i++)
                L[i] = arr[left + i];
            for (int j = 0; j < n2; j++)
                R[j] = arr[mid + 1 + j];
            
            // Merge the temp arrays back
            int i = 0, j = 0, k = left;
            while (i < n1 && j < n2) {
                if (L[i] <= R[j]) {
                    arr[k] = L[i];
                    i++;
                } else {
                    arr[k] = R[j];
                    j++;
                }
                k++;
            }
            
            // Copy remaining elements
            while (i < n1) {
                arr[k] = L[i];
                i++;
                k++;
            }
            while (j < n2) {
                arr[k] = R[j];
                j++;
                k++;
            }
        }

        void mergeSort(int arr[], int left, int right) {
            if (left < right) {
                int mid = left + (right - left) / 2;
                
                mergeSort(arr, left, mid);
                mergeSort(arr, mid + 1, right);
                
                merge(arr, left, mid, right);
            }
        }

## quick sort - O(n log n), average
- picks a pivot element, partitions array around pivot, then recursively sorts sub-arrays

        int partition(int arr[], int low, int high) {
            int pivot = arr[high];  // Choose last element as pivot
            int i = (low - 1);
            
            for (int j = low; j <= high - 1; j++) {
                if (arr[j] < pivot) {
                    i++;
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
            int temp = arr[i + 1];
            arr[i + 1] = arr[high];
            arr[high] = temp;
            return (i + 1);
        }

        void quickSort(int arr[], int low, int high) {
            if (low < high) {
                int pi = partition(arr, low, high);
                
                quickSort(arr, low, pi - 1);
                quickSort(arr, pi + 1, high);
            }
        }

## sorting algorithm stability
- stable = if it preserves the relative order of equal elements
**for example**
- stable sort result: [2♣, 3♥, 5♠, 5♦, 5♣]
    - notice: all 5s maintain their original relative order (♠ before ♦ before ♣)
- unstable sort result: [2♣, 3♥, 5♦, 5♣, 5♠]
    - notice: The 5s are in a different order than originally

=== 

# comprehension test: sorting algorithms
