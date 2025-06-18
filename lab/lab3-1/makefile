scr: testDriver.o scrambled.o 
	gcc -o scr testDriver.o scrambled.o

testDriver.o: testDriver.c scrambled.h
	gcc -Wall -c testDriver.c scrambled.h

scrambled.o: scrambled.c 
	gcc -Wall -c scrambled.c

clean:
	rm -f scr *.o