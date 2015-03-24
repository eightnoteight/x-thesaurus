// Geopt is nice for purposes like this where the 
// args are just the repitions of the program
class Geopt
{
private:
        
        int readFlags(int argc,char const *argv[]);
        bool onlyNouns;
        bool onlyVerbs;
        bool onlySynonyms;
        bool onlyAntonyms;
        int indexOfFirstWord;
        unsigned int maxNumberOfResults;
        const static std::string HELP_MSG;
        const static std::string WRONG_FLAG_MSSG;
        
	std::queue<std::string> options;
	int optind;
public: 
        int getIndexOfFirstWord()const;
        unsigned int  getMaxNumberOfResults()const;
        bool isOnlyNouns()const;
        bool isOnlyVerbs()const;
        bool isOnlySynonyms()const;
        bool isOnlyAntonyms()const;
	Geopt(int argc, char const *argv[]);
	std::string get_next();
    //destructer not needed
};

Geopt::Geopt(int argc, char const *argv[])
{       this->maxNumberOfResults=10;
        indexOfFirstWord=0;
        onlyAntonyms=false;
        onlyNouns=false;
        onlySynonyms=false;
        onlyVerbs=false;
	optind = readFlags(argc,argv);
	for (int i = optind; i < argc; ++i)
	{
		std::string tmp(argv[i], strlen(argv[i]));
		options.push(tmp);
	}
}

std::string Geopt::get_next()
{       
	std::string tmp = options.front();
	options.pop();
	return tmp;
}
bool Geopt::isOnlyAntonyms() const
{
    return this->onlyAntonyms;
}
bool Geopt::isOnlyNouns()const
{
    return this->onlyNouns;
}
bool Geopt::isOnlySynonyms()const
{
    return this->onlySynonyms;
}
bool Geopt::isOnlyVerbs()const
{
    return this->onlyVerbs;
}

int Geopt::readFlags(int argc, const char* argv[])
{   
    int i;
    int temp;
    for (i=1;i<argc;i++){
        std::stringstream convert(argv[i]); 
        if(!(strcmp(argv[i],"-n")&&(strcmp(argv[i],"-N")))){
            this->onlyNouns=true;
        }
        else if(!(strcmp(argv[i],"-v")&&(strcmp(argv[i],"-V")))){
            this->onlyVerbs=true;
        }
        else if(!(strcmp(argv[i],"-a")&&(strcmp(argv[i],"-A")))){
            this->onlyAntonyms=true;
        }
        else if(!(strcmp(argv[i],"-s")&&(strcmp(argv[i],"-S")))){
            this->onlySynonyms=true;
        }
        else if(!(strcmp(argv[i],"-h")&&(strcmp(argv[i],"-H")))){
            std::cout <<HELP_MSG;
            exit(0);
        }
        else if(argv[i][0]=='-'){
            std::cout<<"\""<<argv[i]<<"\" "<<WRONG_FLAG_MSSG<<std::endl;
            std::cout<<HELP_MSG;
            exit(0);
        }
        else if((convert>>temp)){
            maxNumberOfResults=temp;
        }
        else {
            
        
            break;
        }
        
    }
    this->indexOfFirstWord=i;
    return i;

}

int Geopt::getIndexOfFirstWord()const
{   
    return this->indexOfFirstWord;

}
unsigned int  Geopt::getMaxNumberOfResults() const
{   
    return this->maxNumberOfResults;

}
const std::string Geopt::WRONG_FLAG_MSSG="is an unknown flag.";
const std::string Geopt::HELP_MSG="x-thesaurus 1.0 \n"
            "A terminal client to lookup synonyms of an english word. x-thesaurus uses the Big" "Huge Thesaurus api to serve the synonyms to it's users."
            "\nOptions-style:\n"
            "[flag/s] [Integer][word/s]\n"
            "Flags list:\n"
            "\t -h help.\n"
            "\t -v Show only Verbs.\n"
            "\t -n Show only Nouns.\n"
            "\t -a Show only Antonyms.\n"
            "\t -s Show only Synonyms.\n"
            "\t Integer Maximum number of results\n";
