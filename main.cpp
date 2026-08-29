#include "pch.h"

template<typename Container>
static void print(const Container& container)
{
	std::cout << "{";

	for (auto it = container.begin(); it != container.end(); ++it) // Example of iterator
	{
		std::cout << '\"' << *it << '\"';

		if (std::next(it) != container.end())
		{
			std::cout << ", ";
		}
	}
	std::cout << "}";
}

int main()
{
	// Visit https://www.w3schools.com/cpp/cpp_data_structures.asp for the full details.
	// ^^ Include iterators and algorithm.

	// Mostly going to state the definition and the differences between data structures.

	/* -------------- Vectors ---------------- */

	// A vector in C++ is similar to an array.
	// The difference between an array and a vector, is that the size of an array cannot be modified 
	// (you cannot add or remove elements from an array). 
	// A vector however, can grow or shrink in size as needed.

	// Common functions: .front(), .back(), .at(), .push_back(), .pop_back(), .size(), .empty(), .reserve().

	std::cout << "-------------- Vectors ----------------" << "\n\n";

	{
		std::vector<std::string> animals = { "Sheep", "Cow", "Pig" };

		std::cout << "Animals: ";
		print(animals);

		std::cout << '\n';
		std::cout << "Size: " << animals.size() << "\n\n";

		// Other functions
		std::cout << "animals.front() = " << animals.front() << '\n';
		std::cout << "animals.at(1) = " << animals.at(1) << '\n';
		std::cout << "animals.back() = " << animals.back() << '\n';
		std::cout << "animals.empty() = " << animals.empty() << '\n';

		// After pushing an element.
		std::cout << '\n';

		animals.push_back("Cat");

		std::cout << "Animals: ";
		print(animals);

		std::cout << " (After pushing)" << '\n';
		std::cout << "Size: " << animals.size() << '\n';

		// After popping an element.
		std::cout << '\n';

		animals.pop_back();
		animals.pop_back();

		std::cout << "Animals: ";
		print(animals);

		std::cout << " (After popping 2 times)" << '\n';
		std::cout << "Size: " << animals.size() << '\n';
	}
	std::cout << '\n';

	/* -------------- Lists ---------------- */

	// A list is similar to a vector in that it can store multiple elements of the same type and dynamically grow in size.
	// However, two major differences between lists and vectors are :

	// 1. You can add and remove elements from both the beginning and at the end of a list, 
	// while vectors are generally optimized for adding and removing at the end.

	// 2. Unlike vectors, a list does not support random access, meaning you cannot directly jump to a specific index, 
	// or access elements by index numbers.

	// List also has: front(), back(). As such, I won't show them in the code below.

	// Other common functions: .push_back(), .push_front(), .pop_back(), .pop_front(), .size(), .empty(), .clear().

	std::cout << "--------------- Lists -----------------" << "\n\n";

	{
		std::list<std::string> animals = { "Sheep", "Cow", "Pig" };

		std::cout << "Animals: ";
		print(animals);

		std::cout << '\n';

		// After popping beginning and back.
		animals.pop_front();
		animals.pop_back();

		std::cout << "Animals: ";
		print(animals);

		std::cout << " (After popping)" << '\n';

		// After pushing beginning and back.
		animals.push_front("Cat");
		animals.push_front("Dog");

		std::cout << "Animals: ";
		print(animals);

		std::cout << " (After pushing)" << '\n';
	}
	std::cout << '\n';

	/* -------------- Stacks ---------------- */

	// My personal favourite data structure.

	// A stack stores multiple elements in a specific order, called LIFO.
	// LIFO stands for Last in, First Out. To vizualise LIFO, think of a pile of pancakes, 
	// where pancakes are both added and removed from the top. So when removing a pancake, 
	// it will always be the last one you added. 
	// This way of organizing elements is called LIFO in computer science and programming.

	// Unlike vectors, elements in the stack are not accessed by index numbers. 
	// Since elements are added and removed from the top, you can only access the element at the top of the stack.
	// This also means you can't loop it using iterators. Howeverm you can loop through a stack using .empty(), .top() amd .pop()

	// Common functions: .top(), .size(), .empty(), push(), pop(), emplace().

	std::cout << "--------------- Stacks -----------------" << "\n\n";

	{
		/* Example 1: Number and Operator stacks */
		std::stack<int> numberStack;
		std::stack<char> operatorStack;

		auto isoperator = [](char c)
			{
				return c == '+' || c == '-' || c == '*' || c == '/';
			};

		auto parseAndPushNumber = [&](const std::string& expression, size_t& index)
			{
				int number = 0;

				while (index < expression.size() && isdigit(expression[index]))
				{
					number = (expression[index] - '0') + number * 10;
					index++;
				}
				numberStack.push(number);
			};

		std::string expression = "1 + 32 - 2 * 5";
		std::cout << "string expression: " << '\"' << expression << '\"' << '\n';

		for (size_t index = 0; index < expression.size(); index++)
		{
			if (isdigit(expression[index]))
			{
				parseAndPushNumber(expression, index);
			}
			else if (isoperator(expression[index]))
			{
				operatorStack.push(expression[index]);
			}
		}

		std::cout << "Number Stack: ";
		while (!numberStack.empty())
		{
			std::cout << numberStack.top() << ' ';
			numberStack.pop();
		}
		std::cout << '\n';

		std::cout << "Operator Stack: ";
		while (!operatorStack.empty())
		{
			std::cout << operatorStack.top() << ' ';
			operatorStack.pop();
		}
		std::cout << "\n\n";

		/* Example 2: Backtracking */
		std::stack<std::string> actions;

		actions.push("Cute Girl Pinterest");
		actions.push("Wikipedia");

		std::cout << "Another Example:" << '\n';
		std::cout << "When you navigate back to the previous page..." << "\n\n";

		std::cout << "Current page: " << actions.top() << '\n';

		std::cout << "*Goes back to previous page*" << '\n';
		actions.pop();

		std::cout << "Current page: " << actions.top() << '\n';
	}
	std::cout << '\n';

	/* -------------- Queue ---------------- */

	//A queue stores multiple elements in a specific order, called FIFO.

	// FIFO stands for First in, First Out. 
	// To visualize FIFO, think of a queue as people standing in line in a supermarket.
	// The first person to stand in line is also the first who can pay and leave the supermarket. 
	// This way of organizing elements is called FIFO in computer science and programming.

	//	Unlike vectors, elements in the queue are not accessed by index numbers.
	// Since queue elements are added at the end and removed from the front, 
	// you can only access and modify an element at the front or the back.
	// You can't use a for-each loop sadly, but you can use a while not empty loop.

	// Common Functions: size(), empty(), front(), back(), push(), pop().

	std::cout << "--------------- Queue -----------------" << "\n\n";

	{
		std::queue<std::string> animals; // You can't assign values on declaration

		std::cout << "You cannot assign values to a queue on declaration." << '\n';
		std::cout << "Is queue empty: " << animals.empty() << "\n\n";

		// After pushing.
		animals.push("Pig");
		animals.push("Sheep");
		animals.push("Cow");

		std::cout << "The queue would now have pig, sheep, cow. With pig being the first." << '\n';
		std::cout << "Size of the queue: " << animals.size() << '\n';
		std::cout << "First animal in queue: " << animals.front() << '\n';
		std::cout << "Last animal in queue: " << animals.back() << "\n\n";

		// After modifying front and back.
		animals.front() = "Pigson";
		animals.back() = "Cowson";

		std::cout << "First animal in queue (After): " << animals.front() << '\n';
		std::cout << "Last animal in queue (After): " << animals.back() << "\n\n";


		std::cout << "It's like queueing up in a restaurant (animal edition):" << '\n';
		while (!animals.empty())
		{
			std::cout << "Current animal: " << animals.front() << '\n';
			animals.pop();
		}

		// There's std::priority_queue which sorts things out in an order like "Set".
	}
	std::cout << '\n';

	/* -------------- Deque ---------------- */

	// A deque (stands for double-ended queue) however, is more flexible, 
	// as elements can be added and removed from both ends (at the front and the back). 
	// You can also access elements by index numbers. But, at() is often preferred as it can throw an exception error.

	// Common Functions: .front(), .back(), .at(), .push_back(), .push_front(), .pop_back, .pop_front(), .size(), .empty().

	std::cout << "--------------- Deque -----------------" << "\n\n";

	{
		std::deque<std::string> enemies;

		// Normal enemies spawn at the back
		enemies.push_back("Zombie");
		enemies.push_back("Skeleton");
		enemies.push_back("Werewolf");

		// Boss gets priority and spawn at the front
		enemies.push_front("Clison The Demon King");

		std::cout << "Enemies: ";
		print(enemies);
		std::cout << "\n\n";

		// Boss gets defeated
		enemies.pop_front();

		std::cout << "You defeated Clison the Demon King! Now spawning remaining enemies (Slime)." << "\n\n";

		// Slimes spawns at the back
		enemies.push_back("Slime");

		std::cout << "Enemies: ";
		print(enemies);
	}
	std::cout << "\n\n";

	/* -------------- Sets ---------------- */

	// A set stores unique elements where they:

	// 1. Are sorted automatically in ascending order. (You also can use greater<int>, greater<string> to change the order).
	// 2. Are unique, meaning equal or duplicate values are ignored.
	// 3. Can be added or removed, but the value of an existing element cannot be changed.
	// 4. Cannot be accessed by index numbers, because the order is based on sorting and not indexing.

	// Common functions: .insert(x), .erase(x), .clear(), .size(), .empty(), .contains().

	std::cout << "---------------- Sets ------------------" << "\n\n";
	{
		std::set<std::string> evidences;

		// Normal Gameplay
		std::cout << "You've collected Note." << '\n';
		evidences.insert("Note");
		std::cout << "You've collected Broken Glass." << "\n\n";
		evidences.insert("Broken Glass");

		std::cout << "Evidences Collected:" << '\n';

		for (const std::string& evidence : evidences)
		{
			std::cout << "- " << evidence << '\n';
		}
		std::cout << '\n';

		// Duplicate Showcase
		std::cout << "You've collected Note." << "\n\n";
		evidences.insert("Note"); // Duplicate

		std::cout << "Evidences Collected:" << '\n';

		for (const std::string& evidence : evidences)
		{
			std::cout << "- " << evidence << '\n';
		}
		std::cout << '\n';

		// Contain Showcase
		std::cout << "You've collected Key." << '\n';
		evidences.insert("Key");

		if (evidences.contains("Key"))
		{
			std::cout << "Door is unlocked" << '\n';
		}
	}

	std::cout << '\n';

	/* -------------- Map ---------------- */

	// A map stores elements in "key/value" pairs.

	// Elements in a map are :

	// 1. Accessible by keys(not index), and each key is unique.
	// 2. Automatically sorted in ascending order by their keys.

	// Common functions: .insert([key, value]), .erase(key), .at(), .size(), .contains().

	std::cout << "---------------- Map ------------------" << "\n\n";

	{
		std::map<std::string, int> inventory;

		// Add elements (You can add without .insert)
		inventory["Bow"] = 1;
		inventory["Arrow"] = 5;
		inventory["Potion"] = 3;

		// Loop
		for (const auto& [item, quantity] : inventory) // Structure binding
		{
			std::cout << item << ": " << quantity << '\n';
		}
		std::cout << "\n\n";

		std::cout << "You have found 2 arrows and 1 potion" << "\n\n";
		inventory["Arrow"] += 2;
		inventory["Potion"]++;

		// Loop
		for (const auto& [item, quantity] : inventory) // Structure binding
		{
			std::cout << item << ": " << quantity << '\n';
		}
	}
	std::cout << '\n';

	/* -------------- Algorithm ---------------- */

	// Algorithms are used to solve problems by sorting, searching, and manipulating data structures.

	// The <algorithm> library provides many useful functions to perform these tasks with iterators.

	// Iterator Functions:
	// 1. begin() - Gets the pointer of the first element in a container.
	// 2. end() - Gets the pointer of the last element in a container.

	// Common algorithm Functions:
	// 1. sort(start_iterator, end_iterator) - Sorts elements in a container.
	// 2. find(start_iterator, end_iterator, value) - To search for a certain element in a container.
	// 3. rbegin(), rend() - Reverses the elements in a container.
	// 4. upper_bound(start_iterator, end_iterator, value) - To search for the first element that is greater than a specific value.
	// 5. min_element(start_iterator, end_iterator) - To find the smallest element in a container.
	// 6. max_element(start_iterator, end_iterator) - To find the largest element in a container.
	// 7. copy(start_iterator, end_iterator, container) - To copy elements from one container to another.

	std::cout << "-------------- Algorithm ---------------" << "\n\n";

	{
		std::vector<int> numbers = { 1, 3, 6, 1, 4 };

		/* Normal */
		std::cout << "Numbers: ";
		print(numbers);
		std::cout << '\n';

		/* Sort (Smallest To Largest) */
		std::sort(numbers.begin(), numbers.end());
		std::cout << "Numbers (Smallest to Largest): ";
		print(numbers);
		std::cout << '\n';

		/* Reverse */
		std::sort(numbers.rbegin(), numbers.rend());
		std::cout << "Numbers (Reversed): ";
		print(numbers);
		std::cout << '\n';

		/* Clear */
		numbers.clear();
		numbers = { 1, 3, 6, 1, 4 };

		/* Upper_Bound */
		auto it = std::upper_bound(numbers.begin(), numbers.end(), 3);

		std::cout << "First element higher than 3 = " << *it << '\n';

		/* Min and Max */
		auto min = std::min_element(numbers.begin(), numbers.end());
		auto max = std::max_element(numbers.begin(), numbers.end());

		std::cout << "Min element: " << *min << '\n';
		std::cout << "Max element: " << *max << '\n';

		/* Copy */
		std::vector<int> copiedNumbers(5);

		std::cout << "copiedNumbers: ";
		std::copy(numbers.begin(), numbers.end(), copiedNumbers.begin());
		print(copiedNumbers);
	}

	std::cout << "\n\n";
	std::cout << "----------------------------------------" << '\n';

	std::cin.get();
	return 0;
}
