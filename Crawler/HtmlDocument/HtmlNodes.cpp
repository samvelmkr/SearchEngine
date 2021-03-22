#include "HtmlNodes.h"
#include <cassert>

void HtmlNodes::setHtmlNodes(HtmlXPath paths) {
	xmlNodeSetPtr nodeset = paths->nodesetval;
	int size = nodeset->nodeNr; // number of nodes in the set 

	std::vector<HtmlNode> vecOfNodes(size);

	// nodes traversal
	for(int i = 0; i < size; ++i) {
		// nodeTab : array of nodes in no particular order
		HtmlNode cur;
	       	cur.setHtmlNode((xmlNodePtr)nodeset->nodeTab[i]); 
		vecOfNodes[i] = cur;
	}
	

	nodes = vecOfNodes;
	nSize = size;
}

HtmlNode& HtmlNodes::operator[](std::size_t pos) {
	assert(pos >= 0 && pos < nSize);
	return nodes[pos];
}

const HtmlNode& HtmlNodes::operator[](std::size_t pos) const {
	assert(pos >= 0 && pos < nSize);
	return nodes[pos];
}

std::size_t HtmlNodes::getSize() const {
	return nSize;
}

std::vector<std::string> HtmlNodes::extractLinks(HtmlDocument& doc) {
	std::vector<std::string> links;

	doc.findNodes("/html/body//a", [&links, this](HtmlXPath xpath){
		setHtmlNodes(xpath);		
		
		for(int i = 0; i < nSize; ++i) {
			std::string link = nodes[i].getLink();
			if(!link.empty()) {
				links.push_back(link);
			}
		}
	});

	return links;
}

