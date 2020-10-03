/* 04.c
* Voltage Divider
* by Ilya Nikolskiy
* 22.09.2020
*/
#include <stdio.h>
int main ()
{
	// variables
	float u_out;
	float u_in;
	float r1;
	float r2;

	printf("Расчёт входного напряжения\n");
	printf("Введите выходное напряжение Uo, V: ");
	scanf("%f", &u_out);
	printf("Введите R1, Ohm: ");
	scanf("%f", &r1);
	printf("Введите R2, Ohm: ");
	scanf("%f", &r2);
	printf("Входное напряжение Ui, V: %.2f\n", u_out*((r1+r2)/r1));
	
	printf("\nРасчёт R1, Ohm\n");
	printf("Введите входное напряжение Ui, V: ");
	scanf("%f", &u_in);
	printf("Введите выходное напряжение Uo, V: ");
	scanf("%f", &u_out);
	printf("Введите R2, Ohm: ");
	scanf("%f", &r2);
	printf("R1, Ohm: %.2f\n", r2/((u_in/u_out)-1));

	printf("\nРасчёт R2, Ohm\n");
	printf("Введите входное напряжение Ui, V: ");
	scanf("%f", &u_in);
	printf("Введите выходное напряжение Uo, V: ");
	scanf("%f", &u_out);
	printf("Введите R1, Ohm: ");
	scanf("%f", &r1);
	printf("R2, Ohm: %.2f\n", r1*(u_in/u_out-1));
	return (0);
}
	
