CC = clang-15
CFLAGS = -Wall

%.o: %.cpp
	$(CC) $(CFLAGS) -c %< -o $@

program: main.o
	$(CC) -o program main.o

.PHONY clean
clean:
	rm -f *.o program