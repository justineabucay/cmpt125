 /*
 * Filename: Toying_with_Pointers.c
 *
 * Description: Program 1.1 from our reading titled "What is a pointer?".
 * 
 * Date: June 2025
 */
 
 #include <stdio.h>
 
int main( void ) {
 
  int j = 1;
  int k = 2;
  int *ptr = &k;

  printf("\n");
  printf("j has the value %d and is stored at 0x%p\n", j, &j); // the location of the value stored 
  printf("k has the value %d and is stored at 0x%p\n", k, &k); // the location of the value stored

  printf("ptr has the value 0x%p and is stored at 0x%p\n", ptr, &ptr); // the location where the pointer is stored
  printf("the address of the value that ptr points (i.e., %d) to: %p\n", *ptr, ptr); // the location it points to (which is the address of k)
  printf("The value of the integer pointed to by ptr is %d\n", *ptr); // value the pointer points to (the value of k)
   
  return 0;
}