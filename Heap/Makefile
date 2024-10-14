CXX=g++
CXXFLAGS=-std=c++2a

all: createFolders bin/test

createFolders:
	mkdir -p bin obj

bin/test: obj/test.o obj/Gatto.o
	$(CXX) $(CXXFLAGS) $^ -o $@

obj/test.o: src/test.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

obj/Gatto.o: src/utils/Gatto.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: bin/test
	bin/test

clean:
	rm -rf bin obj