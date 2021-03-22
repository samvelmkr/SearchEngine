all: lp

lp: main.o PageLoader.o LoadResult.o
	g++ main.o PageLoader.o LoadResult.o -o lp -lcurl 

main.o: main.cpp
	g++ -c main.cpp -o main.o

PageLoader.o: PageLoader.cpp
	g++ -c PageLoader.cpp -o PageLoader.o 

LoadResult.o: LoadResult.cpp
	g++ -c LoadResult.cpp -o LoadResult.o

clean:
	rm -rf *.o lp
