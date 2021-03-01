#define CURL_STATICLIB

#include <curl/curl.h>
#include <iostream>
#include <cerrno>

#include "PageLoader.h"

size_t write_to_string(void* ptr, size_t size, size_t count, void* stream) {
	((std::string*)stream)->append((char*)ptr, 0, size * count);
	return size * count;
}

PageLoader::PageLoader() {};

LoadResult PageLoader::load(const std::string& url) {

	CURL* curl = curl_easy_init();
	if(!curl) {
		std::cerr << "init failed" << std::endl;
		exit(errno);
	}

	std::string str_result;

	// set options
	curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_to_string);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &str_result);

	curl_easy_setopt(curl, CURLOPT_FAILONERROR, 1L);
	// preform out action
	CURLcode result = curl_easy_perform(curl);
	if(result != CURLE_OK) {
	 	std::cerr << "download problem: " << curl_easy_strerror(result) << std::endl;
	 	exit(errno);
	}
	
	long status_code = 0;
	curl_easy_getinfo (curl, CURLINFO_RESPONSE_CODE, &status_code);
	if(result != CURLE_HTTP_RETURNED_ERROR){
		// succeeded
	}
	else {
		// failed	
	}

	return LoadResult(str_result, status_code);
	
}
