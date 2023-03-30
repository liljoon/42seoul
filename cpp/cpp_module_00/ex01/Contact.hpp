#ifndef CONTACT_H
#define CONTACT_H

#include <string>

class Contact
{
private:
	int idx;
	std::string first_name;
	std::string last_name;
	std::string nick_name;
	std::string phone_number;
	std::string darkest_secret;

public:
	Contact();
	Contact(int idx, std::string fn, std::string ln, std::string nn, std::string pn, std::string ds);
	int get_idx();
	std::string get_first_name();
	std::string get_last_name();
	std::string get_nick_name();
	std::string get_phone_number();
	std::string get_darkest_secret();
};

#endif
