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
	int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
		days_in_month[2]++;

	if (month == 0 || day == 0)
		return false;
	if (month > 12)
		return false;
	if (days_in_month[month] < day)
		return false;

	return true;
}

double BitcoinExchange::findPrice(const std::string &date)
{
	std::map<std::string, double>::iterator it = db.lower_bound(date);

	if (it->first == date)
		return it->second;
	else
	{
		if (it == db.begin())
			throw std::exception();
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
		const double rate = findPrice(date);

		std::cout << date << " => " << value << " = " << value * rate << std::endl;
	}
	catch (const std::exception &err)
	{
		std::cout << "Error: No price" << std::endl;
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
