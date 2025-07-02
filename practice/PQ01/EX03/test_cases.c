#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "labexam.h"

void test_q1() { 
  int ar1[] = {2,6,7,19,19,6,100,500};
  int ar2[] = {-3,-3,0,1,2,2,7,40,100};
  bool ans1 = check_non_decreasing(ar1, 8);
  bool ans2 = check_non_decreasing(ar2, 9);
  
  /**********test answer**********/ 
  if (ans1==false && ans2==true)
    printf("Q1 ok\n");
  else
    printf("Q1 ERROR\n");
}

void test_q2() { 
  int ar[] = {-2,10,10,19,6,-1,5};

  int* ans = rev_arr(ar, 7);

  /**********test answer**********/ 
  if (ans==NULL) {
    printf("Q2 ERROR\n");
    return;
  }
  for (int i = 0; i < 7; i++)
    if (ans[i] != ar[6-i])  {
    printf("Q2 ERROR\n");
    return;
  }
  
  free(ans);

  printf("Q2 ok\n");
}

void test_q3() { 
  const char* ar1[] = {"Hello", "Hello", "hi", "Hi", "Hello", "Hi"};
  const char* ar2[] = {"A", "B", "C", "D", "E"};
  const char* ar3[] = {"c++", "c++", "c++", "c++", "c++", "c++", "c++", "c++"};
  int ans1 = count_distinct(ar1, 6);
  int ans2 = count_distinct(ar2, 5);
  int ans3 = count_distinct(ar3, 8);


  /**********test answer**********/ 

  if (ans1==3 && ans2==5 && ans3==1)
    printf("Q3 ok\n");
  else
    printf("Q3 ERROR\n");
 }

int main() {
  test_q1();
  test_q2();
  test_q3();
  return 0;
}
