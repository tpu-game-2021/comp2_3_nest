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
	int n = 0;

	for (int n1 = 0; n1 < 2;n1++) {
		for (int n2 = 0; n2 < 2; n2++) {
			for (int n3 = 0; n3 < 2; n3++) {
				for (int n4 = 0; n4 < 2; n4++) {
					int s = 0;
					if (n1 == 1)s += val1;
					if (n2 == 1)s += val2;
					if (n3 == 1)s += val3;
					if (n4 == 1)s += val4;

					if (s == sum)n++;
				}
			}
		}
	}
	return n;
	
}

// val_array の配列に格納されたarray_sizeの数字の任意の組み合わせで値の和がsumになる組み合わせは何個ありますか？
int calc_combinations_sub(int array_index,int num,int now,int sum, const int* val_array, int array_size) 
{
	if (now == sum) num++;

	if (sum <= now)return num;

	if (array_index < array_size) {
		int val = val_array[array_index];

		num=calc_combinations_sub(array_index + 1, num, now, sum, val_array, array_size);
		
		num=calc_combinations_sub(array_index + 1, num, now+val, sum, val_array, array_size);
	}
	return num;
}




int calc_combinations(int sum, const int* val_array, int array_size)
{
	return calc_combinations_sub(0, 0, 0, sum, val_array, array_size);
}
