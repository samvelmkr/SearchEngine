#ifndef LOAD_RESULT_H
#define LOAD_RESULT_H

#include <string>
#include <memory>


class LoadResult {
private:
	/**
	 * Stores the response body
	 */
	std::shared_ptr<std::string> mBody;

	/**
	 * Stores the response status
	 */
	int mStatus;
	std::string effectiveUrl;
public:
	// default constructor
	LoadResult();
	
	// constructor
	LoadResult(std::shared_ptr<std::string> body, int status, const std::string& effUrl);

	// getter methods
	std::shared_ptr<std::string> getBody() const;
	int getStatus() const;
	std::string getEffectiveUrl() const;
};

#endif
