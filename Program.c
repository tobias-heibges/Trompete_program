#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>

#define CLEARBUF() {char ch1; if(!feof(stdin)){ ch1=getc(stdin);}}

typedef struct {
	int day;
	int month;
	int year;
	int hour;
	int min;
	time_t time;
	double t_error;
	double ff;
	double ff_error;
}ex_data;

void totale_kontraktion(int, char*);
void binnenspannung(int, char*);
bool write_data(char*, ex_data);
ex_data exercise(ex_data, int);


int main()
{
	int countdown = 3;
	int choice;
	char fpath1[] = "TK.txt";
	char fpath2[] = "BI.txt";
	printf("Hi\n Which exercise would you like to do?\n 1: Totale Kontraktion\n 2: Binnenspannung\n 0: Quit\n");
	while(choice != 0)
	{
		scanf("%d", &choice);
		//printf("%d", choice);
		switch (choice)
		{
			case 0:
				printf("Have a nice day!\n");
				return 0;
			case 1:
				totale_kontraktion(countdown, fpath1);
				break;
			case 2:
				binnenspannung(countdown, fpath2);
				break;
			case 100:
				break;
			default:
				printf("Wrong input please try again\n");
				break;
		}
		choice = 100;
		printf("Would you like to go on?\n 1: Totale Kontraktion\n 2: Binnenspannung\n 0: Quit\n ");
	}
	return 0;
}

void totale_kontraktion(int count, char* fpath1)
{
	ex_data tk;
	printf("\nAufbau:\n 1. Kinn nach unten\n 2. Binnenspannung\n 3. Rotes einklappen\n 4. Seitlich zusammengehen\nZu Beachten:\n 1. Keine Mundwinkel\n 2. Rest entspannt\n");
	tk = exercise(tk, count);
	write_data(fpath1, tk);
}

void binnenspannung(int count, char* fpath)
{
	ex_data bi;
	printf("\nAufbau:\n 1. Kinn nach unten\n 2. Binnenspannung\nZu Beachten:\n 1. Keine Mundwinkel\n 2. Rest entspannt\n 3. nicht einfalten\n 4. nicht rausrüsseln\n");
	bi = exercise(bi, count);
	write_data(fpath, bi);
}

bool write_data(char* fpath1, ex_data ex)
{
	FILE * file = fopen(fpath1, "a");
	fprintf(file, "%d.%d.%d\t%02d:%02d\t%d\t%f\t%f\t%f\n", ex.day, ex.month, ex.year, ex.hour, ex.min, ex.time, ex.t_error, ex.ff, ex.ff_error);
	fclose(file);
}

ex_data exercise(ex_data ex, int count)
{
	printf("\nBereit?\n");
	CLEARBUF();
	getchar();
	printf("\nÜbung beginnt in\n");
	while(count > 0)
	{
		printf("%d\n", count);
		count--;
		sleep(1);
	}

	time_t now;
	time(&now);
	//printf("%d\n", now);
	time_t end;
	time_t hold_time;
	getchar();
	time(&end);
	//printf("%d\n", end);
	hold_time = end - now;
	ex.time = end - now;
	printf("Du hast %d s gehalten\n", hold_time);

	time_t t = time(0);
	struct tm tm = *localtime(&t);
	ex.year = tm.tm_year + 1900;
	ex.month = tm.tm_mon + 1;
	ex.day = tm.tm_mday;
	ex.hour = tm.tm_hour;
	ex.min =tm.tm_min;

	printf("Wie genau ist die Zeitabschätzung?\n");
	scanf("%lf", &ex.t_error);
	printf("\nWie zufrieden bist du mit der Ausführung? (0 sehr gut, 10 hatte nichts damit zu tun)\n");
	CLEARBUF();
	scanf(" %lf", &ex.ff);
	printf("\nWie schätzt du den Fehler dieser Einschätzung ab? (auch zwischen 0 und 10)\n");
	CLEARBUF();
	scanf(" %lf", &ex.ff_error);
	count = 10;
	printf("Weiter geht es mit der zweiten Runde!");
	while(count > 0)
	{
		printf("%d\n", count);
		count--;
		sleep(1);
	}
    return ex;
}



