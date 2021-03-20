#ifndef HTMLDOCUMENT_H
#define HTMLDOCUMENT_H

#include <string>
#include <functional>
#include <iostream>
#include <cerrno>
#include <libxml/tree.h>
#include <libxml/xpath.h>
#include <libxml/HTMLparser.h>
// #include "HtmlXPath.h"

typedef xmlXPathObjectPtr HtmlXPath;

class HtmlDocument {
private:
	htmlDocPtr doc;
	std::string url;
public:
	HtmlDocument(const std::string& str);
	
	void init();
	void shutdown();

	bool parse();

	void findNodes(const std::string& xpath_query, std::function<void(HtmlXPath)> nodeFunc); // void* data
	
};

#endif // HTMLDOCUMENT_H

