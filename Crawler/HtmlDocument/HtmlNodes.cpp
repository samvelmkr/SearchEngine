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
	nodes_size = size;
}

HtmlNode& HtmlNodes::operator[](std::size_t pos) {
	assert(pos >= 0 && pos < nodes_size);
	return nodes[pos];
}

const HtmlNode& HtmlNodes::operator[](std::size_t pos) const {
	assert(pos >= 0 && pos < nodes_size);
	return nodes[pos];
}

std::size_t HtmlNodes::getSize() const {
	return nodes_size;
}

