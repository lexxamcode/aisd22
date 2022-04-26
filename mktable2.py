import pandas as pd
import re


def mktable(input_path:str, output_path:str):
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
	input_file = open(input_path, 'r')

	i = 0
	for line in input_file.readlines():
		line = re.sub('\n', '', line)
		if table.get(i + 1) is None:
			table[i + 1] = line
		else:
			table[i + 1].append(line)
		i+=1
	
	print(table)
	data_frame = pd.DataFrame(table)

	for i in range(1, 11):
		data_frame[f'{i}.comp'] = data_frame[i].str.split(' ').str.get(0).astype(int)
		data_frame[f'{i}.copy'] = data_frame[i].str.split(' ').str.get(1).astype(int)
		del data_frame[i]

	data_frame.to_excel(output_path)
	input_file.close()

if __name__ == '__main__':
	mktable('../selection_straight.txt', '../selection_straight.xlsx')
	mktable('../selection_reverse.txt', '../selection_reverse.xlsx')
	mktable('../cocktail_straight.txt', '../cocktail_straight.xlsx')
	mktable('../cocktail_reverse.txt', '../cocktail_reverse.xlsx')
	mktable('../comb_straight.txt', '../comb_straight.xlsx')
	mktable('../comb_reverse.txt', '../comb_reverse.xlsx')