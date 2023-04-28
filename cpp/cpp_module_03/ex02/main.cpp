#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	FragTrap ft("aname");
	FragTrap ft2("bname");

	ft.attack("bname");
	ft2.takeDamage(30);
	ft.highFivesGuys();

	ft2.takeDamage(70);
	ft2.attack("aname");
	ft2.beRepaired(100);
	ft2.highFivesGuys();
}