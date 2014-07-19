#include "x-thesaurus.h"

int main(int argc, char const *argv[])
{
	std::list <std::string> partsofspeech;
	std::vector <std::string> reltyplist;
	std::map <std::string, std::string> reltypmap;
	init(partsofspeech,reltyplist,reltypmap);
	if (argc < 2)
	{
		std::cout << fg.red << "[warning]" << st.reset << " x-thesaurus needs a word to search" << std::endl;
		std::cout << fg.red << "[warning]" << st.reset << " Very few arguments!" << std::endl;
	}
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
					fg.yellow << "[x-thesaurus]" << st.reset << \
					" Sorry couldn't find the word: "\
					+ which_word << std::endl;
					break;
				case 500:
					std::cout << \
					fg.yellow << "[x-thesaurus]" << st.reset << \
					" Usage limit exceeded or Invalid Key" \
					<< std::endl;
					break;
				case 0:
					std::cout << fg.yellow + "[x-thesaurus]" + fg.red + " Connection Time Out!\n" +\
					fg.yellow + "[x-thesaurus]" + fg.red + " Check your Internet Connection!" +\
                    st.reset \
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
				std::cout << \
				fg.red << "[warning]" << st.reset << \
				"Failed to parse configuration\n"
				<< reader.getFormattedErrorMessages();
				continue;
			}
			std::list<std::string>::iterator parts=partsofspeech.begin();
			for (int i=0; i < root.size() && parts != partsofspeech.end() && i < 10; i++, parts++)
			{
				std::cout << \
				fg.green << *parts << st.reset \
				<< std::endl;
				for (int j=0; j < root[*parts].size() && j < 10;j++)
				{
					std::cout << "   " << \
					fg.cyan << reltypmap[reltyplist[j]] << st.reset \
					<< std::endl;
					for (int k=0; k<root[*parts][reltyplist[j]].size() && k < 10; k++)
					{
						std::cout << "      " << \
						st.bold << fg.blue << root[*parts][reltyplist[j]][k].asString() << st.reset \
						<< std::endl;
					}
				}
			}
		}

	}
	return 0;
}
