CFLAGS=`xml2-config --cflags`
LIBS=`xml2-config --libs`

all: htmlDoc

htmlDoc: HtmlDocument.o HtmlNodes.o HtmlNode.o main.o
	g++ HtmlDocument.o HtmlNodes.o HtmlNode.o main.o -o htmlDoc $(LIBS)

HtmlDocument.o: HtmlDocument.cpp
	g++ $(CFLAGS) -c HtmlDocument.cpp -o HtmlDocument.o

HtmlNodes.o: HtmlNodes.cpp
	g++ $(CFLAGS) -c HtmlNodes.cpp -o HtmlNodes.o

HtmlNode.o: HtmlNode.cpp
	g++ $(CFLAGS) -c HtmlNode.cpp -o HtmlNode.o

main.o: main.cpp
	g++ -c main.cpp -o main.o

clean: 
	rm -rf *.o htmlDoc

