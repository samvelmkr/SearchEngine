#include "LoadResult.h"

LoadResult::LoadResult() {};

LoadResult::LoadResult(std::shared_ptr<std::string> body, int status) 
	: mBody{ body }
	, mStatus{ status }
{}

std::shared_ptr<std::string> LoadResult::getBody() const {
	return mBody;
}

int LoadResult::getStatus() const {
	return mStatus;
}
