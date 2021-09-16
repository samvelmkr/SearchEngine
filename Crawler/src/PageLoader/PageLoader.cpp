#define CURL_STATICLIB

#include <curl/curl.h>
#include <iostream>
#include <cerrno>

#include "PageLoader.h"

PageLoader::PageLoader() {};

size_t PageLoader:: write_to_string(void* ptr, size_t size, size_t count, void* stream) {
	
	((std::string*)stream)->append((char*)ptr, size * count);
	return size * count;
}

LoadResult PageLoader::load(const std::string& url) {

	// initialize CURL
	CURL* curl = curl_easy_init();
	if(!curl) {
		std::cerr << "Init failed: " << errno << std::endl;
		exit(errno);
		// MAKE THE ERROR HANDLER
	}

	std::string* str_result = new std::string;

	// set options
	curl_easy_setopt(curl, CURLOPT_URL, url.c_str()); // set the link to page
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_to_string); // callback function
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void*)str_result); // white result to string
	curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1); // redirect 
	curl_easy_setopt(curl, CURLOPT_MAXREDIRS, 3); // stop redirecting ad infinitum 
	
	// preform out action
	CURLcode result = curl_easy_perform(curl);
	if(result != CURLE_OK) {
	 	std::cerr << "download problem: " << curl_easy_strerror(result) << std::endl;
	 	exit(errno);
	}
	
	char* effUrl = NULL;
	curl_easy_getinfo(curl, CURLINFO_EFFECTIVE_URL, &effUrl);
	std::string effectiveURL(effUrl);
	
	long status_code = 0;
	curl_easy_getinfo (curl, CURLINFO_RESPONSE_CODE, &status_code);
	/*
	if(status_code >= 200 && status_code < 300 && result != CURLE_ABORTED_BY_CALLBACK) {
		// succeeded
	}
	else {
		// failed	
	}
	*/
	curl_easy_cleanup(curl);
	return LoadResult(std::shared_ptr<std::string>(str_result), status_code, effectiveURL);
	
	// No need to delete str_result as we used std::shares_ptr
}
