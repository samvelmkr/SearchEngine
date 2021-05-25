#include "HtmlDocument.h"

HtmlDocument::HtmlDocument (const std::string& str) 
	: htmlCode{str}
{}

void HtmlDocument::init() {
	/*
	 * Initialization
	 * Preallocate the parsing state
	 * Call once before processing in case of use in multithreaded programs
	 */
	xmlInitParser(); 
}

void HtmlDocument::shutdown() {
	/*
	 * Free the library state and data
	 * Call only when the process has finished
	 * 
	 * Free the global variables that may
     * have been allocated by the parser.
	 */
	xmlCleanupParser(); 
}

bool HtmlDocument::parse() { 
	// allocate and initialize a new parser context
	htmlParserCtxtPtr parser_context = htmlNewParserCtxt();
	if(!parser_context) {
		return false; 
	}
	
	/* 
	parse an XML file
	doc = htmlCtxtReadFile(parser_context, url.c_str(), NULL,	HTML_PARSE_NOWARNING | HTML_PARSE_NOERROR | HTML_PARSE_RECOVER);
	*/

	// parse an XML string 
	//doc = htmlCtxtReadDoc(parser_context, (const xmlChar*)htmlCode.c_str(), NULL, 
	//NULL, HTML_PARSE_NOWARNING | HTML_PARSE_NOERROR | HTML_PARSE_RECOVER);

	// parse an XML string and get the DOM
	doc = htmlCtxtReadMemory(parser_context, htmlCode.c_str(), htmlCode.size(), NULL, 
	NULL, HTML_PARSE_NOWARNING | HTML_PARSE_NOERROR | HTML_PARSE_RECOVER);

	//Get the root element node 
	root = xmlDocGetRootElement(doc); 

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
	
	// Free up an HtmlXPath object.
	xmlXPathFreeObject(nodes);
	
}

void HtmlDocument::visitNodes(std::function<void(HtmlNode)> visitor) {
	this->visitNode(this->root, visitor);
}

void HtmlDocument::visitNode(xmlNode* a_node, std::function<void(HtmlNode)> visitor) {
	//if(a_node->type != XML_ELEMENT_NODE) {
	//	return;
	//}

	//visitor(HtmlNode(a_node));
	xmlNode* curNode = NULL;
	for(curNode = a_node; curNode; curNode = curNode->next) {
		visitor(HtmlNode(curNode));
		visitNode(curNode->children, visitor);
	}	
}

HtmlDocument::~HtmlDocument() {
	if(doc != NULL) { 
		// free the document
		xmlFreeDoc(doc);
	}
}
