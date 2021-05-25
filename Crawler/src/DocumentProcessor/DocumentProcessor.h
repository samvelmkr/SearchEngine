#ifndef DOCUMENTPROCESSOR_H
#define DOCUMENTPROCESSOR_H

#include "../HtmlDocument/HtmlDocument.h"

class DocumentProcessor {
public:
    std::vector<std::string> extractDocument(HtmlDocument& doc);
};

#endif // DOCUMENTPROCESSOR_H