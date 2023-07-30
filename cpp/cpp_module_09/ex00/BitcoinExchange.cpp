#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	return *this;
}

void BitcoinExchange::readDB()
{
	std::ifstream fin;
	std::string date;
	double price;

	try
	{
		fin.open(DB_NAME);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		std::exit(1);
	}
	std::getline(fin, date);
	while (!fin.eof())
	{
		std::getline(fin, date, ',');
		fin >> price;
		db.push_back(std::make_pair<std::string, double>(date, price));
	}
}

void BitcoinExchange::run(const std::string &input_file)
{
	readDB();
}
