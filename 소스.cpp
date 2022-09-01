#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int X, COUNTING = 0;
	scanf("%d", &X);

	while (1)
	{
		if (X > 0)
		{
			COUNTING++;
			X--;

			if (X % 3 == 0)
			{
				COUNTING++;
				X = X / 3;

				if (X % 3 != 0)
				{
					COUNTING++;
					printf("%d\n", COUNTING);
					break;
				}
				else
				{

				}
			}
			else
			{

			}
		}
	}
	return 0;
}

// 10에서 1을 빼면 연산횟수 +1 
// 9를 3으로 나누면 연산횟수 +1 / if문
// 3을 3으로 나누면 연산횟수 +1 / if문

// 4에서 1을 빼면 연산횟수 +1
// 3에서 3으로 나누면 연산횟수 +1 / if문