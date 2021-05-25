#include <iostream> 
#include "../PageLoader/PageLoader.h"
#include "../HtmlDocument/HtmlDocument.h"
#include "../LinkProcessor/LinkProcessor.h"
#include "../DocumentProcessor/DocumentProcessor.h"

int main() {
	PageLoader p;
	LoadResult res;
	res = p.load("https://rau.am");

	if(res.getStatus() < 200 || res.getStatus() > 299) {
		return 0;
	}
	
	std::shared_ptr<std::string> htmlDoc;
	htmlDoc = res.getBody();

	//load("HtmlDocument/index.html", htmlDoc);
	HtmlDocument doc(*htmlDoc);
	doc.init();
	bool isParsed = doc.parse();
	if(!isParsed){
		std::cout << "error while parsing" << std::endl;
	}
	//std::cout << "Success\n";

	std::vector<std::string> links;
	LinkProcessor lp;
	links = lp.extractLinks(doc);
	for(std::size_t i = 0; i < links.size(); ++i) {
		if(links[i].size()) {
			std::cout << links[i] << std::endl;
		}
	}
	std::cout << links.size() << std::endl;
	std::cout << "\n\n\n";
	
	DocumentProcessor docs;
	std::vector<std::string> s2 = docs.extractDocument(doc);
	std::cout << "title:\n" << s2[0] << std::endl;
	std::cout << "description:\n" << s2[1] << std::endl;
	std::cout << "text:\n" << s2[2] << std::endl;
	
	doc.shutdown();

	return 0;
}
