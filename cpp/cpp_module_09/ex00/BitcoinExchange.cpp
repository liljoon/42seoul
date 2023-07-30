#include "BitcoinExchange.hpp"

std::vector<std::pair<std::string, double> > BitcoinExchange::db;

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	(void)other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	(void)other;

	return *this;
}

void BitcoinExchange::readDB()
{
	std::ifstream fin;
	std::string date;
	std::string price;

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
		std::getline(fin, price);
		if (fin.eof())
			break;
		db.push_back(std::make_pair(date, std::strtod(price.c_str(), NULL)));
	}
}

void BitcoinExchange::run(const std::string &input_file)
{
	readDB();
	(void)input_file;

	for (size_t i = 0; i < db.size(); i++)
	{
		std::cout<<db[i].first<< ","<< db[i].second<<std::endl;
	}

}
