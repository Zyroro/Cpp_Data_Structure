#include "pch.h"

template<typename Container> 
static void print(const Container& container)
{
	std::cout << "{";

	for (auto it = container.begin(); it != container.end(); ++it)
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

	// Mostly going to state the definition and the differences between data structures.

	/* -------------- Vectors ---------------- */

	// A vector in C++ is similar to an array.
	// The difference between an array and a vector, is that the size of an array cannot be modified 
	// (you cannot add or remove elements from an array). 
	// A vector however, can grow or shrink in size as needed.

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
		
		std::cout << " (After popping)"  << '\n';

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

	/* -------------- Deque ---------------- */

	/* -------------- Sets ---------------- */

	/* -------------- Map ---------------- */

	std::cin.get();
	return 0;
}

