#ifndef PAGE_LOADER_H
#define PAGE_LOADER_H 

#include "LoadResult.h" 

class PageLoader {
private:
	/*		
	 *	For most transfers, this callback gets called many times
	 * and each invoke delivers another chunk of data. ptr points
	 * to the delivered data, and the size of that data is nmemb; 
	 * size is always 1.
	 * 
	 *   void* ptr - received data after request
	 *   size_t size - size of data
	 *   size_t nmemb - number of chunks of data
	 *   void* userdata - data for return
	 */
	 
	static size_t write_to_string(void* prt, size_t size, size_t nmemb, void* userdata);
public:
	PageLoader();
	LoadResult load(const std::string& url);
};

#endif
