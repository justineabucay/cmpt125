/*
 * Filename: imgops.c
 *
 * Description: 10 simple operations on raster images.
 *
 * Author: RV - 2014
 * Modified by: AL - 2025
 *
 * Completed by: <Put your name here>
 * Completion Date: 
 */

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*-------------------------------------------------
  OPERATIONS ON A PIXEL 
*/

/* Get the pixel in the array at coordinate (x,y). */
uint8_t get_pixel( const uint8_t array[], 
                   unsigned int cols, 
                   unsigned int rows,
                   unsigned int x,
                   unsigned int y ) 
{	   
  // Parameter validation
  assert( x < cols );
  assert( y < rows );
	
  // Converting (x,y) -> index
  return array[x + y * cols];
}

/* Set the pixel at coordinate (x,y) to the specified colour. */
void set_pixel( uint8_t array[], 
                unsigned int cols, 
                unsigned int rows,
                unsigned int x,
                unsigned int y,
                uint8_t colour ) 
{
  // Parameter validation
  assert( x < cols );
  assert( y < rows );
	
  // Converting (x,y) -> index
  array[x + y * cols] = colour; 
  return;
} 

/*-------------------------------------------------
  OPERATIONS ON THE WHOLE IMAGE 
*/

/* Set every pixel to zero 0 (black). */
 void zero( uint8_t array[],
	   unsigned int cols,
	   unsigned int rows )
{
  // your code here.
  memset(array, 0, cols * rows * sizeof(uint8_t));
  return;
} 

/*
  Returns a pointer to a freshly allocated array that contains the
  same values as the original array, or a null pointer if the
  allocation fails. The caller is responsible for freeing the array
  later.
*/
uint8_t * copy( const uint8_t array[], 
               unsigned int cols, 
               unsigned int rows )
{
  // your code here
  uint8_t * ret = malloc(cols * rows * sizeof(uint8_t));
  if (ret == NULL) 
    perror("Call to malloc failed\n");
  else
    memcpy(ret, array, cols * rows * sizeof(uint8_t));

  return ret;
}

/* Return the darkest colour that appears in the image. */
uint8_t darkest( const uint8_t array[], 
                 unsigned int cols, 
                 unsigned int rows )
{
  // your code here
  uint8_t ret = 255;
  for (unsigned int i = 0; i < cols * rows; i++) {
    ret = ret < array[i] ? ret : array[i];
  }
  return ret;
}

/* Return the lightest colour that appears in the image. */
uint8_t lightest( const uint8_t array[], 
	              unsigned int cols, 
	              unsigned int rows )
{
  // your code here
  uint8_t ret = 0;
  for (unsigned int i = 0; i < cols * rows; i++) {
    ret = ret > array[i] ? ret : array[i];
  }
  return ret;
}

/* Replace every instance of pre_colour with post_colour. */
void replace_colour( uint8_t array[], 
                    unsigned int cols, 
                    unsigned int rows,
                    uint8_t pre_colour,
                    uint8_t post_colour )
{
  // your code here
  for (unsigned int i = 0; i < cols*rows; i++) {
    if (array[i] == pre_colour) {
      array[i] = post_colour;
    }
  }
  return;
}

void swap(uint8_t * a, uint8_t * b) {
  *a = *b ^ *a;
  *b = *b ^ *a;
  *a = *b ^ *a;
  return;
}

/* Flip the image horizontally, left-to-right, like in a mirror. */
void flip_horizontal( uint8_t array[], 
                      unsigned int cols, 
                      unsigned int rows )
{
  // your code here
  for (unsigned int y = 0; y < rows; y++) {
    for (unsigned int x = 0; x < cols/2; x++) {
      swap(array + y * cols + x, array + y * cols + (cols - x - 1));
    }
  }
  return;
}

/* Find the coordinates (x,y) of the first pixel with a value that
   equals colour. Search from left-to-right, top-to-bottom. If it is
   found, store the coordinates in *x and *y and return 1. If it is
   not found, return 0.
*/
int locate_colour( const uint8_t array[],              
                  unsigned int cols, 
                  unsigned int rows,
                  uint8_t colour,
                  unsigned int * x,
                  unsigned int * y )
{
  // your code here
  for (unsigned int i = 0; i < cols * rows; i++) {
    if (array[i] == colour) {
      *y = i / cols;
      *x = i % cols;
      return 1;
    }
  }
  return 0;
}

/* Invert the image such that black becomes white and vice
   versa and light shades of grey become the corresponding dark
   shade.
*/
void invert( uint8_t array[], 
             unsigned int cols, 
             unsigned int rows )
{
  // your code here
  for (unsigned int i = 0; i < cols * rows; i++) {
    array[i] = ~array[i];
  }
  return;
}
