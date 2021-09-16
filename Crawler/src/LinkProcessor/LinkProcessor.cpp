#include "LinkProcessor.h"

std::vector<std::string> LinkProcessor::extractLinks(HtmlDocument& doc, const std::string& url) {
    HtmlNodes nodes;
	std::vector<std::string> links;

	doc.findNodes("/html/body//a", [&links, &nodes, &url](HtmlXPath xpath){
		nodes.setHtmlNodes(xpath);		
        
		for(std::size_t i = 0; i < nodes.getSize(); ++i) {
			if(nodes[i].isElement()) {
				std::string link = nodes[i].getLink();
				//-- url parsing
				if(link.empty()){
					continue;
				}

				std::vector<std::string> ends = {".pdf", ".png", ".doc", ".jpg", ".jpeg", ".djvu"};
				bool isdoc = false;
				for(size_t x = 0; x < ends.size(); ++x){
					std::size_t found = link.find(ends[x]);
					if(found != std::string::npos){
						isdoc = true;
						continue;
					}
				}
				if(isdoc){
					continue;
				}

				std::size_t found = link.find(" ");
				if(found != std::string::npos){
					continue;	
				}
				found = link.find(":"); // check protocol
				if(found != std::string::npos){
					if(!(link.substr(0, found) == "https" ||
						link.substr(0, found) == "http")){
					}
					else {
						links.push_back(link);
					}
					continue;
				}
				
				// relative link -> absolute link
				std::string newLink = url; 
				if(link.substr(0, 2) == "//"){
					std::size_t found = newLink.find("://");
					link = newLink.substr(0, found + 1) + link;
				}
				else if(link.substr(0, 3) == "../"){
					int count = 1;
					link.erase(0, 3);
					
					while(true){
						if(link.substr(0, 3) != "../"){
							break;
						}

						link.erase(0, 3);
						++count;
					}
					for(int j = 0; j <= count; ++j){
						std::size_t a = newLink.rfind("/");
						newLink.erase(a, newLink.size() - a);
					}
					link = newLink + "/" + link;
					newLink = url;
				}
				else if(link.front() == '/'){
					std::size_t found = newLink.find("://");
					std::size_t f = newLink.find("/", found + 3);
					if(f == std::string::npos){
						newLink.push_back('/');
						link = newLink + link;
					}
					else {
						newLink.replace(f, newLink.size() - f, link);
					}
					link = newLink;
					newLink = url;
				} 
				else {
					std::size_t a = newLink.rfind("/");
					newLink.erase(a, newLink.size() - a);
					link = newLink + "/" +  link;
					newLink = url;
				}
				links.push_back(link);
			}
		}
	});

	return links;
}