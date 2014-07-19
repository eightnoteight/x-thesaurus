inline bool init(std::list<std::string>& partsofspeech,
					std::vector<std::string>& reltyplist,
						std::map<std::string, std::string>& reltypmap)

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
	reltyplist.push_back("usr");
	reltyplist.push_back("rel");
	reltyplist.push_back("sim");
	
	reltypmap["syn"] = "Synonyms";
	reltypmap["ant"] = "Antonyms";
	reltypmap["usr"] = "User Suggestions";
	reltypmap["rel"] = "Related Terms";
	reltypmap["sim"] = "Similar Types";

	fg.black	= "\033[30m";
	fg.red 		= "\033[31m";
	fg.green	= "\033[32m";
	fg.yellow	= "\033[33m";
	fg.blue 	= "\033[34m";
	fg.magenta	= "\033[35m";
	fg.cyan		= "\033[36m";
	fg.white	= "\033[37m";
	bg.black	= "\033[40m";
	bg.red 		= "\033[41m";
	bg.green 	= "\033[42m";
	bg.yellow	= "\033[43m";
	bg.blue 	= "\033[44m";
	bg.magenta	= "\033[45m";
	bg.cyan		= "\033[46m";
	bg.white	= "\033[47m";
	st.bold		= "\033[1m";
	st.blink	= "\033[5m";
	st.reset	= "\033[0m";
	st.rvid		= "\033[7m";
	return 1;
}
