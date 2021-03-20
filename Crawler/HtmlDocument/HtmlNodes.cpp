#include "HtmlNodes.h"

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
}

int HtmlNodes::getSize() const {
	return nodes.size();
}

