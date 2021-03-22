#include <iostream>
#include "HtmlNodes.h" 

int main() {
	HtmlDocument doc("index.html");
	doc.init();
	bool isParsed = doc.parse();
	if(!isParsed){
		std::cout << "error while parsing" << std::endl;
	}

	std::vector<std::string> links;
	
	HtmlNodes nodes;
	links = nodes.extractLinks(doc);

	doc.shutdown();
	
	for(int i = 0; i < links.size(); ++i) {
		std::cout << links[i] << std::endl;
	}
	std::cout << links.size() << std::endl; 	
	return 0;
}
