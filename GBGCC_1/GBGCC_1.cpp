//Не понял, что я должен был тут продимонстрировать
//И как то криво получилось и вроде работает
//Обработчика ошибок ввода нет
//Числа надо вводить целые
//
//Самый простой make со стандартной целью по умолчанию будет выглядеть как:
// .PHONY: all
//	all:
//		gcc -o main main.c
//
#include <stdio.h>
#include <stdlib.h>
#include <vcruntime_string.h>

int main()
{
	int index = -1;
	char symbol[1000];
	float result = 0.0f;
	char tempChar[1000];
	int i = 0;
	int number[1000];
	char znak[1000];
	int operation = 0;

	gets_s(symbol);

	

	memset(tempChar, 0, sizeof(tempChar));

	do
	{
		index++;
		if ('0' <= symbol[index] && symbol[index] <= '9')
		{
			tempChar[i] = symbol[index];
			i++;
		}
		else
		{
			znak[operation] = symbol[index];
			number[operation] = atoi(tempChar);
			memset(tempChar, 0, sizeof(tempChar));
			i = 0;
			operation++;
		}
	} while (symbol[index] != '\0');

	operation--;

	result = (float)number[0];

	for (int y = 0; y < operation; y++)
	{
		switch (znak[y])
		{
		case '+':
			result = result + number[y + 1];
			break;
		case '-':
			result = result - number[y + 1];
			break;
		case '/':
			result = result / number[y + 1];
			break;
		case '*':
			result = result * number[y + 1];
			break;
		}
	}

	printf("\n%f", result);
	return 0;
}
