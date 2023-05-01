#include "Character.hpp"

Character::Character()
{
	for (int i = 0; i < slotSize; i++)
		pslotArr[i] = NULL;
}

Character::Character(std::string name)
{
	this->name = name;
}

Character::~Character()
{
}

int Character::findEmpty()
{
	for (int i = 0; i < slotSize; i++)
	{
		if (pslotArr[i] == NULL)
			return i;
	}
	return -1;
}

std::string const &Character::getName() const
{
	return this->name;
}

void Character::equip(AMateria *m)
{
	int idx = findEmpty();
	if (idx == -1)
		return;
	pslotArr[idx] = m;
}

void Character::unequip(int idx)
{
	pslotArr[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	if (pslotArr[idx] == NULL)
		return;
	pslotArr[idx]->use(target);
}
