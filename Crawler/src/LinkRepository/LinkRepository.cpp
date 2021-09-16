#include "LinkRepository.h"

// return the vectorof all links
std::vector<LinkEntry> LinkRepository::getAll() const {
	return this->linkRepos;
}
/*
std::vector<LinkEntry> LinkRepository::getBy (const std::string& domain, size_t count, LinkStatus status) const {
	
	std::vector<LinkEntry> res;

	for (size_t i = 0; i < linkRepos.size(); ++i) {
		if(count && domain == linkRepos[i].getDomain()){
			if(linkRepos[i].getStatus() == LinkStatus::WAITING){
				res.push_back(linkRepos[i]);
				--count;
			}		
		}
	}

	return res;
}
*/
std::vector<LinkEntry> LinkRepository::getBy (const std::string& domain, LinkStatus status) const {
	
	std::vector<LinkEntry> res;

	for (size_t i = 0; i < linkRepos.size(); ++i) {
		if(domain == linkRepos[i].getDomain()){ 
			if(linkRepos[i].getStatus() == LinkStatus::WAITING){
				res.push_back(linkRepos[i]);
			}		
		}
	}

	return res;
}
void LinkRepository::save(const LinkEntry& entry) {
	for(size_t i = 0; i < linkRepos.size(); i++){
		if(linkRepos[i].getUrl() == entry.getUrl()){
			linkRepos[i] = entry;
			return;
		}
	}
	linkRepos.push_back(entry);
}
int LinkRepository::getSize() const {
	return this->linkRepos.size();
}
