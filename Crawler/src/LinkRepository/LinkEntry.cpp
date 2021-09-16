#include "LinkEntry.h"

// constructor
LinkEntry::LinkEntry (const std::string& str, std::string domain, LinkStatus status) 
	: url{ str }
	, domain{ domain }
	, status{ status }
{}

// return url
std::string LinkEntry::getUrl() const {
	return this->url;
}

LinkStatus LinkEntry::getStatus() const {
	return this->status;
}

std::string LinkEntry::getDomain() const {
	return this->domain;
}

void LinkEntry::setStatus(LinkStatus status) {
	this->status = status;
}