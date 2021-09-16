#ifndef DOCUMENTPROCESSOR_H
#define DOCUMENTPROCESSOR_H

#include "../HtmlDocument/HtmlDocument.h"
#include "../DocumentRepos/DocumentRepos.h"

class DocumentProcessor {
public:
    Document extractDocument(HtmlDocument& doc, const std::string& url);
};

#endif // DOCUMENTPROCESSOR_H