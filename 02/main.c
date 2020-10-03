/*
* Exercise 2
* By Ilya Nikolskiy
* 24.09.2020
*/
#include <stdio.h>
int main ()
{
	// Запросить число и проверить диапазон 0 ... 100
	int value = 0;
	printf("Введите целое число: ");
	scanf("%d", &value);
	if ((0 <= value) & (value <= 100))
		printf("Ваше число %d находится внутри диапазона 0 ... 100\n", value);
	else
		printf("Ваше число %d не попадает в диапазон 0 ... 100\n", value); 
	// Среднее арифметическое 10-ти чисел
	int i;
	value = 0;
	float sum = 0;
	for (i = 1; i <= 10; i++)
		{
			printf("Введите число № %i: ", i);
			scanf("%d", &value);
			sum = sum + value;
		}
	printf("Сумма чисел равна: %.1f\nСреднее арифметическое равно: %.2f\n", sum, sum/--i);
	// Вывод всех положительных чётных чисел до 1000
	int max_range;
	i = 0;

	do {
		printf("Введите целое число не более 1000: ");
		scanf("%d", &max_range);
	} while (max_range > 1000);
	while (i < max_range)
	{
		if (i % 2 == 0)
			printf("%d, ", i);
		i++;
	}
	printf("\n");
	//Равнобедренный треугольник
	int line = 1;
	int pos = 1;
	max_range = 0;
	printf("Введите число строк: ");
	scanf("%d", &max_range);
	while (line <= max_range)
	{
		pos = 1;
		while (pos <= line)
		{
			printf("^");
			pos++;
		}
		printf("\n");
		line++;
	}

	return 0;
}
