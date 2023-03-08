CC = clang++
list: List_Int.o main_List_Int.o
	$(CC) -o $@ $^

%.o: %.cpp
	$(CC) -c $<

.PHONY: clean
clean:
	rm -f *.o list