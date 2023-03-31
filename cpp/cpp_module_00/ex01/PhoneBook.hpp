#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>

class PhoneBook
{
private:
	int top;
	Contact data[8];

public:
	PhoneBook();
	void loop_start();
	void add_process();
	void search_process();
	int find_data(int idx);
	void print_contact(int data_idx);
};

#endif
