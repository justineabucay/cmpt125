/*
 * Filename: imgops.h
 *
 * Description: 10 simple operations on raster images
 *
 * Author: RV - 2014
 * Modified by: AL - 2025
 */

/*-------------------------------------------------
  OPERATIONS ON A PIXEL 
*/
           
/* Get the pixel in the array at coordinate (x,y). */
uint8_t get_pixel( const uint8_t array[], 
		   unsigned int cols, 
		   unsigned int rows,
		   unsigned int x,
		   unsigned int y );

/* Set the pixel at coordinate (x,y) to the specified colour. */
void set_pixel( uint8_t array[], 
		unsigned int cols, 
		unsigned int rows,
		unsigned int x,
		unsigned int y,
		uint8_t colour );

/*-------------------------------------------------
  OPERATIONS ON THE WHOLE IMAGE 
*/

/* Set every pixel to zero 0 (black). */
void zero( uint8_t array[],
	   unsigned int cols,
	   unsigned int rows );

/*
  Returns a pointer to a freshly allocated array that contains the
  same values as the original array, or a null pointer if the
  allocation fails. The caller is responsible for freeing the array
  later.
*/
uint8_t* copy( const uint8_t array[], 
	       unsigned int cols, 
	       unsigned int rows );

/* Return the darkest colour that appears in the image. */
uint8_t darkest( const uint8_t array[], 
	         unsigned int cols, 
	         unsigned int rows );

/* Return the lightest colour that appears in the image. */
uint8_t lightest( const uint8_t array[], 
	          unsigned int cols, 
	          unsigned int rows );

/* Replace every instance of pre_colour with post_colour. */
void replace_colour( uint8_t array[], 
                    unsigned int cols, 
                    unsigned int rows,
                    uint8_t pre_colour,
                    uint8_t post_colour );

/* Flip the image horizontally, left-to-right, like in a mirror. */
void flip_horizontal( uint8_t array[], 
                      unsigned int cols, 
                      unsigned int rows );

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
                  unsigned int *y );

/* Invert the image such that black becomes white and vice
   versa and light shades of grey become the corresponding dark
   shade.
*/
void invert( uint8_t array[], 
             unsigned int cols, 
             unsigned int rows );
