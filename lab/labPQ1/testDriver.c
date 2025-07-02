/*
 * Filename: testDriver.c
 *
 * Description: Test functions from imgops.c
 * 
 * Author: RV - 2014
 * Modified by: AL - 2025
 */

#include <stdlib.h> // for random()
#include <stdint.h> // for explicit integer types, eg. uint8_t
#include <string.h> // for memset()
#include <assert.h>
#include <stdio.h>

// image drawing functions
#include "draw.h"

// load PNG image function
#include "png.h"

// image manipulation functions
#include "imgops.h"


int main( int argc, char* argv[] ) {

  // Windowing system setup
  const unsigned int winwidth  = 500;
  const unsigned int winheight = 500;

  // Declaring variables modelling a raster image:
  unsigned int imgwidth  = winwidth / 4;
  unsigned int imgheight = winheight / 4 ;
  uint8_t * img = NULL;
  
  // initialize the graphics system
  // ********************************************************
  // Get a first window
  draw_startup( (char*)"Window 1", winwidth, winheight );

  if( argc == 2 ) // if a filename was specified
  {
    uint32_t depth=0;
    int alpha=0;
    if( LoadPngImage( argv[1], &imgwidth, &imgheight, &depth, &alpha, &img ) == 0 )
    {
      printf( "failed to load image %s\n", argv[1] );
      exit(1);
    }
  }
  else // no filename specified: create a blank image
  {
    // allocate an array for our image
    img = malloc( imgwidth * imgheight * sizeof(uint8_t) );
    if( img == NULL )
    {
      printf( "failed to allocate memory for image.\n" );
      exit(1);
    }

    // set the whole array to zero (black)
    memset( img, 0, imgwidth * imgheight * sizeof(img[0] ));
  }

  // draw the array as a grey-scale image in the window
  // This function returns after a user clicks or presses a button in the window
  printf( "Original image\n" );
  draw_image_grey( img, imgwidth, imgheight );

  // ********************************************************
  // Get a second window
  draw_startup( (char*)"Window 2", winwidth, winheight );

  // Testing copy function: Get a copy of original image
  printf( "Image copied\n" );
  uint8_t * img_Copied = copy( img, imgwidth, imgheight );

  // draw the array as a grey-scale image in the window
  // This function returns after a user clicks or presses a button in the window
  draw_image_grey( img_Copied, imgwidth, imgheight );

  // ********************************************************

  // Get a third window
  draw_startup( (char*)"Window 3", winwidth, winheight );

  // Testing flip_horizontal function: 
  // Flip the image horizontally, from left to right, like in a mirror.
  printf( "Image flipped horizontally\n" );
  flip_horizontal( img_Copied, imgwidth, imgheight );

  // draw the array as a grey-scale image in the window
  // This function returns after a user clicks or presses a button in the window
  draw_image_grey( img_Copied, imgwidth, imgheight );

  // ********************************************************

 /*   // Get a fourth window
  draw_startup( (char*)"Window 4", winwidth, winheight );

  // Testing zero function:
  printf( "Set every pixel to zero 0 (black)\n" );
  zero( img_Copied, imgwidth, imgheight ); */

  // draw the array as a grey-scale image in the window
  // This function returns after a user clicks or presses a button in the window
  draw_image_grey( img_Copied, imgwidth, imgheight );

  // ********************************************************

    // Copy
  draw_startup( (char*)"Window 5", winwidth, winheight );
  printf( "Testing function: copy\n" );
  copy( img_Copied, imgwidth, imgheight );
  draw_image_grey( img_Copied, imgwidth, imgheight );

  // Darkest

  draw_startup( (char*)"Window 6", winwidth, winheight );
  printf( "Testing function: darkest\n" );
  printf("%d", darkest( img_Copied, imgwidth, imgheight ));
  draw_image_grey( img_Copied, imgwidth, imgheight );

  // Lightest
  draw_startup( (char*)"Window 7", winwidth, winheight );
  printf( "Testing function: lightest\n" );
  printf("%d", lightest( img_Copied, imgwidth, imgheight ));
  draw_image_grey( img_Copied, imgwidth, imgheight );

  // Replace Colour
  uint8_t pre = 33; 
  uint8_t post = 210; 
  draw_startup( (char*)"Window 8", winwidth, winheight );
  printf( "Testing function: replace_colour\n" );
  replace_colour( img_Copied, imgwidth, imgheight, pre, post);
  draw_image_grey( img_Copied, imgwidth, imgheight );

  // Locate Colour 
uint8_t target_colour = 128;  // Grayscale value to search for

// Declare actual variables to store the result
unsigned int x = 0;
unsigned int y = 0;

draw_startup( (char*)"Window 9", winwidth, winheight );
printf( "Testing function: locate_colour\n" );

// Pass the addresses of x and y
int found = locate_colour(img_Copied, imgwidth, imgheight, target_colour, &x, &y);

if (found) {
  printf("Colour %d found at (%u, %u)\n", target_colour, x, y);
} else {
  printf("Colour %d not found in the image.\n", target_colour);
}

draw_image_grey(img_Copied, imgwidth, imgheight);

  

  // Invert
  draw_startup( (char*)"Window 10", winwidth, winheight );


  printf( "Testing function: invert\n" );
  invert( img_Copied, imgwidth, imgheight);
  draw_image_grey( img_Copied, imgwidth, imgheight);


  // finalize the graphics system, freeing its resources
  draw_shutdown();

  // every malloc() should have a matching free()
  free(img);
  free(img_Copied);
  
  // let's get in the habit of setting all freed pointers to NULL
  img = NULL;
  img_Copied = NULL;
  
  return 0;
}
