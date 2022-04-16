#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

int freeSpace=0,fullMemory,processNumber=0;
float cw=0,ca=0;

struct processes
{
	int size;
	char name[50];
	int address; 
	int segments[3]; 
		
};

void addProcess(struct processes process[100])
{
	ca++;
	
	int size;
	printf("Введите имя процесса %d: ",processNumber+1);
	fflush(stdin);
	gets(process[processNumber].name);
	printf("Введите размер процесса %d (в байтах): ",processNumber+1);
	scanf("%d",&size);
	
	if (size>freeSpace-2048)
	{
		puts("Невозможно выделить столько данных.");
	}
	
	else 
	{
		cw++;
		process[processNumber].size=size;
		freeSpace=freeSpace-size-2048;
		processNumber++;
	}	
		
}

void deleteProcess(struct processes process[100])
{
	int adress;
	printf("Введите №-процесса (его адрес): ");
	scanf("%d",&adress);
	
	freeSpace=freeSpace+2048+process[adress].size;
	
	for (int i=adress+1;i<processNumber;i++)
		{				
			process[i-1].size=process[i].size; 
			strcpy(process[i-1].name,process[i].name);
		}
	processNumber--;
}

void showTable(struct processes process[100])
{
	int segments=0;
	printf("\n******************************\n");
	printf("| № сегмента | № процесса | Спецификация сегмента |  Имя процесса  | Размер | \n"); 
	for (int i=0;i<processNumber;i++)
	{
		
		for (int k=0;k<3;k++)
		{
			
			printf("| %10d |",segments);
			printf(" %10d |",i+1);
			if (k==0)
			{
				printf("     Сегмент данных    |");
				printf(" %14s |",process[i].name);
				printf(" %6d |",process[i].size);
			}
			else if (k==1)
			{
				printf("      Сегмент кода     |");
				printf(" %14s |",process[i].name);
				printf("   1024 |");
			}
			else 
			{
					printf("     Сегмент стека     |");
				printf(" %14s |",process[i].name);
				printf("   1024 |");
			
			}
			printf("\n");
			segments++;
		}
			printf("\n*****************************************************************************\n");
		
		
	}
}

void showData()
{
	float percent = (cw/ca)*100;
	printf("\n******************************\n");
	printf("Выделено %d(единиц) памяти: ",fullMemory);
	printf("\nСвободно %d(единиц) памяти:",freeSpace);
	printf("\nКол-во отправленных запросов на выделение памяти: %.0f",ca);
	printf("\nКол-во подходящий процессов: %.2f %%",percent);
	
}

void showAddress(struct processes process[100])
{
	int segment;
	int number;
	puts("Введите номер процесса: ");
	scanf("%d",&number);
	
	puts("Введите номер сегмента процесса (от 0 до 2)");
	scanf("%d",&segment);
	
	int *a = &process[number].segments[segment];
	
	printf("Адрес сегмента %d процесса %d - %x",segment,number,a);
	
}

int main()
{
	setlocale(LC_ALL,"RUS");
	struct processes process[100];
	
	puts("Введите объем свободной памяти (в Байтах)");
	scanf("%d",&freeSpace);
	
	fullMemory=freeSpace;
	
	int t=1;
	
	int menu;
	
	while (t)
	{

		
		puts("\n***********************************\n");
		puts(" 1) ИНФОРМАЦИЯ О ПАМЯТИ");
		puts(" 2) ДОБАВИТЬ ПРОЦЕСС");
		puts(" 3) УДАЛИТЬ ПРОЦЕСС");
		puts(" 4) ВЫВОД НУЖНОГО ПРОЦЕССА ПО АДРЕСУ");
		puts(" 5) СПИСОК ПРОЦЕССОВ");
		puts(" 6) ВЫХОД\n");
		puts("************************************\n");
		
		scanf("%d",&menu);
		
		switch(menu)
		{
			case 1:
				showData();
				break;
			case 2:
				addProcess(process);
				break;
			case 3:
				deleteProcess(process);
				break;
			case 4:
				showAddress(process);
				break;
			case 5:
				showTable(process);	
				break;
			case 6:
				t=0;
				break;
			default:
				printf("Неверно введённые данные\n");
		}
		
	}
	
}
