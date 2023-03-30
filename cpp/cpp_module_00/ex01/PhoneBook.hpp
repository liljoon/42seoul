#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"
#include <iostream>
#include <iomanip>

class PhoneBook
{
private:
	int top;
	Contact data[8];

public:
	PhoneBook();
	void loop_start();
	void add_process();
};

#endif
