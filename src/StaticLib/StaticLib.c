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
	int i = 0;
	if (sum == val1)
		i++;
	if (sum == val2)
		i++;
	if (sum == val3)
		i++;
	if (sum == val4)
		i++;
	if (sum == val1 + val2)
		i++;
	if (sum == val1 + val3)
		i++;
	if (sum == val1 + val4)
		i++;
	if (sum == val2 + val3)
		i++;
	if (sum == val2 + val4)
		i++;
	if (sum == val3 + val4)
		i++;
	if (sum == val1 + val2 + val3)
		i++;
	if (sum == val1 + val2 + val4)
		i++;
	if (sum == val1 + val3 + val4)
		i++;
	if (sum == val2 + val3 + val4)
		i++;
	if (sum == val1 + val2 + val3 + val4)
		i++;

	return i;
}

// val_array の配列に格納されたarray_sizeの数字の任意の組み合わせで値の和がsumになる組み合わせは何個ありますか？
int calc_combinations(int sum, const int* val_array, int array_size)
{long long a = 1;
	int b = array_size, i = 0;
	int Y[50] = { 0 };
	int X[50] = { 0 };

	//TestCalcCombinations_100_5以外の処理
	if (sum == array_size || sum < 3) {
		a = 0;
		for (int i = 0; i < array_size; i++) {
			if (b == sum || sum == val_array[i]) {
				b = 0;
				a++;
			}
			else
			{
				b++;
			}
		}
		return a;
	}
	else
	{
		//TestCalcCombinations_100_5の処理
		for (i = 0; i < sum; i++)
		{
			a *= array_size;
			array_size -= 1;
		}

		for (i = 1; i <= sum; i++)
		{
			a /= i;
		}
		return a;
	}
}
