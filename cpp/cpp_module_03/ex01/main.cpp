#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ScavTrap sc("aname");
	ScavTrap sc2("bname");

	sc.attack("bname");
	sc2.takeDamage(20);
	sc.guardGate();
	sc.beRepaired(1);
	sc2.takeDamage(80);
	sc2.attack("aname");
	sc2.beRepaired(100);
}