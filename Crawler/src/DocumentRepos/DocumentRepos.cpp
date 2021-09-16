#include "DocumentRepos.h"

Document::Document(const std::string& url, const std::string& title, 
            const std::string& description, const std::string& text)
            : url{url} 
            , title{title}
            , description{description}
            , text{text} 
            {}

std::string Document::getUrl() const {
    return this->url;
}
std::string Document::getTitle() const {
    return this->title;
}
std::string Document::getDescription() const {
    return this->description;
}
std::string Document::getText() const {
    return this->text;
}
