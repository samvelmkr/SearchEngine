#ifndef HTMLNODE_H
#define HTMLNODE_H

#include <vector> 
#include <string>
#include <sstream>
#include <libxml/tree.h>

class HtmlNode{
private:
	xmlNode* node = NULL;
public:
	HtmlNode() = default;
	HtmlNode(xmlNode* n);
	bool isElement() const;
	bool isText() const;
	std::string getAttribute(const std::string& name) const;
	bool isValidLink(const std::string& link) const;
	std::string getLink() const;
	std::string getInnerText() const;
	std::string getName() const;
};

#endif // HTMLNODE_H

