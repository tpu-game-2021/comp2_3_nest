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
	int pattern[11];
	int count = 0;

	pattern[0] = val1 + val2;
	pattern[1] = val1 + val3;
	pattern[2] = val1 + val4;
	pattern[3] = val2 + val3;
	pattern[4] = val2 + val4;
	pattern[5] = val3 + val4;
	pattern[6] = val1 + val2 + val3;
	pattern[7] = val1 + val2 + val4;
	pattern[8] = val1 + val3 + val4;
	pattern[9] = val2 + val3 + val4;
	pattern[10] = val1 + val2 + val3 + val4;

	if (pattern[0] == sum)
	{
		count = count + 1;
	}
	if (pattern[1] == sum)
	{
		count = count + 1;
	}
	if (pattern[2] == sum)
	{
		count = count + 1;
	}
	if (pattern[3] == sum)
	{
		count = count + 1;
	}
	if (pattern[4] == sum)
	{
		count = count + 1;
	}
	if (pattern[5] == sum)
	{
		count = count + 1;
	}
	if (pattern[6] == sum)
	{
		count = count + 1;
	}
	if (pattern[7] == sum)
	{
		count = count + 1;
	}
	if (pattern[8] == sum)
	{
		count = count + 1;
	}
	if (pattern[9] == sum)
	{
		count = count + 1;
	}
	if (pattern[10] == sum)
	{
		count = count + 1;
	}


	if (val1 == sum)
	{
		count = count + 1;
	}
	if (val2 == sum)
	{
		count = count + 1;
	}
	if (val3 == sum)
	{
		count = count + 1;
	}
	if (val4 == sum)
	{
		count = count + 1;
	}


	return count;
}

// val_array の配列に格納されたarray_sizeの数字の任意の組み合わせで値の和がsumになる組み合わせは何個ありますか？
int calc_combinations(int sum, const int* val_array, int array_size)
{
	float count = 0;
	int i;
	float big = 1;
	int min = 1;
	int b = 0;
	float a = 0;
	int purasu = 0;
	//1と2

	for (i = 0; i <= array_size; i++)
	{
		purasu = purasu + val_array[i];
		if (val_array[i] == sum)
		{
			count = count + 1;
		}
		else if (purasu == sum)
		{
			count = count + 1;
		}

	}
	purasu = 0;

	if (sum != array_size)
	{
		for (i = 0; i < sum; i++)
		{
			purasu = purasu + val_array[i];
		}
		if (purasu == sum)
		{
			for (i = 0; i < sum; i++)
			{
				a = array_size - i;
				big = big * a;
				b = 1 + i;
				min = b * min;
			}
			count = big / min;
		}
	}
	return count;
}
