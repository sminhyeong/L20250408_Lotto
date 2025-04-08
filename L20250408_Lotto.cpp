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

void SelectionSort()
{
	for (int i = 0; i < LOTTO_COUNT; i++)
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

void BubbleSort()
{
	for (int i = 0; i < LOTTO_COUNT-1; i++)
	{
		int temp = 0;
		for (int j = 0; j < LOTTO_COUNT - i - 1; j++)
		{
			if (LottoNumbers[j] > LottoNumbers[j+1])
			{
				temp = LottoNumbers[j];
				LottoNumbers[j] = LottoNumbers[j+1];
				LottoNumbers[j+1] = temp;
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


int main()
{
	int GameCount = 0;
	Initialize();
	std::cin >> GameCount;

	if (GameCount > 5)
	{
		GameCount = 5;
	}

	for (int cnt = 0; cnt < GameCount; cnt++)
	{
		SetLottoNumber(MAX_NUMBER * 1000);
		SelectionSort();
		PrintLottoNumber();
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
