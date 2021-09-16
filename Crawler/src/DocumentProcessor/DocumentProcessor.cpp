#include "DocumentProcessor.h"

Document DocumentProcessor::extractDocument(HtmlDocument& doc, const std::string& url) {
	std::string title = "";
	std::string description = "";
	std::string text = "";
	doc.visitNodes([&title, &description, &text](HtmlNode node){
		if(node.isElement()) {
			if(node.getName() == "title") {
				if(node.getInnerText().size()){
					title.append(node.getInnerText());
				}
			}
			if( node.getName() == "meta" &&
				node.getAttribute("name") == "description"){
				
				if(node.getAttribute("content").size()) {
					description.append(node.getAttribute("content"));
				}	
			}
		}
		else if(node.isText()) {
			if(node.getInnerText().size()) {
				// to replace the newline and the Tab characters with spaces 
				std::string tmp = node.getInnerText();

				std::replace_if(tmp.begin(), tmp.end(), [&](char c){
					return c == '\n' || c == '\t';
				}, ' ');
				
				// to remove the newline characters from content
				//tmp.erase(std::remove(tmp.begin(), tmp.end(), '\n'), tmp.end());
				
				text.append(tmp);
				text.push_back(' ');
			}
		}
	});
	Document info(url, title, description, text);
	return info;
}