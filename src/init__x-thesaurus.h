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
	return 1;
}
