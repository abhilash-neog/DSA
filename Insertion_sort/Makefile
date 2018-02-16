mytarg: readRecords.o insertionSort.o measureTimeAndSpace.o
	gcc readRecords.o insertionSort.o measureTimeAndSpace.o -o mytarg
readRecords.o: readRecords.c elements.h
	gcc -c readRecords.c
insertionSort.o: insertionSort.c elements.h
	gcc -c insertionSort.c
measureTimeAndSpace.o: measureTimeAndSpace.c elements.h
	gcc -c measureTimeAndSpace.c
