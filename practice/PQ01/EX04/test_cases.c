#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "labexam.h"

void test_q1() { 
  char str0[] = "hello";
  char str1[] = "AEIOUaeiou";
  char str2[] = "oNe-TwO-ThReE";
  char* ar[3] = {str0, str1, str2};

  /**********test answer**********/ 
  if (hide_vowels(ar, 3)==10   // answer = 2+5+3
      && strcmp(str0, "h*ll*")==0
      && strcmp(str1, "AEIOU*****")==0
      && strcmp(str2, "*N*-TwO-ThR*E")==0)
    printf("Q1 ok\n");
  else
    printf("Q1 ERROR\n");
}


void test_q2() { 
  int ar[4][3] = { { 1, 2, 0},
                   { 4, 7,-3},
                   {-9,10,12},
                   { 1, 5,-9}};
  int* ans = sum_columns(4,3,ar);
  
  /**********test answer**********/ 
  int correct[] = {-3,24,0};
  if (ans==NULL) {
    printf("Q2 ERROR\n");
    return;
  }
  for (int i = 0; i < 3; i++)
    if (ans[i] != correct[i])  {
    printf("Q2 ERROR\n");
    return;
  }
  
  free(ans);

  printf("Q2 ok\n");
}

void test_q3() { 
  int ar1[] = {3,1,2,4,7,1,1,8,1,2,9,5};
  int ar2[] = {9,7,2,0,-5};

  int ans1 = longest_increasing_seq(ar1,12);
  int ans2 = longest_increasing_seq(ar2,5);
  /**********test answer**********/ 

  if (ans1==4 && ans2==1)
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
