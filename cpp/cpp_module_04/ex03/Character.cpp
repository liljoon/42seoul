#include "Character.hpp"

Character::Character()
{
	for (int i = 0; i < slotSize; i++)
		pslotArr[i] = NULL;
}

Character::Character(std::string name)
{
	for (int i = 0; i < slotSize; i++)
		pslotArr[i] = NULL;
	this->name = name;
}

Character::Character(const Character &other)
{
	for (int i = 0; i < slotSize; i++)
		pslotArr[i] = NULL;
	for (int i = 0; i < slotSize; i++)
		pslotArr[i] = other.pslotArr[i]->clone();
	name = other.name;
}

Character &Character::operator=(const Character &other)
{
	name = other.name;
	for (int i = 0; i < slotSize; i++)
	{
		if (pslotArr[i] != NULL)
			delete pslotArr[i];
		pslotArr[i] = other.pslotArr[i]->clone();
	}

	return *this;
}

Character::~Character()
{
	for (int i = 0; i < slotSize; i++)
	{
		if (pslotArr[i] != NULL)
			delete pslotArr[i];
	}
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
	if (pslotArr[idx] == NULL || idx < 0 || idx >= slotSize)
		return;
	pslotArr[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	if (pslotArr[idx] == NULL || idx < 0 || idx >= slotSize)
		return;
	pslotArr[idx]->use(target);
}
