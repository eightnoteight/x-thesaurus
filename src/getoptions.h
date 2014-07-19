// Geopt is nice for purposes like this where the 
// args are just the repitions of the program
class Geopt
{
private:
	std::queue<std::string> options;
	int optind;
public:
	Geopt(int argc, char const *argv[]);
	std::string get_next();
    //destructer not needed
};
Geopt::Geopt(int argc, char const *argv[])
{
	optind = 1;
	for (int i = 1; i < argc; ++i)
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
