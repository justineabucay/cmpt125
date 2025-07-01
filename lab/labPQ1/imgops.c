/*
 * Filename: imgops.c
 *
 * Description: 10 simple operations on raster images
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
  // Put your code here
  memset(array, 0, rows * cols * sizeof(array[0]));

  return;
}

/*
  Returns a pointer to a freshly allocated array that contains the
  same values as the original array, or a null pointer if the
  allocation fails. The caller is responsible for freeing the array
  later.
*/
uint8_t* copy( const uint8_t array[], 
               unsigned int cols, 
               unsigned int rows )
{
  // Put your code here
  unsigned char *img = malloc(cols * rows * sizeof(unsigned char));
  if(img == NULL) return NULL; // checks if allocation fails; if so, return NULL

  memcpy(img, array, cols * rows * sizeof(unsigned char)); // use memcpy to copy the same values as the original array

  return img; // You will need to change NULL to something more appropriate.
}

/* Return the darkest colour that appears in the image. */
uint8_t darkest( const uint8_t array[], 
                 unsigned int cols, 
                 unsigned int rows )
{
  // Put your code here
  uint8_t darkest = array[0]; // start at the first element of the array
  for(unsigned int i = 1; i < cols * rows; i ++){
    if(array[i]< darkest) darkest = array[i];  // if the current pixel is darker than the current darkest pixel, assign darkest to the current pixel
  }

  return darkest; // You will need to change 0 to something more appropriate.
}

/* Return the lightest colour that appears in the image. */
uint8_t lightest( const uint8_t array[], 
	              unsigned int cols, 
	              unsigned int rows )
{
  // Put your code here
  uint8_t lightest = array[0]; // start at the first element of the array
  for (unsigned int i = 1; i < cols * rows; i++)
  {
    if (array[i] > lightest)
      lightest = array[i]; // if the current pixel is lighter than the current lightest pixel, assign lightest to the current pixel
  }

  return lightest; // You will need to change 0 to something more appropriate.
}

/* Replace every instance of pre_colour with post_colour. */
void replace_colour( uint8_t array[], 
                    unsigned int cols, 
                    unsigned int rows,
                    uint8_t pre_colour,
                    uint8_t post_colour )
{
  // Put your code here
  for (unsigned int i = 1; i < cols * rows; i++)
  {
    if (array[i] == pre_colour) // find each instance 0f pre_colour
      array[i] = post_colour;   // replace it with post_colour
  }
  return;
}

/* Flip the image horizontally, left-to-right, like in a mirror. */
void flip_horizontal( uint8_t array[], 
                      unsigned int cols, 
                      unsigned int rows )
{
  // Put your code here
  for (unsigned int y = 0; y < rows; y++){
    for (unsigned int x = 0; x < cols / 2; x++){ // divide cols by 2 to iterate through half the columns 
      // find the pixels to swap
      unsigned int left = y * cols + x; 
      unsigned int right = y * cols + (cols - 1 - x);

      // swapping the pixels
      uint8_t temp = array[left];
      array[left] = array[right]; 
      array[right] = temp;
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
                  unsigned int *x,
                  unsigned int *y )
{
  // Put your code here
  for(unsigned int row = 0; row < rows; row++){
    for(unsigned int col = 0; col < cols; col++){
      unsigned int index = row * cols + col; // convert 2D to 1D 
      if(array[index] == colour){
        *x = col; 
        *y = row;
        return 1; // found the coordinates
      } 
    }
  }
  // return 0 if not found
  return 0;  // You will need to change 0 to something more appropriate.
}

/* Invert the image such that black becomes white and vice
   versa and light shades of grey become the corresponding dark
   shade.
*/
void invert( uint8_t array[], 
             unsigned int cols, 
             unsigned int rows )
{
  // Put your code here
  for (unsigned int i = 0; i < cols * rows; i++)
  {
    array[i] = 255 - array[i]; // for each array substact its balue from 255
  }
  return;
}
