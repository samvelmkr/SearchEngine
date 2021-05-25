#ifndef LINKREPOSIROTY_H
#define LINKREPOSIROTY_H

#include "LinkEntry.h"
#include <vector>
#include <map>

class LinkRepository {
private:
	std::map<int, LinkEntry> source;

public:
	// return the vector of all links 
	std::vector<LinkEntry> getAll() const;

	// return LinkEntry by id
	LinkEntry getById(int id) const;
	
	/*
	 * create a non-existing document
	 * or update an existing document
	 */
	void save(LinkEntry& entry);
};

#endif // LINKREPOSITORY_H

