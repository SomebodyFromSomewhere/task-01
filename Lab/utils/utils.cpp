#include <stdio.h>
#include <iostream>
#include <time.h>
#include <string>

void executionTime(clock_t start, std::string function_name = "NULL") {
	clock_t end = clock();
	double seconds = (double)(end - double(start)) / CLOCKS_PER_SEC;
	if (function_name == "NULL")
	{
		printf("[TIME]%f SECONDS ELAPSED\n", seconds);
	}
	else {
		std::cerr << "[TIME][" << function_name << "]" << seconds << " SECONDS ELAPSED" << std::endl;
	}
}