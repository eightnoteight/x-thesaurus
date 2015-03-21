#include "x-thesaurus.h"


void printPartOfSpeech( Json::Value &root,const Geopt &opt,std::string partOFSpeach){
    
    std::cout << fg.green << partOFSpeach << st.reset << std::endl;
    
//     if(!opt.isOnlySynonyms() && !opt.isOnlyAntonyms()){
        for(unsigned int i=0;i<root[partOFSpeach].size();i++ ){
            
            if(i==INIT::Synonym_INDEX&&opt.isOnlyAntonyms()){
                continue;
            }
            std::cout << "   " << fg.cyan << INIT::reltypmap[INIT::reltyplist[i]] <<
            st.reset << std::endl;
           for (unsigned int j = 0;j<root[partOFSpeach][INIT::reltyplist[i]].size()&&j<opt.getMaxNumberOfResults(); j++) {
                std::cout << "      " << st.bold <<
                fg.blue <<
                root[partOFSpeach][INIT::reltyplist[i]]
                [j].asString() << st.
                reset << std::endl;
           }
           if(i==INIT::Synonym_INDEX&&opt.isOnlySynonyms())
               return;
           else if(i==INIT::Antonym_INDEX&&opt.isOnlyAntonyms())
               return;
        }
        
        
//     }
                                    
    
}
int main(int argc, char const *argv[])
{
	
        Geopt opt(argc, argv);
	int words = argc - opt.getIndexOfFirstWord();
	if (words < 1) {
		std::cout << fg.red << "[warning]" << st.reset << st.
		    bold << " x-thesaurus needs a word to search" << st.
		    reset << std::endl;
		std::cout << fg.red << "[warning]" << st.reset << st.
		    bold << " Very few arguments!" << st.reset << std::endl;
	}
	
	for (int i = 1; i <= words; ++i) {
		std::string which_word = opt.get_next();
		GET get("http://words.bighugelabs.com/api/2/" + api_key + "/" +
			which_word + "/json");
		if (!get.ok) {
			switch (get.status) {
			case 404:
				std::cout <<
				    fg.yellow << "[x-thesaurus]" << st.reset <<
				    " Sorry couldn't find the word: "
				    + which_word << std::endl;
				break;
			case 500:
				std::cout <<
				    fg.yellow << "[x-thesaurus]" << st.reset <<
				    " Usage limit exceeded or Invalid Key"
				    << std::endl;
				exit(1);
				break;
			case 0:
				std::cout << fg.yellow + "[x-thesaurus]" +
				    fg.red + " Connection Time Out!\n" +
				    fg.yellow + "[x-thesaurus]" + fg.red +
				    " Check your Internet Connection!" +
				    st.reset << std::endl;
				exit(1);
				break;
			}
		} else {
			Json::Value root;
			Json::Reader reader;
			std::ifstream file;
			file.open((get.filename).c_str());
			std::istream & inp = file;
			bool parsingSuccessful = reader.parse(inp, root);
			file.close();
			if (!parsingSuccessful) {
				std::cout <<
				    fg.red << "[warning]" << st.reset <<
				    "Failed to parse configuration\n"
				    << reader.getFormattedErrorMessages();
				continue;
			}
                        if(opt.isOnlyNouns()){
                             printPartOfSpeech(root,opt,INIT::partsofspeech[INIT::NOUN_INDEX]);
                            
                        }
			if(opt.isOnlyVerbs()){
                            printPartOfSpeech(root,opt,INIT::partsofspeech[INIT::VERB_INDEX]);
                            
                        }
                        if(!(opt.isOnlyNouns()||opt.isOnlyVerbs())){
                            unsigned int j=0;
                            for(std::vector<std::string>::const_iterator i=INIT::partsofspeech.begin();
                                i!=INIT::partsofspeech.end()&&j<root.size();i++,j++)
                                        printPartOfSpeech(root,opt,*i);
                        }
                        
                        
			
		}

	}
	return 0;
}
