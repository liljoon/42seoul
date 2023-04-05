#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
private:
	Weapon *wp;
	std::string name;

public:
	HumanA(std::string name, Weapon &wp);
	~HumanA();

	void attack();
};

#endif
