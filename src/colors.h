//color headers
struct fore {
	std::string black;
	std::string red;
	std::string green;
	std::string yellow;
	std::string blue;
	std::string magenta;
	std::string cyan;
	std::string white;
    fore();
} fg;
struct back {
	std::string black;
	std::string red;
	std::string green;
	std::string yellow;
	std::string blue;
	std::string magenta;
	std::string cyan;
	std::string white;
    back();
} bg;
struct style {
	std::string bold;
	std::string blink;
	std::string reset;
	std::string rvid;
    style();
} st;

fore::fore() {

	black	= "\033[30m";
	red 	= "\033[31m";
	green	= "\033[32m";
	yellow	= "\033[33m";
	blue 	= "\033[34m";
	magenta	= "\033[35m";
	cyan	= "\033[36m";
	white	= "\033[37m";
	
}
back::back() {
	black	= "\033[40m";
	red 	= "\033[41m";
	green 	= "\033[42m";
	yellow	= "\033[43m";
	blue 	= "\033[44m";
	magenta	= "\033[45m";
	cyan	= "\033[46m";
	white	= "\033[47m";
	
}
style::style() {

	bold	= "\033[1m";
	blink	= "\033[5m";
	reset	= "\033[0m";
	rvid	= "\033[7m";
}
