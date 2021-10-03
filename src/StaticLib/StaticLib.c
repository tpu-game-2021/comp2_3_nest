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
		int a = 0;
		int b = val1 + val2;//3.4
		int c = val2 + val3;//1.4
		int d = val3 + val1;//2.4
		int e = val4 + val1;//2.3
		int f = val4 + val2;//1.3
		int g = val4 + val3;//1.2
		int h = val1 + val2 + val4;//3
		int i = val4 + val2 + val3;//1
		int j = val4 + val1 + val3;//2
		int k = val2 + val1 + val3;//4
		int m = val1 + val2 + val3 + val4;

		if (sum == val1)
		{
			a += 1;
		}
		if (sum == val2)
		{
			a += 1;
		}
		if (sum == val3)
		{
			a += 1;
		}
		if (sum == val4)
		{
			a += 1;
		}
		if (b == sum)
		{
			a += 1;
		}
		if (c == sum)
		{
			a += 1;
		}
		if (d == sum)
		{
			a += 1;
		}
		if (e == sum)
		{
			a += 1;
		}
		if (f == sum)
		{
			a += 1;
		}
		if (g == sum)
		{
			a += 1;
		}
		if (h == sum)
		{
			a += 1;
		}
		if (i == sum)
		{
			a += 1;
		}
		if (j == sum)
		{
			a += 1;
		}
		if (k == sum)
		{
			a += 1;
		}
		if (m == sum)
		{
			a += 1;
		}


		return a;

}

// val_array の配列に格納されたarray_sizeの数字の任意の組み合わせで値の和がsumになる組み合わせは何個ありますか？
int calc_combinations(int sum, const int* val_array, int array_size)
{
	int i, k;
	k = 1;

	if (val_array[1] == 1) 
	{
		for (i = 0; i < sum; i++)
		{
			k = k * (array_size - i) / (i + 1);
		}
		if (sum == array_size)
		{
			k = 1;
		}
	}
	else
	{
		k = 1;
	}

	return k;
}
