#include "PmergeMe.hpp"

#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>
#include <cerrno>
#include <climits>
#include <ctime>

static int parseInt(const char *str)
{
	char *end;
	long value;

	errno = 0;
	value = std::strtol(str, &end, 10);

	if (*str == '\0' || *end != '\0')
		throw std::runtime_error("Error");

	if (errno == ERANGE || value < 0 || value > INT_MAX)
		throw std::runtime_error("Error");

	return static_cast<int>(value);
}

/*static bool contains(const std::vector<int> &v, int value)
{
	for (size_t i = 0; i < v.size(); ++i)
	{
		if (v[i] == value)
			return true;
	}

	return false;
}*/

static void printVector(const std::vector<int> &v)
{
	for (size_t i = 0; i < v.size(); ++i)
	{
		if (i != 0)
			std::cout << " ";

		std::cout << v[i];
	}

	std::cout << std::endl;
}

/*static void printDeque(const std::deque<int> &d)
{
	for (size_t i = 0; i < d.size(); ++i)
	{
		if (i != 0)
			std::cout << " ";

		std::cout << d[i];
	}

	std::cout << std::endl;
}*/

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}

	try
	{
		std::vector<int> vectorInput;

		for (int i = 1; i < argc; ++i)
		{
			int value = parseInt(argv[i]);
			vectorInput.push_back(value);
		}

		std::deque<int> dequeInput(vectorInput.begin(),
								   vectorInput.end());

		std::cout << "Before: ";
		printVector(vectorInput);

		/*
		 * Copy the input because we want to measure
		 * each container independently.
		 */
		std::vector<int> vectorSorted = vectorInput;
		std::deque<int> dequeSorted = dequeInput;

		clock_t vectorStart = clock();

		PmergeMe::sortVector(vectorSorted);

		clock_t vectorEnd = clock();

		clock_t dequeStart = clock();

		PmergeMe::sortDeque(dequeSorted);

		clock_t dequeEnd = clock();

		double vectorTime =
			static_cast<double>(vectorEnd - vectorStart)
			/ CLOCKS_PER_SEC
			* 1000000.0;

		double dequeTime =
			static_cast<double>(dequeEnd - dequeStart)
			/ CLOCKS_PER_SEC
			* 1000000.0;

		std::cout << "After:  ";
		printVector(vectorSorted);

		std::cout << "Time to process a range of "
				  << vectorInput.size()
				  << " elements with std::vector : "
				  << vectorTime
				  << " us"
				  << std::endl;

		std::cout << "Time to process a range of "
				  << dequeInput.size()
				  << " elements with std::deque  : "
				  << dequeTime
				  << " us"
				  << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}
