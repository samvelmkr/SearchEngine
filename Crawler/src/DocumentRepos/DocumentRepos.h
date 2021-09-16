#ifndef DOCUMENT_REPOS
#define DOCUMENT_REPOS

#include <string>

class Document{
private:
    std::string url;
    std::string title;
    std::string description;
    std::string text;
public:
    Document(const std::string& url, const std::string& title, 
            const std::string& description, const std::string& text);
    std::string getUrl() const;
    std::string getTitle() const;
    std::string getDescription() const;
    std::string getText() const;
};

#endif 
