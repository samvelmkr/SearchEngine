#include "HtmlNodes.h"
#include <cassert>

void HtmlNodes::setHtmlNodes(HtmlXPath paths) {
	xmlNodeSetPtr nodeset = paths->nodesetval;
	int size = nodeset->nodeNr; // number of nodes in the set 

	std::vector<HtmlNode> vecOfNodes(size);

	// nodes traversal
	for(int i = 0; i < size; ++i) {
		// nodeTab : array of nodes in no particular order
		HtmlNode cur = HtmlNode(xmlNodePtr(nodeset->nodeTab[i])); 
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
/*
std::vector<std::string> HtmlNodes::extractLinks(HtmlDocument& doc) {
	std::vector<std::string> links;

	doc.findNodes("/html/body//a", [&links, this](HtmlXPath xpath){
		setHtmlNodes(xpath);		
		
		for(int i = 0; i < nSize; ++i) {
			if(nodes[i].isElement()) {
				std::string link = nodes[i].getLink();
				links.push_back(link);
			}
		}
	});

	return links;
}
*/
/*
std::vector<std::string> HtmlNodes::extractDocument(HtmlDocument& doc) {
	std::string title = "";
	std::string description = "";
	std::string text = "";
	doc.visitNodes([&title, &description, &text](HtmlNode node){
		if(node.isElement()) {
			if(node.getName() == "title") {
				if(node.getInnerText().size()){
					title.append(node.getInnerText());
				}
			}
			if( node.getName() == "meta" &&
				node.getAttribute("name") == "description"){
				
				if(node.getAttribute("content").size()) {
					description.append(node.getAttribute("content"));
				}	
			}
		}
		else if(node.isText()) {
			if(node.getInnerText().size()) {
				// to replace the newline and the Tab characters with spaces 
				std::string tmp = node.getInnerText();

				std::replace_if(tmp.begin(), tmp.end(), [&](char c){
					return c == '\n' || c == '\t';
				}, ' ');
				
				// to remove the newline characters from content
				//tmp.erase(std::remove(tmp.begin(), tmp.end(), '\n'), tmp.end());
				//
//			text.append(node.getInnerText());
				text.push_back(' ');
			}
		}
	});

	std::vector<std::string> res;
	res.push_back(title);
	res.push_back(description);
	res.push_back(text);

	return res;
}
*/