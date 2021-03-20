#include "HtmlNode.h"

void HtmlNode::setHtmlNode (xmlNodePtr n) {
	node = n;
}

bool HtmlNode::isElement() const {
	return node->type == XML_ELEMENT_NODE;
}

std::string HtmlNode::getAttribute(const std::string& name) const {
	if(isElement()) {
		// search an attribute with name "name"
		xmlAttrPtr attr = xmlHasProp(node,(const xmlChar*)name.c_str());
		
		std::stringstream ss;
		if(attr){
			unsigned char* c = xmlGetProp(node, (const xmlChar*)name.c_str());
			ss << c;
		}
		return ss.str();

	}
	return "";
}

std::string HtmlNode::getLink() const {
	if(isElement()) {
		return getAttribute("href");
	}
	return "";
}
