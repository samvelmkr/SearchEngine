#include "LinkEntry.h"

// constructor
LinkEntry::LinkEntry (const std::string& str, int num) 
	: url{ str }
	, id{ num }
{
	// convert the createTime to a calendar local time
	std::asctime(std::localtime(&createTime));
	crawlingTime = createTime;
}

// return id
int LinkEntry::getId() const {
	return id;
}

// return url
std::string LinkEntry::getUrl() const {
	return url;
}

bool LinkEntry::isCrawled() const {
	// if createTime and crawlingTime are equal => link has not been passed(crawled)
	return !(createTime == crawlingTime);
}

// set crawlingTime after the link passing
void LinkEntry::setCrawlingTime() {
	// convert the crawlingTime to a calendar local time
	std::asctime(std::localtime(&crawlingTime));
}
