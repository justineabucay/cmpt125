#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "labexam.h"


bool check_non_decreasing(int* arr, int n) {
  // implement me
  

  for(int i = 0; i < n; i++)
  {
      int curr = arr[i];
      int next = arr[i + 1]; 

      if(curr > next) return false;

  }

  return true;
}


int* rev_arr(const int* A, int n) {
  // implement me
  int * result = malloc(n * sizeof(int));
  if(result == NULL) perror("oh no! the allocation was unsuccessful");
  for(int i = 0; i < n; i++) result[i] = A[n - 1 - i]; // initialize new array, result and assigning each element to the corresponding index on A, starting from the end of the array

  return result;
}


int count_distinct(const char** ar, int n) {
  // implement me
  int count = 0;
  bool isDuplicate = false;
  for(int i = 0; i < n; i++)
  {
    isDuplicate = false;
    
    for(int j = 0; j < n; j++){
      if(i != j){
        int match = 1;
        int k = 0;
        while(ar[i][k] != '\0' || ar[j][k] != '\0'){
          if(ar[i][k] != ar[j][k]){
            match = 0;
            break;
          }
          k++;
        }

        if(match){
          isDuplicate = true;
          break;
        }
      }
      if(!isDuplicate) count++;
    }
      
    
    
     
  }
    
  
    
  
  printf("%d\n", count/n);
  return count;
}  
