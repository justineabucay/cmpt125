# Makefile for RASTER lab by RTV. 

# Makefiles help manage the compilation process.  
# To use this makefile, run 'make' in the directory containing this file.

# compiler options
CFLAGS = -std=c99 -g -Wall -O3
LDFLAGS = -lm -lpng

# find X11 libraries on most platforms, including Linux in CSIL
LDFLAGS += `pkg-config --libs x11` 
CFLAGS  += `pkg-config --cflags x11`

# find X11 library on other platforms, e.g. OS X with XQuartz installed.
# CFLAGS  += -I/usr/X11/include 
# LDFLAGS += -L/usr/X11/lib -lX11 


SRC1 = testDriver.c CodingQuiz1.c draw.c png.c
CQ1: $(SRC1) draw.h png.h CodingQuiz1.h
	gcc $(CFLAGS) -o CQ1 $(SRC1) $(LDFLAGS)

clean:
	rm -f CQ1 *.o
