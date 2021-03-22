#ifndef HTMLNODES_H
#define HTMLNODES_H

#include "HtmlDocument.h"
#include "HtmlNode.h"

class HtmlNodes {
private:
	std::vector<HtmlNode> nodes;
	std::size_t nSize;
public:
	void setHtmlNodes(HtmlXPath paths);
	
	HtmlNode& operator[](std::size_t pos);
	const HtmlNode& operator[](std::size_t pos) const;
	std::size_t getSize() const;
	
	std::vector<std::string> extractLinks(HtmlDocument& doc);
};

#endif // HTMLNODES_H

