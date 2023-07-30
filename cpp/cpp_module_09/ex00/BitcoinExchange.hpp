#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <utility>

#define DB_NAME "data.csv"

class BitcoinExchange
{
private:
	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);

	static std::vector<std::pair<std::string, double>> db;
	static void readDB();

public:

	static void run(const std::string &input_file);
};


#endif
