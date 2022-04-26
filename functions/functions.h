#include <iostream>
#include <vector>

struct stats
{
	size_t comparison_count;
	size_t copy_count;
};

stats selection_sort(std::vector<int>& data)
{
	stats selection_sort_stats = {0 ,0};
	for (int i = 0; i < data.size()-1; i++)
	{
		for (int j = i + 1; j < data.size(); j++)
		{
			selection_sort_stats.comparison_count++;
			if (data[j] < data[i])
			{
				selection_sort_stats.copy_count++;
				int temp = data[j];
				data[j] = data[i];
				data[i] = temp;
			}
		}
	}

	return selection_sort_stats;
}

stats cocktail_sort(std::vector<int>& data)
{
	stats cocktail_sort_stats = { 0, 0 };
	int left = 1;
	int right = data.size() - 1;
	while (left <= right)
	{
		for (int i = right; i >= left; i--)
		{
			cocktail_sort_stats.comparison_count++;
			if (data[i - 1] > data[i])
			{
				cocktail_sort_stats.copy_count++;
				int temp = data[i - 1];
				data[i - 1] = data[i];
				data[i] = temp;
			}
		}
		left++;

		for (int i = left; i <= right; i++)
		{
			cocktail_sort_stats.comparison_count++;
			if (data[i - 1] > data[i])
			{
				cocktail_sort_stats.copy_count++;
				int temp = data[i];
				data[i] = data[i - 1];
				data[i - 1] = temp;
			}
		}
		right--;
	}
	return cocktail_sort_stats;
}

stats comb_sort(std::vector<int>& data)
{
	stats comb_sort_stats = {0, 0};
	int step = int(data.size());
	while (step >= 1)
	{
		step = (int)(step / 1.247);
		for (int i = 0; i < data.size() - step; i++)
		{
			comb_sort_stats.comparison_count++;
			if (data[i] > data[i + step])
			{
				comb_sort_stats.copy_count++;
				int temp = data[i];
				data[i] = data[i + step];
				data[i + step] = temp;
			}
		}
	}
	return comb_sort_stats;
}