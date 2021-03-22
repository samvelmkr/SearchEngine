all: l

l: LinkEntry.o LinkRepository.o main.o
	g++ LinkEntry.o LinkRepository.o main.o -o l

LinkEntry.o: LinkEntry.cpp
	g++ -c LinkEntry.cpp -o LinkEntry.o

LinkRepository.o: LinkRepository.cpp
	g++ -c LinkRepository.cpp -o LinkRepository.o

main.o: main.cpp
	g++ -c main.cpp -o main.o

clean: 
	rm -rf *.o l

