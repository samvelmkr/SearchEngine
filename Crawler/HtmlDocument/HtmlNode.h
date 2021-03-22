#ifndef HTMLNODE_H
#define HTMLNODE_H

#include <vector> 
#include <string>
#include <sstream>
#include <libxml/tree.h>

class HtmlNode{
private:
	xmlNodePtr node;
public:
	void setHtmlNode(xmlNodePtr n);
	bool isElement() const;
	std::string getAttribute(const std::string& name) const;
	bool isValidLink(const std::string& link) const;
	std::string getLink() const;
};

#endif // HTMLNODE_H

