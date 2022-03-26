#include<iostream>
#include <Windows.h>

void ShowSumAverageMinMaxNumber()
{
	const int N = 5;
	const int M = 6;
	srand(time(0));
	int sum = 0;
	int average = 0;
	int min = 0;
	int max = 20;
	int minNumber = max;
	int maxNumber = min;

	int arr[N][M] = {};

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			arr[y][x] = rand() % (max - min + 1);
			printf("%5d", arr[y][x]);
			sum += arr[y][x];
			if (arr[y][x] < minNumber)
				minNumber = arr[y][x];
			if (arr[y][x] > maxNumber)
				maxNumber = arr[y][x];
		}
		average = sum / (N * M);
		std::cout << std::endl;
	}
	std::cout << "sum = " << sum << ", average number is " << average << ", min number is " << minNumber << ", max number is " << maxNumber << std::endl;
}

void ShowSumDiagonals()
{
	const int M = 6;
	srand(time(0));
	int sumMainDiagonal = 0;
	int sumSecondaryDiagonal = 0;
	int min = 0;
	int max = 20;
	int arr[M][M] = {};
	for (int y = 0; y < M; y++)
	{
		for (int x = 0; x < M; x++)
		{
			arr[y][x] = rand() % (max - min + 1);
			printf("%5d", arr[y][x]);
			if (x == y)
				sumMainDiagonal += arr[y][x];
			if (y == M - 1 - x)
				sumSecondaryDiagonal += arr[y][x];
		}
		std::cout << std::endl;
	}
	std::cout << "Sum of main dialgonal is " << sumMainDiagonal << ", sum of secondary dialgonal is " << sumSecondaryDiagonal << std::endl;
}

void ShowNumberPositiveNegativeZeroElements ()
{
	const int N = 5;
	const int M = 6;
	srand(time(0));
	int min = -10;
	int max = 10;
	int plus = 0;
	int minus = 0;
	int zero = 0;
	int arr[N][M] = {};

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			arr[y][x] = rand() % (max - min + 1) - 10;
			printf("%5d", arr[y][x]);
			if (arr[y][x] > 0)
				plus++;
			else if (arr[y][x] == 0)
				zero++;
			else if (arr[y][x] < 0)
				minus++;
		}
		std::cout << std::endl;
	}
	std::cout << "Number of positive numbers is " << plus << ", number of negative numbers is " << minus << ", number of zeros is " << zero << std::endl;
}

void ShowSumRowColumnArray()
{
	const int N = 5;
	const int M = 6;
	srand(time(0));
	int min = 0;
	int max = 20;
	int arr[N][M] = {};

	for (int y = 0; y < N; y++)
	{
		int sumOfLine = 0;
		for (int x = 0; x < M; x++)
		{
			arr[y][x] = rand() % (max - min + 1) - 10;
			printf("%5d", arr[y][x]);
			sumOfLine += arr[y][x];
		}
		printf("   = " "%5d", sumOfLine);
		std::cout << std::endl;
	}
	std::cout << std::endl;
	for (int i = 0; i < M; i++)
		printf("    =");
	std::cout << std::endl;
	for (int x = 0; x < M; x++)
	{
		int sumOfColumn = 0;
		for (int y = 0; y < N; y++)
			sumOfColumn += arr[y][x];
		printf("%5d", sumOfColumn);
	}
	std::cout << std::endl;
}

void ShowArray()
{
	const int N = 5;
	const int M = 6;
	int arr[N][M] = {};

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			arr[y][x] = (y + 1) * 10 + x + 1;
			printf("%5d", arr[y][x]);
		}
		std::cout << std::endl;
	}
}

void SwapEvenOddLines()
{
	const int N = 6;
	const int M = 8;
	srand(time(0));
	int min = 0;
	int max = 20;
	int arr[N][M] = {};
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			arr[y][x] = rand() % (max + min + 1);
			printf("%5d", arr[y][x]);
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			if (y % 2 == 0)
				std::swap(arr[y][x], arr[y + 1][x]);
			printf("%5d", arr[y][x]);
		}
		std::cout << std::endl;
	}
}

void CounterclockwiseSpiral()
{
	const int N = 6;
	int arr[N][N] = {};
	int direction = 1;
	int current = N * N;
	int x = 0;
	int y = 0;

	for (int i = N * N; i > 0; i--)
	{
		arr[y][x] = current--;
		if (direction == 1) x++;
		else if (direction == 2) y++;
		else if (direction == 3) x--;
		else if (direction == 4) y--;

		if (direction == 1 && (x == N - 1 || arr[y][x + 1] != 0)) direction = 2;
		else if (direction == 2 && (y == N - 1 || arr[y + 1][x] != 0)) direction = 3;
		else if (direction == 3 && (x == 0 || arr[y][x - 1] != 0)) direction = 4;
		else if (direction == 4 && (y == 1 || arr[y - 1][x] != 0)) direction = 1;

		system("cls");
		for (int a = 0; a < N; a++)
		{
			for (int b = 0; b < N; b++)
				printf("%5d", arr[a][b]);
			std::cout << std::endl;
		}
		Sleep(100);
	}
}

void ClockwiseSpiral()
{
	const int N = 6;
	int arr[N][N] = {};
	int direction = 1;
	int current = 1;
	int x = 0;
	int y = 0;

	for (int i = 0; i < N * N; i++)
	{
		arr[y][x] = current++;
		if (direction == 1) y++;
		else if (direction == 2) x++;
		else if (direction == 3) y--;
		else if (direction == 4) x--;

		if (direction == 1 && (y == N - 1 || arr[y + 1][x] != 0)) direction = 2;
		else if (direction == 2 && (x == N - 1 || arr[y][x + 1] != 0)) direction = 3;
		else if (direction == 3 && (y == 0 || arr[y - 1][x] != 0)) direction = 4;
		else if (direction == 4 && (x == 1 || arr[y][x - 1] != 0)) direction = 1;

		system("cls");
		for (int a = 0; a < N; a++)
		{
			for (int b = 0; b < N; b++)
				printf("%5d", arr[a][b]);
			std::cout << std::endl;
		}
		Sleep(100);
	}
}


int main()
{
	std::cout << std::endl;
	ShowSumAverageMinMaxNumber();
	std::cout << std::endl;
	ShowSumDiagonals();
	std::cout << std::endl;
	ShowNumberPositiveNegativeZeroElements();
	std::cout << std::endl;
	ShowSumRowColumnArray();
	std::cout << std::endl; 
	ShowArray();
	std::cout << std::endl;
	SwapEvenOddLines();
	std::cout << std::endl;
	CounterclockwiseSpiral();
	std::cout << std::endl;
	ClockwiseSpiral();
}
