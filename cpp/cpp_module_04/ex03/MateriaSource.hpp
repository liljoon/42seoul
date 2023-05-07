#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
private:
	static const int slotSize = 4;
	AMateria *pslotArr[slotSize];
	int findEmpty();

public:
	MateriaSource();
	MateriaSource(const MateriaSource &other);
	MateriaSource &operator=(const MateriaSource &other);
	~MateriaSource();

	void learnMateria(AMateria *pmateria);
	AMateria *createMateria(std::string const &type);
};

#endif
