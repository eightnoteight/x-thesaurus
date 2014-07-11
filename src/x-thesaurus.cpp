#include "x-thesaurus.h"

int main(int argc, char const *argv[])
{
	if (argc < 2)
	{
		std::cout << "[warning] x-thesaurus needs a word to search\n" << std::endl;
		std::cout << "[warning] Very few arguments!" << std::endl;
	}
	int words = argc;
	Geopt opt (argc, argv);
	for (int i = 1; i < words; ++i)
	{
		//http_get_response_t* GET;
		//GET = http_get("http://words.bighugelabs.com/api/2/" + api_key + "/" + opt.get_next() + "/json");
	}
	return 0;
}