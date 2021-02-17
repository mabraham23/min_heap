NAME=heap

all: heap

run: heap
	./$(NAME).exe

heap: 
	g++ *.cpp -o $(NAME).exe

gdb:
	g++ -g *.cpp -o $(NAME).exe

clean:
	rm -f *.o *.exe