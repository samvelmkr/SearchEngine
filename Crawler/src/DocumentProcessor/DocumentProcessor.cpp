#include "DocumentProcessor.h"

std::vector<std::string> DocumentProcessor::extractDocument(HtmlDocument& doc) {
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

	std::vector<std::string> res;
	res.push_back(title);
	res.push_back(description);
	res.push_back(text);

	return res;
}