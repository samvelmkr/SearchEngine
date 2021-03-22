#include "PageLoader.h"

#include <iostream>

int main() {

	PageLoader p;
	LoadResult res;
	res = p.load("https://rau.am");

	std::cout << *res.getBody().get() << " " << res.getStatus() << std::endl;
}
