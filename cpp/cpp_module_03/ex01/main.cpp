#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ScavTrap sc("kkk");
	sc.guardGate();
	sc.beRepaired(1);
	ScavTrap sc2(sc);
	sc2.beRepaired(1);
}