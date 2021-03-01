#ifndef LOAD_RESULT_H
#define LOAD_RESULT_H

#include <string>

class LoadResult {
private:
	/**
	 * Stores the response body
	 */
	std::string mBody;

	/**
	 * Stores the response status
	 */
	int mStatus;
public:
	LoadResult();
	LoadResult(const std::string& body, int status);
	std::string getBody();
	int getStatus();
};

#endif
