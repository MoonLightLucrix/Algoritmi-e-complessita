CXX=g++
CXXFLAGS=-g

all: createFolders bin/test

createFolders:
	mkdir -p bin obj

bin/test: obj/test.o
	$(CXX) $(CXXFLAGS) $< -o $@

obj/test.o: src/test.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: bin/test
	bin/test

debug: bin/test
	gdb bin/test

clean:
	rm -rf bin obj
