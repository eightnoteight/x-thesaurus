#ifndef INIT_H
#define INIT_H
class INIT{
    public :
        static const std::vector<std::string> partsofspeech;
        static const  std::vector<std::string> reltyplist;
        static   std::map<std::string, std::string> reltypmap;
        static const int VERB_INDEX=1;
        static const int NOUN_INDEX=0;
        static const int Synonym_INDEX=0;
        static const int Antonym_INDEX=1;
};
        

std::vector<std::string> partsOfSpeechINIT() {
    std::vector<std::string> partsofspeech;
            partsofspeech.push_back("noun");
            partsofspeech.push_back("verb");
            partsofspeech.push_back("adjective");
            partsofspeech.push_back("adverb");
            partsofspeech.push_back("pronoun");
            partsofspeech.push_back("preposition");
            partsofspeech.push_back("conjunction");
            partsofspeech.push_back("interjection");
    return partsofspeech;
}
	
std::vector<std::string> reltypListINIT() {
   std::vector<std::string> reltyplist;
            reltyplist.push_back("syn");
            reltyplist.push_back("ant");
            reltyplist.push_back("usr");
            reltyplist.push_back("rel");
            reltyplist.push_back("sim");
    return reltyplist;
}
std::map<std::string, std::string> reltypMapINIT(){
            std::map<std::string, std::string> reltypmap;
            reltypmap["syn"] = "Synonyms";
            reltypmap["ant"] = "Antonyms";
            reltypmap["usr"] = "User Suggestions";
            reltypmap["rel"] = "Related Terms";
            reltypmap["sim"] = "Similar Types";
            return reltypmap;
    
}
	
        const std::vector<std::string> INIT::partsofspeech=partsOfSpeechINIT();
        const std::vector<std::string> INIT::reltyplist=reltypListINIT();
         std::map<std::string, std::string> INIT::reltypmap=reltypMapINIT();

#endif