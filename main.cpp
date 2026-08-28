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

	//A queue stores multiple elements in a specific order, called FIFO.

	// FIFO stands for First in, First Out. 
	// To visualize FIFO, think of a queue as people standing in line in a supermarket.
	// The first person to stand in line is also the first who can pay and leave the supermarket. 
	// This way of organizing elements is called FIFO in computer science and programming.
	
	//	Unlike vectors, elements in the queue are not accessed by index numbers.
	// Since queue elements are added at the end and removed from the front, 
	// you can only access and modify an element at the front or the back.
	// You can't use a for-each loop sadly, but you can use a while not empty loop.
	
	// Functions: size(), empty(), front(), back(), push(), pop().

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

	/* -------------- Sets ---------------- */

	/* -------------- Map ---------------- */

	std::cin.get();
	return 0;
}

