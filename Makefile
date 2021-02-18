NAME=heap

all: heap

run: heap
	./$(NAME).exe

heap: 
	g++ -std=c++11 *.cpp -o $(NAME).exe

gdb:
	g++ -std=c++11 *.cpp -o $(NAME).exe

clean:
	rm -f *.o *.exe