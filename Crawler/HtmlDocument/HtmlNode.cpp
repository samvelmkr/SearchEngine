#include "HtmlNode.h"

void HtmlNode::setHtmlNode (xmlNodePtr n) {
	node = n;
}

bool HtmlNode::isElement() const {
	return node->type == XML_ELEMENT_NODE;
}

std::string HtmlNode::getAttribute(const std::string& name) const {
	// search an attribute with name "name"
	xmlAttrPtr attr = xmlHasProp(node,(const xmlChar*)name.c_str());
	
	std::stringstream ss;
	if(attr){
		unsigned char* c = xmlGetProp(node, (const xmlChar*)name.c_str());
		ss << c;
	}
		
	if(isValidLink(ss.str())) {  
		return ss.str();
	}
	return "";
}

bool HtmlNode::isValidLink(const std::string& link) const {
	if(link.empty() || link[0] == '#') {
		return false;
	}
	// TODO: check if absolute or relative link
	/*
	if(link.rfind("http://") != std::string::npos ||
			link.rfind("https://") != std::string::npos) {
		return false;
	}
	*/
	return true;
}

std::string HtmlNode::getLink() const {
	if(isElement()) {
		return getAttribute("href");
	}
	return "";
}
