#ifndef LINKENTRY_H
#define LINKENTRY_H

#include <ctime>
#include <string>
#include "LinkStatus.h"

class LinkEntry {
private:
	// link url
	std::string url;
	std::string domain;
	LinkStatus status;
public:
	// default constructor
	LinkEntry() = default;
	// constructor
	LinkEntry(const std::string& str, std::string domain, LinkStatus status);

	// return url
	std::string getUrl() const;
	std::string getDomain() const;
	LinkStatus getStatus() const;

	void setStatus(LinkStatus status);
};

#endif // LINKENTRY_H

