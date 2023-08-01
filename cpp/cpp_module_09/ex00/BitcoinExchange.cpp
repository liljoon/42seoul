#include "BitcoinExchange.hpp"

std::map<std::string, double> BitcoinExchange::db;

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

	fin.open(DB_NAME);
	if(fin.fail())
	{
		std::cout << "Error: could not open file." << std::endl;
		std::exit(1);
	}
	std::getline(fin, date);
	while (!fin.eof())
	{
		std::getline(fin, date, ',');
		std::getline(fin, price);
		if (fin.eof())
			break;
		db.insert(std::make_pair(date, std::strtod(price.c_str(), NULL)));
	}
}

bool check_date(const std::string &date)
{
	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	if ((month % 2 == 1))
	{
		if (month <= 7)
		{
			if (day > 31)
				return false;
			else
			{
				if (day > 30)
					return false;
			}
		}
	}
	else
	{
		if (month <= 6)
		{
			if (month == 2)
			{
				if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
				{
					if (day > 30)
						return false;
				}
				else if (day > 28)
					return false;
			}
			if (day > 30)
				return false;
		}
		else
		{
			if (day > 31)
				return false;
		}
	}
	return true;
}

double BitcoinExchange::findPrice(const std::string &date)
{
	std::map<std::string, double>::iterator it = db.lower_bound(date);

	if (it == db.find(date))
		return db[date];
	else
	{
		if (it == db.begin())
			throw "No price";
		else
		{
			it--;
			return it->second;
		}
	}
}

void BitcoinExchange::exec_line(const std::string &line)
{
	std::string date;
	double value;

	date = line.substr(0, 10);
	if (check_date(date) == false)
	{
		std::cout << "Error: bad input => " << date << std::endl;
		return ;
	}
	value = std::strtod(line.substr(13, std::string::npos).c_str(), NULL);
	if (value < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return ;
	}
	if (value > 1000)
	{
		std::cout << "Error: too large a number." << std::endl;
		return;
	}

	try
	{
		std::cout<< date << " => " << value <<  " = " << value * findPrice(date) << std::endl;
	}
	catch(const std::string &err)
	{
		std::cout << err << std::endl;
	}
}

void BitcoinExchange::readInput(const std::string &input_file)
{
	std::ifstream fin;
	std::string line;

	fin.open(input_file.c_str());
	if (fin.fail())
	{
		std::cout << "Error: could not open file." << std::endl;
		std::exit(1);
	}
	std::getline(fin, line);

	while (!fin.eof())
	{
		std::getline(fin, line);
		//check
		if (fin.eof() || line.size() == 0)
			break;
		exec_line(line);
	}

}

void BitcoinExchange::run(const std::string &input_file)
{
	readDB();
	readInput(input_file);
}
