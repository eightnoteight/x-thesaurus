#include "x-thesaurus.h"

int main(int argc, char const *argv[])
{
	if (argc < 2)
	{
		std::cout << "[warning] x-thesaurus needs a word to search" << std::endl;
		std::cout << "[warning] Very few arguments!" << std::endl;
	}
	int words = argc;
	Geopt opt (argc, argv);
	for (int i = 1; i < words; ++i)
	{
		GET get("http://words.bighugelabs.com/api/2/" + api_key + "/" + opt.get_next() + "/json");
		std::cout << get.ok << std::endl;
		std::cout << get.status << std::endl;
		std::cout << get.msg << std::endl;
		Json::Value root;
		Json::Reader reader;
		std::cout << get.filename << std::endl;
		std::ifstream file;
		file.open((get.filename).c_str());
		std::istream& inp = file;
		bool parsingSuccessful = reader.parse(inp,root);
		file.close();
		if ( !parsingSuccessful )
		{
			std::cout << "Failed to parse configuration\n"
			<< reader.getFormattedErrorMessages();
			continue;
		}
		std::cout << root << std::endl;

	}
	return 0;
}