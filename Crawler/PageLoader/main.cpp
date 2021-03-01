#include "PageLoader.h"

#include <iostream>

int main() {

	PageLoader p;
	LoadResult res;
	res =  p.load("http://ysu.am/main");

	std::cout << res.getBody() << " " << res.getStatus() << std::endl;
}
