#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < slotSize; i++)
		pslotArr[i] = NULL;
}

MateriaSource::~MateriaSource()
{
}

int MateriaSource::findEmpty()
{
	for (int i = 0; i < slotSize; i++)
	{
		if (pslotArr[i] == NULL)
			return i;
	}
	return -1;
}

void MateriaSource::learnMateria(AMateria *pmateria)
{
	int idx = findEmpty();

	if (idx == -1)
		return;
	pslotArr[idx] = pmateria;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < slotSize; i++)
	{
		if (pslotArr[i] != NULL && pslotArr[i]->getType() == type)
			return pslotArr[i]->clone();
	}
	return 0;
}
