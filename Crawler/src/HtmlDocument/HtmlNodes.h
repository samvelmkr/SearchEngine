#ifndef HTMLNODES_H
#define HTMLNODES_H

//#include "HtmlDocument.h"
#include "HtmlNode.h"
#include <algorithm>
#include <libxml/xpath.h>

typedef xmlXPathObjectPtr HtmlXPath;

class HtmlNodes {
private:
	std::vector<HtmlNode> nodes;
	std::size_t nSize;
public:
	void setHtmlNodes(HtmlXPath paths);
	
	HtmlNode& operator[](std::size_t pos);
	const HtmlNode& operator[](std::size_t pos) const;
	std::size_t getSize() const;
	
	//std::vector<std::string> extractLinks(HtmlDocument& doc);
	//std::vector<std::string> extractDocument(HtmlDocument& doc);

};

#endif // HTMLNODES_H

