compare: compare.o merge_iter.o merge.h
	gcc compare.o merge_iter.o -o compare
compare.o: compare.c merge_iter.c merge.h
	gcc -c compare.c merge_iter.c 
merge_iter.o: merge_recursion.c merge.h 
	gcc -c merge_recursion.c 
merge_recursion.o: merge_iter.c merge.h
	gcc -c merge_iter.c
runRecMS: merge_recursion.o
	gcc merge_recursion -o runRecMS
runIterMS: merge_iter.o
	gcc merge_iter.o -o runIterMS

