/*
*
* Homework 04
* By Ilya Nikolskiy
* 10.10.2020
*
*1. Описать функцию, возвращающую строку с двоичным представлением положительного целого десятичного числа, переданного в аргументе этой функции.
*2. Описать структуру "прямоугольник", содержащую целочисленные значения длины, ширины, периметра и площади прямоугольника. Написать функцию, принимающую на вход указатель на структуру, подсчитывающую и записывающую площадь и периметр данного прямоугольника в структуру.
*3. Описать структуру "прямая линия" которая должна состоять из длины и двух внутренних структур типа "точка", в каждой из которых должны содержаться координаты по оси 'х' и по оси 'у'. Описать функцию принимающую на вход координаты двух точек, и возвращающую структуру "линия" с подсчитанной длиной.
*4. (необязательно) Написать функцию-обёртку, принимающую указатель на область памяти, которую затем можно использовать как двумерный массив из элементов типа integer. Количество элементов указывается в аргументе функции. Массив должен быть гарантированно инициализирован нулями. Для проверки - заполните этот массив и выведите на экран.
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROWS 10
#define COLUMNS 10

typedef struct rectangle {
	int length;
	int width;
	int perimeter;
	int square;
} Rectangle;

typedef struct point {
	int pos_x;
	int pos_y;
} Point;

typedef struct line {
	Point point_a;
	Point point_b;
	float length;
} Line;

void calcRectangle(Rectangle *r) {
	r->square = r->length * r->width;
	r->perimeter = 2*(r->length + r->width);
}

void calcLineLength(Line *l) {
	int offset_x = l->point_a.pos_x - l->point_b.pos_x; 
	int offset_y = l->point_a.pos_y - l->point_b.pos_y;
	l->length = sqrt(pow(offset_x, 2) + pow(offset_y, 2));
}

void printBinary(int *d, char *out) {
	int i = 0;
	int b = 0;
	int e = 0;
	while (*d != 0) {
		// преобразуем 1 или 0 в символ "1" или "0"
		out [i] = (*d % 2) + '0';
		*d = *d / 2;
		i++;
	}
	// изменим порядок символов в строке 
	e = i - 1;
	for (b = 0; b < i / 2; b++) {
		out [e] = out [b] + out [e];
		out [b] = out [e] - out [b];
		out [e] = out [e] - out [b];
		e--;
	}
	// добавим символ Line Feed и терминатор строки
	out [i] = '\0';			
	out [i++] = 10;			
}

int *arrayInt(int *array, unsigned len) {
	array = (int *) calloc(len, sizeof(int));
	return array;
}

void printArray(int *array) {
int i = 0;
int c = 0;
printf("Массив:\n");
	for (i = 0; i < ROWS; i++){
		for (c = 0; c < COLUMNS; c++) 
			printf("%4d", *(array + i * ROWS + c));
		printf("\n");
	}
}

Rectangle r;
Line l;
int d;
char out[33];
int i, c;

int main() {
	// Задание 1
	printf("Вывод строки с бинарным представлением целого числа\n");
	printf("Введите целое положительное число: ");
	scanf("%d", &d);
	printBinary(&d, out);
	printf("%s", out);

	// Задание 2
	printf("Площадь и периметр прямоугольника\n");
	printf("Введите сторону А: ");
	scanf("%d", &r.length);
	printf("Введите сторону B: ");
	scanf("%d", &r.width);
	calcRectangle(&r);
	printf("Периметр: %d\nПлощадь: %d\n", r.perimeter, r.square);

	// Задание 3
	printf("Длина линии\n");
	printf("Введите координаты X и Y точки A:");
	scanf("%d %d", &l.point_a.pos_x, &l.point_a.pos_y);
	printf("Введите координаты X и Y точки B:");
	scanf("%d %d", &l.point_b.pos_x, &l.point_b.pos_y);
	calcLineLength(&l);
	printf("Длина линии %.2f условных единиц.\n", l.length);
	
	// Задание 4
	int *array = arrayInt(array, COLUMNS * ROWS); 
	printArray(array);

	for (i = 0; i < ROWS; i++)
		for (c = 0; c < COLUMNS; c++)
			*(array + i * ROWS + c) = (i + 1) * (c + 1);

	printArray(array);
	free(array);
	return 0;
}
