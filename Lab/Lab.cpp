#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm> //sort function
#include <time.h>
#include "utils\utils.h"

void readNumberSellersAndBuyers(std::ifstream& file, int& sellers, int& buyers) {
	for (int i = 0; i < 2; i++)
	{
		(i < 1) ? file >> sellers : file >> buyers;
	}
}
void readToArray(std::ifstream& file, int n, std::vector <int>& output_array) {
	clock_t start = clock();
	int number;
	for (int i = 0; i < n; i++)
	{
		file >> number;
		output_array.push_back(number);
	}
	executionTime(start, "READ_TO_ARRAY");
}



int readFromFile(std::string file_name, std::vector <int>& sellers_array, std::vector <int>& buyers_array) {
	clock_t start = clock();
	std::ifstream file(file_name);
	if (!file)
	{
		std::cerr << "[FILE]CANNOT OPEN FILE" << std::endl;
		return -1;
	}
	std::cerr << "[FILE]SUCCESSFULY OPENED FILE" << std::endl;
	int sellers, buyers;
	for (; !file.eof();) {
		readNumberSellersAndBuyers(file, sellers, buyers);
		readToArray(file, sellers, sellers_array);
		std::cerr << "[FILE]READED SELLERS" << std::endl;
		readToArray(file, buyers, buyers_array);
		std::cerr << "[FILE]READED BUYERS" << std::endl;
	}
	executionTime(start, "READ_FROM_FILE");
	return 0;
}

void sortAndClearTheExcess(std::vector <int>& sellers, std::vector <int>& buyers) {
	clock_t start = clock();
	std::sort(sellers.begin(), sellers.end());
	std::cerr << "[ALGORITHM]SORTED SELLERS" << std::endl;
	std::sort(buyers.begin(), buyers.end());
	std::cerr << "[ALGORITHM]SORTED BUYERS" << std::endl;

	executionTime(start, "SORTING");

	int min_sell_price, max_buy_price;
	min_sell_price = sellers[0];
	max_buy_price = buyers[(buyers.size() - 1)];
	for (int i = sellers.size() - 1; i > 0; i--)
	{
		if (sellers[i] > max_buy_price) {
			sellers.pop_back();
		}
		else {
			break;
		}
	}

	std::cerr << "[ALGORITHM]REMOVED EXCESS SELLERS" << std::endl;

	for (int i = 0; i < buyers.size() - 1;)
	{
		if (buyers[i] < min_sell_price) {
			buyers.erase(buyers.begin());
		}
		else {
			i++;
			break;
		}
	}

	std::cerr << "[ALGORITHM]REMOVED EXCESS BUYERS" << std::endl;

	executionTime(start, "ALGORITHM");
}

void calculatePriceAndProceed(std::vector <int>& sellers, std::vector <int>& buyers, int& max_proceeds, int& max_proceeds_price) {
	clock_t start = clock();

	std::vector <int> united;
	std::vector <std::vector <int>> results;
	united.insert(united.end(), sellers.begin(), sellers.end());
	united.insert(united.end(), buyers.begin(), buyers.end());
	sort(united.begin(), united.end());
	auto last = std::unique(united.begin(), united.end());
	united.erase(last, united.end());
	int n, m;
	
	std::cerr << "[CALCULATE]STARTING" << std::endl;

	for (int i = 0; i < united.size(); i++)
	{
		n = 0, m = 0;
		for (int j = 0; j < sellers.size(); j++)
		{
			if (sellers[j] > united[i]) {
				break;
			}
			n++;
		}
		for (int k = buyers.size() - 1; k > 0; k--)
		{
			if (buyers[k] < united[i]) {
				break;
			}
			m++;
		}
		auto record = { united[i], std::min(n, m) * united[i] };
		results.push_back(record);
	}

	for (int i = 0; i < results.size(); i++) {
		if (results[i][1] > max_proceeds)
		{
			max_proceeds_price = results[i][0];
			max_proceeds = results[i][1];
		}
	}


	executionTime(start, "CALCULATING");
}

void writeToFile(std::string file_name, int max_proceeds_price, int max_proceeds) {
	clock_t start = clock();
	std::ofstream output_file(file_name);
	output_file << max_proceeds_price << ' ' << max_proceeds << std::endl;
	output_file.close();
	executionTime(start, "WRITE");
}

int main()
{
	std::clock_t main_start = clock();
	int max_proceeds, max_proceeds_price;
    std::vector <int> sellers__prices, buyers_prices;
    readFromFile("INPUT.txt", sellers__prices, buyers_prices);
	std::cerr << "[FILE]ENDED READING FILE" << std::endl;
	sortAndClearTheExcess(sellers__prices, buyers_prices);
	calculatePriceAndProceed(sellers__prices, buyers_prices, max_proceeds, max_proceeds_price);
	writeToFile("OUTPUT.txt", max_proceeds_price, max_proceeds);

	executionTime(main_start, "MAIN");
}