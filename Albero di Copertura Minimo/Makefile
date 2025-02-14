CXX=g++
CXXFLAGS=-std=c++2a -g

all: createFolders bin/GrafoMST

createFolders:
	mkdir -p bin obj

bin/GrafoMST: obj/Edge.o obj/DSU.o obj/Grafo.o obj/GrafoMST.o
	$(CXX) $(CXXFLAGS) $^ -o $@

obj/GrafoMST.o: src/GrafoMST.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

obj/Grafo.o: src/utils/Grafo.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

obj/DSU.o: src/utils/DSU.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

obj/Edge.o: src/utils/Edge.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: bin/GrafoMST
	bin/GrafoMST

debug: bin/GrafoMST
	gdb bin/GrafoMST

clean:
	rm -r bin obj