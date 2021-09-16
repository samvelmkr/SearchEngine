#include "LoadResult.h"

LoadResult::LoadResult() {};

LoadResult::LoadResult(std::shared_ptr<std::string> body, int status, const std::string& effUrl) 
	: mBody{ body }
	, mStatus{ status }
	, effectiveUrl{ effUrl }
{}

std::shared_ptr<std::string> LoadResult::getBody() const {
	return this->mBody;
}

int LoadResult::getStatus() const {
	return this->mStatus;
}

std::string LoadResult::getEffectiveUrl() const {
	return this->effectiveUrl;
}
