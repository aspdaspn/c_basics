/*
* Homework 03
* By Ilya Nikolskiy
* 05.10.2020
*1. Используя заголовочный файл <math.h>, описать функцию: int calcSquareEq(int a, int b, int c, double* x1, double* x2); Которая будет решать квадратное уравнение вида a * x ** 2 + b * x + c = 0, и записывать корни этого уравнения в переменные, адреса которых переданы в качестве указателей х1 и х2. Функция должна вернуть -1, если уравнение не имеет корней, 0, если у уравнения есть один корень, и 1, если у уравнения два корня.
*
*2. Инициализировать массив из целых чисел, описать функцию, принимающую на вход этот массив. Функция должна вернуть ноль, если в массиве нет нечётных чисел, в противном случае удвоить все нечётные числа в массиве и вернуть единицу. После выполнения функции, если массив был изменён, вывести все числа из массива на экран.
*
*3. Опишите функцию asShortPrint(unsigned* a, int len); которая принимает массив из тридцатидвухразрядных чисел (типа unsigned int), например, [0, 1, 2, 3, 4, 65541, 65542, 65543, 65544, 65545] и выводит его на экран шестнадцатиразрядными числами (типа unsigned short). Для массива в примере вывод будет выглядеть следующим образом [0, 0, 1, 0, 2, 0, 3, 0, 4, 0, 5, 1, 6, 1, 7, 1, 8, 1, 9, 1]. Решения такого рода широко применяются для расшифровывания данных из входящих потоков или логов цифровых систем в аппаратуре.
*/
#include <stdio.h>
#include <math.h>

// Для всех проверяющих: определение переменных для всех заданий. Не комментируйте этот блок!
#define ARRAY_LENGTH 10
double x1, x2;
int a, b, c;
int diskr;
char input;
int digit_array[ARRAY_LENGTH];
unsigned int unsigned_int_array[ARRAY_LENGTH];
// Конец блока определения переменных

int calcSquareEq(int a, int b, int c, double* x1, double* x2) {
	// Проверим что пользователь не ввёл что-то вида 0x^2 + 0*b + 5 = 0
	if ((a == 0) && (b == 0) && (c != 0))
		return -1;
	int d;
	// Посчитаем дискриминант и определим число корней:
	// d < 0, нет корней, возвращаем -1
	// d > 0, два корня, посчитаем x2 и x1 и вернём 1
	// d = 0, один корень, посчитаем х1 и вернём 0
	d = pow(b, 2) - 4 * a * c;
	if (d < 0)
		return -1;
	else {
		if (d > 0)
			*x2 = (-b - sqrt(d)) / (2 * a);
		*x1 = (-b + sqrt(d)) / (2 * a);
		return (d > 0) ? 1 : 0;
	}
}

void inputArray(unsigned int *arr, int len, char *type_specifier) {
	// В программе два массива: unsigned int и unsigned short. 
	// Переменная указатель type_specifier покажет scanf тип входных данных
	int i = 0;
	while (i < len) {
		printf("Элемент № %2d: ", i);
		scanf(type_specifier, arr + i);
		i++;
	}
}

int makeEven(int *arr, int len) {
	int i = 0;
	int odd = 0;
	while (i < len) {
		if (arr[i] % 2 != 0) {
			arr[i] = arr[i] * 2;
			odd++;
		}
		i++;
	}
	// Вернём 1, если выполнится условие odd != 0, т.е. чётные числа в массиве есть
	return odd != 0;
}

void printArray(int *arr, int len) {
	int i = 0;
	printf("Массив:\n");
	for (i = 0; i < len; i++)
		printf("%3d%s", arr[i], (i < len - 1) ? "," : "");
	printf("\n");
}
	
void convertLongShortArray(unsigned int *arr, int len) {
	// Число 65545 выглядит как HEX 0001 0009. Нам нужно вывести сначала два младших байта 0009, затем старшие 0001
	// arr[i] & 0xFFFF накладывает маску FFFF на два младших байта в элементе массива и выводит их.
	// arr[i] >> 16 сдвигает число на 16 бит вправо 0001 0009 >> 0001
	int i = 0;
	printf("Преобразованный массив:\n");
	for (i = 0; i < len; i++)
		printf("%d, %d%s", arr[i] & 0xFFFF, arr[i] >> 16, (i < len - 1) ? ", " : "");
	printf("\n");
}

int main() {
	// Задача 1: квадратное уравнение
	x1 = 0;
	x2 = 0;
	printf("Квадратное уравнение вида ax^2 + bx + c = 0\n");
	do {
		printf("Введите a, b, c через пробел без запятых: ");
		scanf("%d %d %d", &a, &b, &c);
		printf("Уравнение %dx^2 %s %dx %s %d = 0 ", a, (b < 0) ? "" : "+", b, (c < 0) ? "" : "+", c);
		diskr = calcSquareEq(a, b, c, &x1, &x2);
		if (diskr == -1)
			printf("не имеет корней!\n");
		else {
			printf("имеет %d кор%s\n", diskr + 1, (diskr > 0) ? "ня:\n" : "ень:\n");
			printf("x1 = %.2f\n", x1);
			if (diskr > 0)
				printf("x2 = %.2f\n", x2);
		}
		printf("Посчитать ещё? (y/n): ");
		scanf("%s", &input);
	}	while (input == 'y');
	
	// Задача 2: нечётные числа в массиве
	do {
		printf("\nНечетные числа в массиве\n");
		printf("Введите %d целых чисел в массив:\n", ARRAY_LENGTH);
		inputArray(digit_array, ARRAY_LENGTH, "%d");
		if (makeEven(digit_array, ARRAY_LENGTH) == 1) {
			printf("Удваиваем все нечётные числа:\n");
			printArray(digit_array, ARRAY_LENGTH);
		}
		else {
			printf("Ваш масив не содержит нечётных чисел\n");
		}
		printf("Посчитать ещё? (y/n): ");
		scanf("%s", &input);
	}	while (input == 'y');
	
	// Задача 3: преобразование insigned int в insigned short
	do {
		printf("\nПреобразование insigned int в insigned short\n");
		printf("Введите %d положительных чисел от 0 до 4294967295:\n", ARRAY_LENGTH);
		inputArray(unsigned_int_array, ARRAY_LENGTH, "%u");
		convertLongShortArray(unsigned_int_array, ARRAY_LENGTH);
		printf("Посчитать ещё? (y/n): ");
		scanf("%s", &input);
	}	while (input == 'y');
	return 0;
}

