CXX = g++
CXXFLAGS = -Wall

mytest: wordTree.o bNode.o bookTree.o mytest.cpp
	$(CXX) $(CXXFLAGS) wordTree.o bNode.o bookTree.o mytest.cpp -o mytest

bookTree.o: bookTree.h bookTree.cpp bNode.o wordTree.o
	$(CXX) $(CXXFLAGS) -c bookTree.cpp

bNode.o: bNode.h bNode.cpp wordTree.o
	$(CXX) $(CXXFLAGS) -c bNode.cpp

wordTree.o: wordTree.h wordTree.cpp
	$(CXX) $(CXXFLAGS) -c wordTree.cpp

run:
	./mytest

clean:
	-rm -f *~ *.o

val:
	valgrind ./mytest

