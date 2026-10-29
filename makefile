OBJ = $(patsubst %.c, %.o, $(wildcard *.c))
address : $(OBJ)
	gcc -o $@ $^
clean:
	rm *.exe *.o
