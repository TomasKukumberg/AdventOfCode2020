output: main.o func.o 
	gcc main.o func.o -o output 

main.o: main.c 
	gcc -c main.c

func.o: func.c func.h
	gcc -c func.c

ifeq ($(OS),Windows_NT)
	clean:
		del *.o output.exe
else
	clean:
		rm *.o output
endif
