#ifndef LINKREPOSIROTY_H
#define LINKREPOSIROTY_H

#include "LinkEntry.h"
#include <vector>
#include <map>

class LinkRepository {
private:
	std::vector<LinkEntry> linkRepos;

public:
	// return the vector of all links 
	std::vector<LinkEntry> getAll() const;

//	std::vector<LinkEntry> getBy(const std::string& domain, size_t count, LinkStatus status) const;
	std::vector<LinkEntry> getBy(const std::string& domain, LinkStatus status) const;
	
	/*
	 * create a non-existing document
	 * or update an existing document
	 */
	void save(const LinkEntry& entry);
	int getSize() const;
};

#endif // LINKREPOSITORY_H
