#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "labexam.h"

void test_q1() { 
  char* str = "a--@98@hi@B!i!o@!";
  char_int ans = most_frequent(str);  

  if (ans.c=='@' && ans.n==4)
    printf("Q1 ok\n");
  else
    printf("Q1 ERROR\n");
}

bool is_odd(int x) {return x%2==1;}
bool is_greater_equal_zero(int x) {return x>=0;}  

void test_q2() { 
  int ar1[] = {2,6,2,3,8,9};
  int ar2[] = {1,-6,-3,9,7,9,0,1};
  int ans1 = filter_to_zero(ar1, 6, is_odd);
  int ans2 = filter_to_zero(ar2, 8, is_greater_equal_zero);


  /**********test answer**********/ 
  int correct1[] = {0,0,0,3,0,9};
  int correct2[] = {1,0,0,9,7,9,0,1};
  
  if (!(ans1==4 && ans2==2)) {
    printf("Q2 ERROR: incorrect return value\n");
    return;
  }

  for(int i=0;i<6;i++)
    if (ar1[i]!=correct1[i]) {
      printf("Q2 ERROR: incorrect result ar1\n");
      return;
    }
  for(int i=0;i<8;i++)
    if (ar2[i]!=correct2[i])  {
      printf("Q2 ERROR: incorrect result ar2\n");
      return;
    }

  printf("Q2 ok\n");
} 

void test_q3() { 
  int ar1[] = {1,2,3,4,5};
  int ar2[] = {1,0,2,0,-5};

  int* ans = sum_arrays(ar1, ar2, 5); 
  /**********test answer**********/ 
  int correct[] = {2,2,5,4,0};
  if (ans==NULL) {
    printf("Q3 ERROR\n");
    return;
  }
  for (int i = 0; i < 5; i++) {
    if (ans[i] != correct[i]) {
      printf("Q3 ERROR: incorrect returned sum\n");
      return;
    }
  }
  
  free(ans);

  printf("Q3 ok\n");

}

int main() {
  test_q1();
  test_q2();
  test_q3();
  return 0;
}
