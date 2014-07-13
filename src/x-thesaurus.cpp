#include "x-thesaurus.h"

int main(int argc, char const *argv[])
{
	if (argc < 2)
	{
		std::cout << "[warning] x-thesaurus needs a word to search" << std::endl;
		std::cout << "[warning] Very few arguments!" << std::endl;
	}
	std::list<std::string> partsofspeech;
	std::vector<std::string> reltyplist;
	std::map<std::string, std::string> reltypmap;
	init(partsofspeech,reltyplist,reltypmap);
	int words = argc;
	Geopt opt (argc, argv);
	for (int i = 1; i < words; ++i)
	{
		std::string which_word = opt.get_next();
		GET get("http://words.bighugelabs.com/api/2/" + api_key + "/" + which_word + "/json");
		if (!get.ok)
		{
			switch(get.status)
			{
				case 404:
					std::cout << \
					"[x-thesaurus] Sorry couldn't find the word: "\
					+ which_word << std::endl;
					break;
				case 500:
					std::cout << \
					"[x-thesaurus] Usage limit exceeded or Invalid Key"\
					<< std::endl;
					break;
				case 0:
					std::cout << std::string("[x-thesaurus] Connection Time Out!\n") +\
					std::string("[x-thesaurus] Check your Internet Connection!")\
					<< std::endl;
					break;
			}
		}
		else
		{
			Json::Value root ;
			Json::Reader reader;
			std::ifstream file;
			file.open((get.filename).c_str());
			std::istream& inp = file;
			bool parsingSuccessful = reader.parse(inp, root);
			file.close();
			if ( !parsingSuccessful )
			{
				std::cout << "Failed to parse configuration\n"
				<< reader.getFormattedErrorMessages();
				continue;
			}
			std::list<std::string>::iterator parts=partsofspeech.begin();
			for (int i=0; i < root.size() && parts != partsofspeech.end() && i < 10; i++, parts++)
			{
				std::cout << *parts << std::endl;
				for (int j=0; j < root[*parts].size() && j < 10;j++)
				{
					std::cout << "\t" << reltypmap[reltyplist[j]] << std::endl;
					for (int k=0; k<root[*parts][reltyplist[j]].size() && k < 10; k++)
					{
						std::cout << "\t\t" << root[*parts][reltyplist[j]][k].asString() << std::endl;
					}
				}
			}
		}

	}
	return 0;
}
