#include <iostream>
#include "../functions/functions.h"
#include <vector>
#include <termcolor/termcolor.hpp>
#include <conio.h>
#include <string>

int getKey()
{
	int key = _getch();
	return key;
}
void randinit(std::vector<int>& v)
{
	srand(time(NULL));
	unsigned max = rand() % 15;
	std::vector<int> vect(max);
	for (auto it = vect.begin(); it < vect.end(); it++)
	{
		*it = rand() % 201 - 100;
	}
	v = vect;
}
int getInt()
{
	int value;
	char str[256];
	while (true)
	{
		system("cls");
		std::cout << termcolor::bright_cyan << "Enter a value: " << termcolor::reset;

		try
		{
			gets_s(str, 256);
			value = std::stoi(str);
			break;
		}
		catch (std::invalid_argument)
		{
			std::cout << "Invalid argument" << std::endl;
			system("pause");
		}

	}
	return value;
}
unsigned getIndex(const unsigned& max)
{
	int value;
	char str[256];
	while (true)
	{
		system("cls");
		std::cout << termcolor::bright_cyan << "Enter an Index: " << termcolor::reset;

		try
		{
			gets_s(str, 256);
			value = std::stoi(str);
			if (value < 0)
				throw - 1;
			else if (value > max - 1)
				throw 1;
			break;
		}
		catch (int error)
		{
			if (error == -1)
				std::cout << "Index can not be less than 0" << std::endl;
			else if (error == 1)
				std::cout << "Index is out of range" << std::endl;
			system("pause");
		}
		catch (std::invalid_argument)
		{
			std::cout << "Invalid argument" << std::endl;
			system("pause");
		}

	}
	return static_cast<unsigned>(value);
}
stats sort(std::vector<int>& vect,stats(*f)(std::vector<int>&))
{
	stats result = f(vect);
	return result;
}

int vectorMenu(std::vector<int>& vect, const size_t& arrow, const stats& statistic)
{
	std::cout << termcolor::cyan << "Vector menu" << termcolor::reset << std::endl;
	for (auto it = vect.begin(); it != vect.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	switch (arrow)
	{
		case 0:
		{
			std::cout << termcolor::bright_yellow << "Add element" << termcolor::reset << std::endl;
			std::cout << "Delete element" << std::endl;
			std::cout << "Randomize" << std::endl;
			std::cout << "Selection sort" << std::endl;
			std::cout << "Cocktail sort" << std::endl;
			std::cout << "Comb sort" << std::endl;
			break;
		}
		case 1:
		{
			std::cout << "Add element" <<  std::endl;
			std::cout << termcolor::bright_yellow << "Delete element" << termcolor::reset << std::endl;
			std::cout << "Randomize" << std::endl;
			std::cout << "Selection sort" << std::endl;
			std::cout << "Cocktail sort" << std::endl;
			std::cout << "Comb sort" << std::endl;
			break;
		}
		case 2:
		{
			std::cout << "Add element" << std::endl;
			std::cout << "Delete element" << std::endl;
			std::cout << termcolor::bright_yellow << "Randomize" << termcolor::reset << std::endl;
			std::cout << "Selection sort" << std::endl;
			std::cout << "Cocktail sort" << std::endl;
			std::cout << "Comb sort" << std::endl;
			break;
		}
		case 3:
		{
			std::cout << "Add element" << std::endl;
			std::cout << "Delete element" << std::endl;
			std::cout << "Randomize" << std::endl;
			std::cout << termcolor::bright_yellow << "Selection sort" << termcolor::reset << std::endl;
			std::cout << "Cocktail sort" << std::endl;
			std::cout << "Comb sort" << std::endl;
			break;
		}
		case 4:
		{
			std::cout << "Add element" << std::endl;
			std::cout << "Delete element" << std::endl;
			std::cout << "Randomize" << std::endl;
			std::cout << "Selection sort" << std::endl;
			std::cout << termcolor::bright_yellow << "Cocktail sort" << termcolor::reset << std::endl;
			std::cout << "Comb sort" << std::endl;
			break;
		}
		case 5:
		{
			std::cout << "Add element" << std::endl;
			std::cout << "Delete element" << std::endl;
			std::cout << "Randomize" << std::endl;
			std::cout << "Selection sort" << std::endl;
			std::cout << "Cocktail sort" << std::endl;
			std::cout << termcolor::bright_yellow << "Comb sort" << termcolor::reset << std::endl;
			break;
		}
		default: break;
	}

	std::cout << std::endl;

	if (statistic.comparison_count != 0)
	{
		std::cout << termcolor::bold << "Statistic: " << termcolor::reset << statistic.comparison_count << " : " << statistic.copy_count << std::endl;
	}

	return getKey();
}

void process()
{
	std::vector<int> main_vector;
	stats statistic = { 0, 0 };
	size_t arrow = 0;
	while (true)
	{
		system("cls");
		int action = vectorMenu(main_vector, arrow, statistic);

		if (action == 27)
			break;
		else if (action == 13)
		{
			switch (arrow)
			{
			case 0:
			{
				main_vector.push_back(getInt());
				break;
			}
			case 1:
			{
				if (main_vector.size() != 0)
				{
					unsigned index = getIndex(main_vector.size());
					main_vector.erase(main_vector.begin() + index);
				}
				break;
			}
			case 2:
			{
				randinit(main_vector);
				statistic = { 0,0 };
				break;
			}
			case 3:
			{
				statistic = sort(main_vector, selection_sort);
				break;
			}
			case 4:
			{
				statistic = sort(main_vector, cocktail_sort);
				break;
			}
			case 5:
			{
				statistic = sort(main_vector, comb_sort);
				break;
			}
			default: break;
			}
		}
		else if (action == 72 && arrow > 0)
			arrow--;
		else if (action == 80 && arrow < 5)
			arrow++;
	}
	return;
}

int main()
{
	process();
	return 0;
}