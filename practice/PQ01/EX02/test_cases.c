#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "labexam.h"

void test_q1() { 
  int ar[] = {2,6,7,19,19,6,1,5};
  min_max ans = get_min_max(ar,8);
  
  /**********test answer**********/ 
  if (ans.min==1 && ans.max==19)
    printf("Q1 ok\n");
  else
    printf("Q1 ERROR\n");
}

void test_q2() { 
  int ar1[4][3] = {{1, 2, 3},
                   {4, 7,-2},
                   {9,10,12},
                   {1, 5, 4}};
  bool ans1 = has_equal_columns(4,3,ar1);
  int ar2[3][5] = {{ 1, 2, 2, 1, 5},
                   {-9,10,12,-9,-2},
                   { 1, 5, 1, 1, 8}};
  bool ans2 = has_equal_columns(3,5,ar2);
  
  /**********test answer**********/ 
  if (ans1==false && ans2==true)
    printf("Q2 ok\n");
  else
    printf("Q2 ERROR\n");
}

int mult3(int x) {return x*3;}

void test_q3() { 
  int ar[] = {-2,10,10,19,6,-1,5};

  int* ans = map_to_new_array(ar, 7, mult3);

  /**********test answer**********/ 
  int correct[] = {-6,30,30,57,18,-3,15};
  if (ans==NULL) {
    printf("Q3 ERROR\n");
    return;
  }
  for (int i = 0; i < 7; i++)
    if (ans[i] != correct[i])  {
    printf("Q3 ERROR\n");
    return;
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
