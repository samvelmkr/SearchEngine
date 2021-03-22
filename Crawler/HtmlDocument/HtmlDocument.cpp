#include "HtmlDocument.h"

HtmlDocument::HtmlDocument (const std::string& str) 
	: url{str}
{}

void HtmlDocument::init() {
	// initialization
	// preallocate the parsing state
	xmlInitParser();
}

void HtmlDocument::shutdown() {
	// free the library state and data
	xmlCleanupParser(); 
}

bool HtmlDocument::parse() { 
	// allocate aon initialize a new parser context
	htmlParserCtxtPtr parser_context = htmlNewParserCtxt();
	if(!parser_context) {
		return false; 
	}
	
	// parse an XML file
	doc = htmlCtxtReadFile(parser_context, url.c_str(), NULL,
			HTML_PARSE_NOWARNING | HTML_PARSE_NOERROR | HTML_PARSE_RECOVER);

	// free all the memory used by parser_context
	htmlFreeParserCtxt(parser_context);

	return true;
}


void HtmlDocument::findNodes(const std::string& xpath_query, std::function<void(HtmlXPath)> nodeFunc) {
	// create a new xmlXPathContext
	xmlXPathContextPtr xpath_ctx = xmlXPathNewContext(doc);

	// evaluate the XPath location path in the xpath_ctx
	HtmlXPath nodes(xmlXPathEvalExpression((const xmlChar*)xpath_query.c_str(), xpath_ctx));
	/*if(!nodes) {
		"failed"
	}*/	

	xmlXPathFreeContext(xpath_ctx);

	nodeFunc(nodes);
}


