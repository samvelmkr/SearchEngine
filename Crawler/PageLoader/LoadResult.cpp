#include "LoadResult.h"

LoadResult::LoadResult() {};

LoadResult::LoadResult(const std::string& body, int status) 
	: mBody{ body }
	, mStatus{ status }
{		
}


std::string LoadResult::getBody() {
	return this->mBody;
}

int LoadResult::getStatus() {
	return this->mStatus;
}
