#include "Contact.hpp"

Contact::Contact()
{
}

Contact::Contact(int idx, std::string fn, std::string ln, std::string nn, std::string pn, std::string ds)
	: idx(idx), first_name(fn), last_name(ln), nick_name(nn), phone_number(pn), darkest_secret(ds)
{
}

int Contact::get_idx()
{
	return this->idx;
}

std::string Contact::get_first_name()
{
	return this->first_name;
}

std::string Contact::get_last_name()
{
	return this->last_name;
}

std::string Contact::get_nick_name()
{
	return this->nick_name;
}

std::string Contact::get_phone_number()
{
	return this->phone_number;
}

std::string Contact::get_darkest_secret()
{
	return this->darkest_secret;
}
