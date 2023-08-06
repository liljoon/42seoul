#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <utility>
#include <map>
#include <stdexcept>

#define DB_NAME "data.csv"

class BitcoinExchange
{
private:
	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);

	static std::map<std::string, double> db;
	static void readDB();
	static void readInput(const std::string &input_file);
	static void exec_line(const std::string &line);
	static double findPrice(const std::string &date);

public :

		static void run(const std::string &input_file);
};


#endif
