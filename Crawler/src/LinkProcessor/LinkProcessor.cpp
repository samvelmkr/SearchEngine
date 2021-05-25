#include "LinkProcessor.h"

std::vector<std::string> LinkProcessor::extractLinks(HtmlDocument& doc) {
    HtmlNodes nodes;
	std::vector<std::string> links;

	doc.findNodes("/html/body//a", [&links, &nodes](HtmlXPath xpath){
		nodes.setHtmlNodes(xpath);		
        
		for(std::size_t i = 0; i < nodes.getSize(); ++i) {
			if(nodes[i].isElement()) {
				std::string link = nodes[i].getLink();
				links.push_back(link);
			}
		}
	});

	return links;
}