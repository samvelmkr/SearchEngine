#ifndef HTMLNODES_H
#define HTMLNODES_H

#include "HtmlNode.h"
#include "HtmlDocument.h"

class HtmlNodes {
private:
	std::vector<HtmlNode> nodes;
	std::size_t nodes_size;
public:
	void setHtmlNodes(HtmlXPath paths);
	
	HtmlNode& operator[](std::size_t pos);
	const HtmlNode& operator[](std::size_t pos) const;

	std::size_t getSize() const;
		
};

#endif // HTMLNODES_H

