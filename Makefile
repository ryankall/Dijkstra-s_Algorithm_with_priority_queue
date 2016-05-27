CC=g++
C++FLAGS=-Wall -std=c++11 -pedantic

AVL_OBJ=main.o
TEST_PROG=findPaths


%.o : %.cpp
	$(CC)  -c $< -o $@ $(C++FLAGS)

all:
	make $(TEST_PROG)
	

$(TEST_PROG): $(AVL_OBJ)
	$(CC) $(C++FLAG) -o $@ $(AVL_OBJ)




clean:
	(rm -f *.o;)
	rm -f $(TEST_PROG)
	
