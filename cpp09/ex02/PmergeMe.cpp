#include "PmergeMe.hpp"

#include <algorithm>

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	(void)other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	(void)other;
	return *this;
}

PmergeMe::~PmergeMe()
{
}

/*
 * Jacobsthal numbers:
 *
 * J(0) = 0
 * J(1) = 1
 * J(n) = J(n - 1) + 2 * J(n - 2)
 *
 * Ford-Johnson uses these numbers to determine
 * the order in which the smaller elements are inserted.
 */
std::vector<size_t> PmergeMe::generateJacobsthal(size_t n)
{
	std::vector<size_t> result;

	if (n == 0)
		return result;

	size_t j0 = 0;
	size_t j1 = 1;

	while (j1 < n)
	{
		result.push_back(j1);

		size_t next = j1 + 2 * j0;
		j0 = j1;
		j1 = next;
	}

	return result;
}

void PmergeMe::binaryInsert(std::vector<int> &main,
							int value,
							size_t end)
{
	size_t left = 0;
	size_t right = end;

	while (left < right)
	{
		size_t middle = left + (right - left) / 2;

		if (main[middle] < value)
			left = middle + 1;
		else
			right = middle;
	}

	main.insert(main.begin() + left, value);
}

void PmergeMe::binaryInsert(std::deque<int> &main,
							int value,
							size_t end)
{
	size_t left = 0;
	size_t right = end;

	while (left < right)
	{
		size_t middle = left + (right - left) / 2;

		if (main[middle] < value)
			left = middle + 1;
		else
			right = middle;
	}

	main.insert(main.begin() + left, value);
}

/*
 * Ford-Johnson / merge-insertion sort for vector.
 */
void PmergeMe::sortVectorRecursive(std::vector<int> &v)
{
	if (v.size() <= 1)
		return;

	/*
	 * Pair the elements.
	 *
	 * For every pair:
	 *
	 * smaller -> pending
	 * larger  -> main chain
	 *
	 * Example:
	 *
	 * 8 3 | 7 5 | 9 2
	 *
	 * pairs become:
	 *
	 * (3,8), (5,7), (2,9)
	 *
	 * main:    8 7 9
	 * pending: 3 5 2
	 */
	std::vector<int> main;
	std::vector<int> pending;

	for (size_t i = 0; i + 1 < v.size(); i += 2)
	{
		if (v[i] < v[i + 1])
		{
			pending.push_back(v[i]);
			main.push_back(v[i + 1]);
		}
		else
		{
			pending.push_back(v[i + 1]);
			main.push_back(v[i]);
		}
	}

	/*
	 * If the number of elements is odd, keep the last
	 * element aside. It will be inserted at the end.
	 */
	bool hasStraggler = (v.size() % 2 != 0);
	int straggler = 0;

	if (hasStraggler)
		straggler = v.back();

	/*
	 * Recursively sort the larger elements.
	 */
	sortVectorRecursive(main);

	/*
	 * Insert the pending elements.
	 *
	 * The first pending element can immediately be inserted.
	 * The remaining elements are inserted according to
	 * Jacobsthal ordering.
	 */
	if (!pending.empty())
	{
		binaryInsert(main, pending[0], main.size());

		std::vector<size_t> jacobsthal =
			generateJacobsthal(pending.size());

		std::vector<bool> inserted(pending.size(), false);
		inserted[0] = true;

		for (size_t j = 0; j < jacobsthal.size(); ++j)
		{
			size_t current = jacobsthal[j];

			if (current >= pending.size())
				current = pending.size() - 1;

			if (current == 0)
				continue;

			/*
			 * Insert backwards from the current Jacobsthal
			 * position until the previous boundary.
			 */
			size_t previous = 0;

			if (j > 0)
				previous = jacobsthal[j - 1];

			size_t i = current;

			while (i > previous)
			{
				if (i < pending.size() && !inserted[i])
				{
					binaryInsert(main, pending[i], main.size());
					inserted[i] = true;
				}
				--i;
			}
		}

		/*
		 * Safety pass for any elements that weren't inserted.
		 */
		for (size_t i = 0; i < pending.size(); ++i)
		{
			if (!inserted[i])
			{
				binaryInsert(main, pending[i], main.size());
				inserted[i] = true;
			}
		}
	}

	/*
	 * Insert the odd element.
	 */
	if (hasStraggler)
		binaryInsert(main, straggler, main.size());

	v = main;
}

/*
 * Ford-Johnson / merge-insertion sort for deque.
 */
void PmergeMe::sortDequeRecursive(std::deque<int> &d)
{
	if (d.size() <= 1)
		return;

	std::deque<int> main;
	std::deque<int> pending;

	for (size_t i = 0; i + 1 < d.size(); i += 2)
	{
		if (d[i] < d[i + 1])
		{
			pending.push_back(d[i]);
			main.push_back(d[i + 1]);
		}
		else
		{
			pending.push_back(d[i + 1]);
			main.push_back(d[i]);
		}
	}

	bool hasStraggler = (d.size() % 2 != 0);
	int straggler = 0;

	if (hasStraggler)
		straggler = d.back();

	sortDequeRecursive(main);

	if (!pending.empty())
	{
		binaryInsert(main, pending[0], main.size());

		std::vector<size_t> jacobsthal =
			generateJacobsthal(pending.size());

		std::vector<bool> inserted(pending.size(), false);
		inserted[0] = true;

		for (size_t j = 0; j < jacobsthal.size(); ++j)
		{
			size_t current = jacobsthal[j];

			if (current >= pending.size())
				current = pending.size() - 1;

			if (current == 0)
				continue;

			size_t previous = 0;

			if (j > 0)
				previous = jacobsthal[j - 1];

			size_t i = current;

			while (i > previous)
			{
				if (i < pending.size() && !inserted[i])
				{
					binaryInsert(main, pending[i], main.size());
					inserted[i] = true;
				}

				--i;
			}
		}

		for (size_t i = 0; i < pending.size(); ++i)
		{
			if (!inserted[i])
			{
				binaryInsert(main, pending[i], main.size());
				inserted[i] = true;
			}
		}
	}

	if (hasStraggler)
		binaryInsert(main, straggler, main.size());

	d = main;
}

void PmergeMe::sortVector(std::vector<int> &v)
{
	sortVectorRecursive(v);
}

void PmergeMe::sortDeque(std::deque<int> &d)
{
	sortDequeRecursive(d);
}
