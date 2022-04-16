#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

char name1[10],name2[10],name3[10];
int timeAlive1, timeAlive2, timeAlive3;
int prior1,prior2,prior3;
int time1, time2, time3;

struct processes
{
	char name[10];
	int timeAlive;
	int prioritet;
	int time;
	char symbol[5];
	int left;
};

int main()
{
	int minPriority,mintimeAlive,currentInd;
	setlocale(LC_ALL,"RUS");
	struct processes MainProcess[3];
	
	for (int i=0;i<3;i++)
	{
		puts("Имя процесса: ");
		gets(MainProcess[i].name);
		
		puts("Продолжительность процесса: ");
		scanf("%d",&MainProcess[i].timeAlive);
		
		puts("Приоритет процесса: ");
		scanf("%d",&MainProcess[i].prioritet);
		
		puts("Время появления процесса: ");
		scanf("%d",&MainProcess[i].time);
		
		MainProcess[i].left=MainProcess[i].timeAlive;
		printf("Процесс %d: \n************************\n",i+1);
		fflush(stdin);
	}
	
	int timeAll=MainProcess[0].timeAlive+MainProcess[1].timeAlive+MainProcess[2].timeAlive;
	
	printf("%d\n",timeAll);
	
	printf("Квант Времени|Процесс %4s|Процесс %4s|Процесс %4s| Осталось P1 | Осталось P2 | Осталось P3 |\n",MainProcess[0].name,MainProcess[1].name,MainProcess[2].name);
	
	for (int i=1;i<=timeAll;i++)
	{		
		minPriority=100;
		mintimeAlive=timeAll;
		
		for(int k=0;k<3;k++)
		{
			if (MainProcess[k].time<=i && MainProcess[k].left>0)
			{
				if (MainProcess[k].prioritet<=minPriority)
				{
					minPriority=MainProcess[k].prioritet;
					if (MainProcess[k].timeAlive<mintimeAlive)
					{
						mintimeAlive=MainProcess[k].timeAlive;
						currentInd=k;
					}
				}
			}
		}
		
		for (int k=0;k<3;k++)
		{
			if(currentInd==k && MainProcess[k].left>0)
				strcpy(MainProcess[k].symbol,"И");
			else if(MainProcess[k].time<=i && MainProcess[k].left>0)
				strcpy(MainProcess[k].symbol,"Г");
			else
				strcpy(MainProcess[k].symbol," ");
		}
		fflush(stdin);		
		MainProcess[currentInd].left--;
		printf("      %7d|        %4s|        %4s|        %4s|%-13d|%-13d|%-13d|",i,MainProcess[0].symbol,MainProcess[1].symbol,MainProcess[2].symbol,MainProcess[0].left,MainProcess[1].left,MainProcess[2].left);
		getchar();
	}
	
	
	fflush(stdin);
	getchar();
	return 0;
	
}
