#ifndef HTMLNODES_H
#define HTMLNODES_H

#include "HtmlNode.h"
#include "HtmlDocument.h"

class HtmlNodes {
private:
	std::vector<HtmlNode> nodes;
public:
	void setHtmlNodes(HtmlXPath paths);
	int getSize() const;
		
};

#endif // HTMLNODES_H

