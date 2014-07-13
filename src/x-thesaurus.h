#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <fstream>

#include <curl/curl.h>
#include "../lib/jsoncpp.cpp"
#include "getoptions.h"
#include "../lib/http-get/http-get.cpp"
#include <json/json.h>

std::string api_key = "YOURAPIKEY";//12a85ecd6e7543af55a878e45c263086

inline bool init(std::list<std::string> partsofspeech,
					std::vector<std::string> reltyplist,
						std::map<std::string, std::string> reltypmap)

{
	partsofspeech.push_back("noun");
	partsofspeech.push_back("verb");
	partsofspeech.push_back("adjective");
	partsofspeech.push_back("adverb");
	partsofspeech.push_back("pronoun");
	partsofspeech.push_back("preposition");
	partsofspeech.push_back("conjunction");
	partsofspeech.push_back("interjection");

	reltyplist.push_back("syn");
	reltyplist.push_back("ant");
	reltyplist.push_back("rel");
	reltyplist.push_back("sim");
	reltyplist.push_back("usr");
	
	reltypmap["syn"] = "Synonyms";
	reltypmap["ant"] = "Antonyms";
	reltypmap["rel"] = "Related Terms";
	reltypmap["sim"] = "Similar Types";
	reltypmap["usr"] = "User Suggestions";
	return 1;
}