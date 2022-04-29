#include "../functions/functions.h"
#include <random>
#include <fstream>
#include <string>

void randinit(std::vector<int>& v)
{
	srand(time(NULL));

	for (auto it = v.begin(); it < v.end(); it++)
	{
		*it = rand() % 201 - 100;
	}
}

void straight_sorted(std::vector<int>& v)
{
	for (int i = 0; i < v.size(); i++)
		v[i] = i;
}

void reverse_sorted(std::vector<int>& v)
{
	for (int i = 0; i < v.size(); i++)
		v[i] = v.size() - i;
}

stats* stats_iteration(stats(*f)(std::vector<int>&), void(*g)(std::vector<int>&))
{
	stats* measurements = new stats[10];
	std::vector<int> vect;
	//std::cout << "Selection sort: " << std::endl;
	for (int i = 1; i <= 10; i++)
	{
		std::cout << i*1000 << " size..." << std::endl;
		vect.resize(i * 1000);
		g(vect);
		measurements[i - 1] = f(vect);
		//std::cout << i*1000 << " elements: " << measurements[i - 1].comparison_count << ", " << measurements[i - 1].copy_count << std::endl;
	}
	return measurements;
}

void save_sorted_SR_measurements() // Paths are gonna be hardcoded because I am too sleepy for their realizations
{
	std::fstream file;
	stats* selection_straight_measurements = stats_iteration(selection_sort, straight_sorted);
	stats* cocktail_straight_measurements = stats_iteration(cocktail_sort, straight_sorted);
	stats* comb_staight_measurements = stats_iteration(comb_sort, straight_sorted);
	stats* selection_reverse_measurements = stats_iteration(selection_sort, reverse_sorted);
	stats* cocktail_reverse_measurements = stats_iteration(cocktail_sort, reverse_sorted);
	stats* comb_reverse_measurements = stats_iteration(comb_sort, reverse_sorted);

	file.open("../selection_straight.txt", 'w');
	for (int i = 0; i < 10; i++)
	{
		file << selection_straight_measurements[i].comparison_count << " " << selection_straight_measurements[i].copy_count << std::endl;
	}
	file.close();
	file.open("../selection_reverse.txt", 'w');
	for (int i = 0; i < 10; i++)
	{
		file << selection_reverse_measurements[i].comparison_count << " " << selection_reverse_measurements[i].copy_count << std::endl;
	}

	file.close();
	file.open("../cocktail_straight.txt", 'w');
	for (int i = 0; i < 10; i++)
	{
		file << cocktail_straight_measurements[i].comparison_count << " " << cocktail_straight_measurements[i].copy_count << std::endl;
	}
	file.close();
	file.open("../cocktail_reverse.txt", 'w');
	for (int i = 0; i < 10; i++)
	{
		file << cocktail_reverse_measurements[i].comparison_count << " " << cocktail_reverse_measurements[i].copy_count << std::endl;
	}

	file.close();
	file.open("../comb_straight.txt", 'w');
	for (int i = 0; i < 10; i++)
	{
		file << comb_staight_measurements[i].comparison_count << " " << comb_staight_measurements[i].copy_count << std::endl;
	}
	file.close();
	file.open("../comb_reverse.txt", 'w');
	for (int i = 0; i < 10; i++)
	{
		file << comb_reverse_measurements[i].comparison_count << " " << comb_reverse_measurements[i].copy_count << std::endl;
	}
	file.close();
}

stats** all_stats(stats(*f)(std::vector<int>&), const std::string& path)
{
	stats** measurements = new stats* [100];
	std::fstream file;
	file.open(path, 'w');
	for (int i = 0; i < 100; i++)
	{
		std::cout << "Measure " << i << ":" << std::endl;
		measurements[i] = stats_iteration(f, randinit);
		for (int j = 0; j < 10; j++)
		{
			file << measurements[i][j].comparison_count << " " << measurements[i][j].copy_count << " | ";
		}
		file << std::endl;
		std::cout << "Done" << std::endl;
	}
	file.close();
	return measurements;
}

int main()
{
	all_stats(selection_sort, "../selection_sort.txt");
	all_stats(cocktail_sort, "../cocktail_sort.txt");
	all_stats(comb_sort, "../comb_sort.txt");
	save_sorted_SR_measurements();
	return 0;
}