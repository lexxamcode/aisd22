import pandas as pd
import re

def saveSort(sort_name:str):
	table = {1: [],
			 2: [],
			 3: [],
			 4: [],
			 5: [],
			 6: [],
			 7: [],
			 8: [],
			 9: [],
			 10: []}
	input_file = open(f'../{sort_name}.txt', 'r')

	lines = input_file.readlines()

	i = 0
	for line in lines:
		measures = line.split(' | ')
		for measure in measures:
			if i < 10:
				measure = re.sub(r'\n', '', measure)
				table[i + 1].append(measure)
			i += 1
		i = 0

	print(table)
	data_frame = pd.DataFrame(table)

	for i in range(1, 11):
		data_frame[f'{i}.comp'] = data_frame[i].str.split(' ').str.get(0).astype(int)
		data_frame[f'{i}.copy'] = data_frame[i].str.split(' ').str.get(1).astype(int)
		del data_frame[i]

	data_frame.to_excel(f'../{sort_name}.xlsx')
	input_file.close()


if __name__ == '__main__':
	saveSort('selection_sort')
	saveSort('cocktail_sort')
	saveSort('comb_sort')
	