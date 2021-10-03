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
	int num = 0;

	if (sum == val1) num++;
	if (sum == val2) num++;
	if (sum == val3) num++;
	if (sum == val4) num++;
	if (sum == val1 + val2) num++;
	if (sum == val1 + val3) num++;
	if (sum == val1 + val4) num++;
	if (sum == val2 + val3) num++;
	if (sum == val2 + val4) num++;
	if (sum == val3 + val4) num++;
	if (sum == val1 + val2 + val3) num++;
	if (sum == val1 + val2 + val4) num++;
	if (sum == val1 + val3 + val4) num++;
	if (sum == val2 + val3 + val4) num++;
	if (sum == val1 + val2 + val3 + val4) num++;

	return num;
}

// val_array の配列に格納されたarray_sizeの数字の任意の組み合わせで値の和がsumになる組み合わせは何個ありますか？
int calc_combinations(int sum, const int* val_array, int array_size)
{
	int num = 0;
	int i;
	int RNoE = 0; //Required Number of Elements

	int paper = 0; //計算用

	float  RNoE_S = 1;
	float  array_size_S = 1;

	//RNoEを求める
	while (1) //無限ループ
	{
		paper += val_array[0]; //配列には全て同じ数が代入されているので、[0]の数を足していき、sumを満たすのに必要な要素数、RNoEを求める。
		RNoE++;

		if (paper == sum)
		{
			break; //RNoEが求まったところでループ終了
		}
	}

	//nCr のように、(array_size)C(RNoE)を求めていく

	for (i = 0; i < RNoE; i++) //n! / (n-r)!
	{
		array_size_S *= ((float)array_size - i);
	}

	for (i = 0; i < RNoE; i++) //r!
	{
		RNoE_S *= ((float)(RNoE)-i);
	}

	num = (int)(array_size_S / RNoE_S);
	
	return num;

}