#include "ClapTrap.hpp"

int main()
{
	ClapTrap A("aname");
	ClapTrap B("bname");

	A.attack("bname");
	B.takeDamage(0);

	B.takeDamage(5);
	B.beRepaired(15);
	B.takeDamage(25);

	B.beRepaired(10); // hitpoints : 0
	B.attack("aname");

	for (int i = 0; i < 9; i++)
		A.attack("bname");

	A.beRepaired(10);
	A.attack("bname");
}