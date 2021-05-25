#ifndef HTMLDOCUMENT_H
#define HTMLDOCUMENT_H

#include <string>
#include <functional>
#include <iostream>
#include <cerrno>
//#include <libxml/tree.h>
//#include <libxml/xpath.h>
#include <libxml/HTMLparser.h>

//#include "HtmlNode.h"
#include "HtmlNodes.h"

//typedef xmlXPathObjectPtr HtmlXPath;

class HtmlDocument {
private:
	htmlDocPtr doc = NULL;
	std::string htmlCode;
	xmlNode* root;

public:
	// constructor
	HtmlDocument(const std::string& str);
	
	void init();
	void shutdown();
	bool parse();
	
	void findNodes(const std::string& xpath_query, std::function<void(HtmlXPath)> nodeFunc); // void* data
	void visitNodes(std::function<void(HtmlNode)> visitor);
	void visitNode(xmlNode* a_node, std::function<void(HtmlNode)> visitor);
	// destructor
	~HtmlDocument();	
};

#endif // HTMLDOCUMENT_H

