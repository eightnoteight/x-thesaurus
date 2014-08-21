#include <cstring>
#include <cstdlib>
#include <string>
#include "http-get.c"
class GET
{
private:
	std::string randstr(int len);
	std::string file(std::string url);//returns filename
public:
	int ok;
	long long int status;
	std::string msg;
	std::string data;
	std::string filename;
	GET(std::string url);

	/* data */
};
GET::GET(std::string url="http://www.google.com")
{
	http_get_response_t *res=http_get(url.c_str());
	ok = res->ok;
	status = res->status;
	data.assign(res->data);
	msg.assign(res->msg, res->msg + strlen(res->msg));
	filename = file(url);
	http_get_free(res);
}
std::string GET::randstr(int len)
{
	const char alphanum[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	std::string str;
	srand(time(NULL));
	for (int i = 0; i < len; ++i)
	{
		str.push_back(alphanum[rand() % strlen(alphanum)]);
	}
	return str;
}
std::string GET::file(std::string url)
{
	std::string filname = randstr(15);
	if (http_get_file(url.c_str(), ("/tmp/" + filname).c_str()) == 0)
		return "/tmp/" + filname;
	return "null";
}
