#include "HtmlNode.h"

HtmlNode::HtmlNode (xmlNode* n) :node{n}
{}

bool HtmlNode::isElement() const {
	return node->type == XML_ELEMENT_NODE;
}

bool HtmlNode::isText() const {
	return node->type == XML_TEXT_NODE;
}

std::string HtmlNode::getAttribute(const std::string& name) const {
	// search an attribute
	xmlAttrPtr attr = xmlHasProp(node,(const xmlChar*)name.c_str());
	
	std::stringstream ss;
	if(attr){
		xmlChar* c = xmlGetProp(node, (const xmlChar*)name.c_str());
		ss << c;
		xmlFree(c);
	}
		
	return ss.str();
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
	std::string tmp = getAttribute("href");
	if(isValidLink(tmp)) {
		return tmp;
	}
	return "";	
}

std::string HtmlNode::getInnerText() const {	
	std::stringstream ss;
	xmlChar* c = xmlNodeGetContent(node);
    ss << c;
	xmlFree(c);
	return ss.str();	
}

std::string HtmlNode::getName() const {
	std::stringstream ss;
    ss << node->name;
	return ss.str();
}