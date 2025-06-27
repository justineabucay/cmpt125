# rastering images: 1D arrays 
- black: 0, 255: white and anywhere between is different shades of grey

## modelling a raster image: 

    const unsigned int width = 5;
    const unsigned int height = 4; 
    unsigned char* img = malloc(width * height * sizeof(unsigned charr)); 

the reason why we are using unsigned char because a char has 8 bits (or 1 byte), where each of these bits could either hold 1 or 2, basically, 8 bits is the smallest space of memory to represent gray value (i.e., black and white)

to visualize the mapping of a raster image, each row will consist of 5 cells, which is the width. basically, the first row matches the first 5 cells and the second row matches the next 5 cells of the array, and so on. 

**to access a pixel**
we can map the coordinates of the 1D array to an index as so: 

    index = x + y * image_width; 

**initialzing raster images**

    for(unsigned int i = 0; i < width*height; i++) // use this method for the function replace_colour() in the practice quiz
        img[i]

    for(unsigned int y = 0l y < rows; y++)
        for(unsigned int x = 0; x < cols; x++)  // divide cols by 2 for the function flip_horizontally()

    memset(img, 0, width * height * sizeof(img[0])); // faster approach: setting all pixels at once

