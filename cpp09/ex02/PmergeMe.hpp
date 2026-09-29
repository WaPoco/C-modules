#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>

class PmergeMe
{
private:
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();

	static std::vector<size_t> generateJacobsthal(size_t n);

	static void binaryInsert(std::vector<int> &main,
							 int value,
							 size_t end);

	static void binaryInsert(std::deque<int> &main,
							 int value,
							 size_t end);

	static void sortVectorRecursive(std::vector<int> &v);
	static void sortDequeRecursive(std::deque<int> &d);

public:
	static void sortVector(std::vector<int> &v);
	static void sortDeque(std::deque<int> &d);
};

#endif
