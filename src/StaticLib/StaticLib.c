#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include <stdbool.h>

#include "../include/lib_func.h"

// 2つの数字が等しいですか？
bool is_same(int val1, int val2)
{
	return val1 == val2;
}

// val1 から val3 の任意の組み合わせで値の和がsumになる組み合わせは何個ありますか？
int calc_combinations_3(int sum, int val1, int val2, int val3)
{
	int num = 0;
	
	if(sum == val1) num++;
	if(sum == val2) num++;
	if(sum == val3) num++;
	if(sum == val1 + val2) num++;
	if(sum == val1 + val3) num++;
	if(sum == val2 + val3) num++;
	if(sum == val1 + val2 + val3) num++;
	
	return num;
}

// val1 から val4 の任意の組み合わせで値の和がsumになる組み合わせは何個ありますか？
int calc_combinations_4(int sum, int val1, int val2, int val3, int val4)
{
	int combinations = 0;

	if (sum == val1) combinations = combinations + 1;
	if (sum == val2) combinations = combinations + 1;
	if (sum == val3) combinations = combinations + 1;
	if (sum == val4) combinations = combinations + 1;
	if (sum == val1 + val2) combinations = combinations + 1;
	if (sum == val1 + val3) combinations = combinations + 1;
	if (sum == val1 + val4) combinations = combinations + 1;
	if (sum == val2 + val3) combinations = combinations + 1;
	if (sum == val2 + val4) combinations = combinations + 1;
	if (sum == val3 + val4) combinations = combinations + 1;
	if (sum == val1 + val2 + val3) combinations = combinations + 1;
	if (sum == val1 + val2 + val4) combinations = combinations + 1;
	if (sum == val1 + val3 + val4) combinations = combinations + 1;
	if (sum == val2 + val3 + val4) combinations = combinations + 1;
	if (sum == val1 + val2 + val3 + val4) combinations = combinations + 1;

	return combinations;
}

// val_array の配列に格納されたarray_sizeの数字の任意の組み合わせで値の和がsumになる組み合わせは何個ありますか？
int calc_combinations(int sum, const int* val_array, int array_size)
{
	int i, j;
	int TOTAL = 0;
	int combinations = 0;
	float combinations_1 = 1;
	float combinations_2 = 1;

	for (i = 0; i < array_size; i++)
	{
		TOTAL = TOTAL + val_array[i];
		if (sum == TOTAL)
		{
			for (j = 0; j < i + 1; j++)
			{
				combinations_1 = combinations_1 * ((float)(i + 1) - j);
			}
			for (j = 0; j < i + 1; j++)
			{
				combinations_2 = combinations_2 * ((float)array_size - j);
			}
			combinations = (int)(combinations_2 / combinations_1);
			break;
		}
	}

	return combinations;
	
}
