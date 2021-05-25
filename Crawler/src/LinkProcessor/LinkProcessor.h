#ifndef LINKPROCESSOR_H
#define LINKPROCESSOR_H

#include "../HtmlDocument/HtmlDocument.h"

class LinkProcessor {
public:
	std::vector<std::string> extractLinks(HtmlDocument& doc);
	// make absolute url from relative url
};

#endif // LINKPROCESSOR_H