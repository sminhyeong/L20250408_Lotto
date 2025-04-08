// L20250408_Lotto.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define MAX_NUMBER 45
#define LOTTO_COUNT 6

int LottoNumbers[MAX_NUMBER];

void Initialize()
{
	srand((unsigned int)time(NULL));
	for (int i = 0; i < MAX_NUMBER; i++)
	{
		LottoNumbers[i] = i + 1;
	}
}

void SetLottoNumber(int ShuffleCount)
{
	int temp = 0;
	for (int cnt = 0; cnt < ShuffleCount; cnt++)
	{
		int idx1 = rand() % MAX_NUMBER;
		int idx2 = rand() % MAX_NUMBER;
		temp = LottoNumbers[idx1];
		LottoNumbers[idx1] = LottoNumbers[idx2];
		LottoNumbers[idx2] = temp;
	}
}
void Sort()
{
	for (int i = 0; i < LOTTO_COUNT - 1; i++)
	{
		int temp = 0;
		for (int j = i + 1; j < LOTTO_COUNT; j++)
		{
			if (LottoNumbers[i] > LottoNumbers[j])
			{
				temp = LottoNumbers[i];
				LottoNumbers[i] = LottoNumbers[j];
				LottoNumbers[j] = temp;
			}
		}
	}

}
void SelectionSort()
{
	for (int i = 0; i < LOTTO_COUNT; i++)
	{
		int min = 999;
		int idx = 0;

		for (int j = i; j < LOTTO_COUNT; j++)
		{

			if (min > LottoNumbers[j])
			{
				idx = j;
				min = LottoNumbers[j];
			}
		}
		min = LottoNumbers[i];
		LottoNumbers[i] = LottoNumbers[idx];
		LottoNumbers[idx] = min;

	}
}

void BubbleSort()
{
	for (int i = 0; i < LOTTO_COUNT - 1; i++)
	{
		int temp = 0;
		for (int j = 0; j < LOTTO_COUNT - i - 1; j++)
		{
			if (LottoNumbers[j] > LottoNumbers[j + 1])
			{
				temp = LottoNumbers[j];
				LottoNumbers[j] = LottoNumbers[j + 1];
				LottoNumbers[j + 1] = temp;
			}
		}
	}
}

void PrintLottoNumber()
{
	for (int i = 0; i < LOTTO_COUNT; i++)
	{
		printf("%d ", LottoNumbers[i]);
	}
	printf("\n");
}


//int main()
//{
//	int GameCount = 0;
//	Initialize();
//	std::cin >> GameCount;
//
//	if (GameCount > 5)
//	{
//		GameCount = 5;
//	}
//
//	for (int cnt = 0; cnt < GameCount; cnt++)
//	{
//		SetLottoNumber(MAX_NUMBER * 1000);
//		SelectionSort();
//		PrintLottoNumber();
//	}
//}
void* ReSize(void* ptr, int Size)
{
	delete[] ptr;
	return new unsigned char[Size];
}

int main()
{
	int size = 20;
	int* DynamicArray = new int[10];

	//int* test = (int*)malloc(sizeof(int) * 10);


	for (int i = 0; i < 10; ++i)
	{
		DynamicArray[i] = (i + 1) * 3;
	}
	if(DynamicArray!= nullptr)
		std::cout << DynamicArray << std::endl;

	DynamicArray = (int*)ReSize(DynamicArray, sizeof(int)*20);

	for (int i = 0; i < size; ++i)
	{
		if (DynamicArray != nullptr)
		{
			if (i < 10)
				DynamicArray[i] = (i + 1) * 3;
			else
				DynamicArray[i] = ((i + 1) - 10) * 4;
		}
	}
	if (DynamicArray != nullptr)
		std::cout << DynamicArray << std::endl;

	for (int i = 0; i < size; i++)
	{
		if (DynamicArray != nullptr)
			printf("%d, ", DynamicArray[i]);
	}

	delete[] DynamicArray;
}