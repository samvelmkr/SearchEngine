#include <iostream> 
#include "../PageLoader/PageLoader.h"
#include "../HtmlDocument/HtmlDocument.h"
#include "../LinkProcessor/LinkProcessor.h"
#include "../DocumentProcessor/DocumentProcessor.h"
#include "../Website/Website.h"
#include "../LinkRepository/LinkRepository.h"
#include "../DocumentRepos/DocumentRepos.h"

int main() {

	std::vector<Website> websites;
	websites.push_back(Website("rau.am","https://rau.am/"));
	websites.push_back(Website("ysu.am","http://www.ysu.am/main/"));
	websites.push_back(Website("edition.cnn.com","https://edition.cnn.com/"));


	LinkRepository linkrepos;

	

	for(auto& website : websites){
		linkrepos.save(LinkEntry(website.getHomePage(), website.getDomain(), LinkStatus::WAITING));
		
		while(true){
			
			//std::vector<LinkEntry> links = linkrepos.getBy(website.getDomain(), 10, LinkStatus::WAITING);	
			std::vector<LinkEntry> links = linkrepos.getBy(website.getDomain(), LinkStatus::WAITING);
			// std::cout << "HomePage: " << links[0] << "\n\n\n";
			if(links.empty()){
				break;
			}

			for(size_t i = 0; i < links.size(); ++i){
				PageLoader p;
				LoadResult res;
				res = p.load(links[i].getUrl());

				if(res.getStatus() < 200 || res.getStatus() > 299) {
					links[i].setStatus(LinkStatus::ERROR);
					linkrepos.save(links[i]);
					continue;
				}

				std::shared_ptr<std::string> htmlDoc;
				htmlDoc = res.getBody();

				HtmlDocument doc(*htmlDoc);
				doc.init();
				bool isParsed = doc.parse();
				if(!isParsed){
					std::cout << "error while parsing" << std::endl;
				}

				std::vector<std::string> newLinks;
				LinkProcessor lp;
				newLinks = lp.extractLinks(doc, res.getEffectiveUrl());
				
				size_t x = 0;
				while(true){
					if(x == newLinks.size())
						break;

					std::size_t found = newLinks[x].find(":");
					found += 3; // ://
					std::size_t domainStart = found;
					found = newLinks[x].find("www", domainStart);
					if(found != std::string::npos){
						domainStart += 4; // www.
					} 
					std::size_t domainEnd = newLinks[x].find("/", domainStart);
					
					if(newLinks[x].substr(domainStart, domainEnd - domainStart) != website.getDomain()){
						newLinks.erase(newLinks.begin() + x);
					}
					else{
						++x;
					}
				}

				for(std::size_t i = 0; i < newLinks.size(); ++i) {
					linkrepos.save(LinkEntry(newLinks[i], website.getDomain(), LinkStatus::WAITING));
					std::cout << newLinks[i] << "\n";
				}
				// std::cout << newLinks.size() << std::endl;
					
				DocumentProcessor docExtract;
				Document info = docExtract.extractDocument(doc, links[i].getUrl());
				/*
				std::cout << "title:\n" << info.getTitle() << std::endl;
				std::cout << "description:\n" << info.getDescription() << std::endl;
				std::cout << "text:\n" << info.getText() << std::endl;
				*/
				doc.shutdown();
				links[i].setStatus(LinkStatus::SUCCESS);				
				std::cout << linkrepos.getSize() << std::endl;
			}
		}

	}

/*
	PageLoader p;
	LoadResult res;
	res = p.load("https://rau.am");

	if(res.getStatus() < 200 || res.getStatus() > 299) {
		return 0;
	}
	
	std::shared_ptr<std::string> htmlDoc;
	htmlDoc = res.getBody();

	//load("HtmlDocument/index.html", htmlDoc);
	HtmlDocument doc(*htmlDoc);
	doc.init();
	bool isParsed = doc.parse();
	if(!isParsed){
		std::cout << "error while parsing" << std::endl;
	}
	//std::cout << "Success\n";

	std::vector<std::string> links;
	LinkProcessor lp;
	links = lp.extractLinks(doc);
	for(std::size_t i = 0; i < links.size(); ++i) {
		if(links[i].size()) {
			std::cout << "\"" <<links[i] << "\"," << std::endl;
		}
	}
	std::cout << links.size() << std::endl;
	std::cout << "\n\n\n";
	
	DocumentProcessor docs;
	std::vector<std::string> s2 = docs.extractDocument(doc);
	std::cout << "title:\n" << s2[0] << std::endl;
	std::cout << "description:\n" << s2[1] << std::endl;
	std::cout << "text:\n" << s2[2] << std::endl;
	
	doc.shutdown();
*/
	return 0;
}
