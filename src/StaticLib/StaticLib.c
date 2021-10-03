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
	//conbinations = 'c','o','n','b'
	int c = 0;
	int o = 0;
	int n = 0;
	int b = 0;

	if (sum == val1) c += 1;
	if (sum == val2) c += 1;
	if (sum == val3) c += 1;
	if (sum == val4) c += 1;

	if (sum == val1 + val2) o += 1;
	if (sum == val1 + val3) o += 1;
	if (sum == val1 + val4) o += 1;
	if (sum == val2 + val3) o += 1;
	if (sum == val2 + val4) o += 1;
	if (sum == val3 + val4) o += 1;
	
	if (sum == val1 + val2 + val3) n += 1;
	if (sum == val1 + val3 + val4) n += 1;
	if (sum == val1 + val2 + val4) n += 1;
	if (sum == val2 + val3 + val4) n += 1;
	
	if (sum == val1 + val2 + val3 + val4) b += 1;

	return c + o + n + b;
}

// val_array の配列に格納されたarray_sizeの数字の任意の組み合わせで値の和がsumになる組み合わせは何個ありますか？
int calc_combinations(int sum, const int* val_array, int array_size)
{
	int i, j;
	int goukei = 0;
	int count = 0;
	float  denominator = 1, molecule = 1;

	for (i = 0; i < array_size; i++)
	{
		goukei = goukei + val_array[i];
		if (sum == goukei)
		{
			for (j = 0; j < i + 1; j++)
			{
				denominator = denominator * ((float)(i + 1) - j);
				molecule = molecule * ((float)array_size - j);
			}
			count = (int)(molecule / denominator);
			break;
		}
	}

	return count;
}
