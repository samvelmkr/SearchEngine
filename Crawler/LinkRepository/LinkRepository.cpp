#include "LinkRepository.h"

// return the vectorof all links
std::vector<LinkEntry> LinkRepository::getAll() const {
	std::vector<LinkEntry> vec;
	
	// pass source and push LinkEntries into vector
	for(auto elem : source) {
		vec.push_back(elem.second);
	}

	return vec;
}

// return LinkEntry by id
LinkEntry LinkRepository::getById (int id) const {
	auto it = source.find(id);
	if(it != source.end()) {
		return it->second;
	}
	// HAVE TO CORRECT
	return it->second;
}

void LinkRepository::save(LinkEntry& entry) {
	auto it = source.find(entry.getId());
	if(it == source.end()) {
		int id = entry.getId();
		std::string url = entry.getUrl();

		LinkEntry newEntry(url, id);
		source.insert({ id, newEntry });
	}

	else {
		it->second.setCrawlingTime();
	}
}
