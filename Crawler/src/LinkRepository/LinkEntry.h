#ifndef LINKENTRY_H
#define LINKENTRY_H

#include <ctime>
#include <string>

class LinkEntry {
private:
	// time when the link was found
	std::time_t createTime = std::time(nullptr);

	// time when the link was passed
	std::time_t crawlingTime = std::time(nullptr);

	// link url
	std::string url;

	// unique identifier for the link
	int id;
public:
	// default constructor
	LinkEntry() = default;
	// constructor
	LinkEntry(const std::string& str, int num);

	// return id
	int getId() const;

	// return url
	std::string getUrl() const;

	bool isCrawled() const;
	
	// set crawlingTime after the link passing 
	void setCrawlingTime();
};

#endif // LINKENTRY_H

