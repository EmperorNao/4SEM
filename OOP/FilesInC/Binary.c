/*
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <locale.h> 

#pragma warning (disable:4996)

typedef struct {
	char name[30];
	char number[15];
	char adress[30];
} inform;

// Вставляет структуру a в файл с именем s, не нарушая упорядоченности, если ее там нет
void add_new_record(char* filename, inform a);

// Ввод структуры a
void read_struct(inform* a);

// Вставляет структуру a в файл f, начиная с байта под номером i 
void insert(FILE* f, long int i, inform a);

// Возвращает номер байт в f, начиная с которого надо вставить a,
// если вставка не требуется возвращает -1// 
long int search_record(FILE* f, inform a);

// Вывод записанных в файл s структур
void write_f(char* s);


int main() {

	setlocale(LC_ALL, "RUS");
	char filename[20];
	inform a;

	read_struct(&a);

	printf("Введите название файла\n");
	gets(filename);

	printf("Содержимое файла до преобразования\n");
	write_f(filename);

	add_new_record(filename, a);

	printf("Содержимое файла после преобразования\n");
	write_f(filename);

}

void read_struct(inform* a) {

	printf("Введите фамилию\n");
	gets(a->name);
	printf("Введите номер\n");
	gets(a->number);
	printf("Введите адрес\n");
	gets(a->adress);

}


void add_new_record(char* s, inform a) {

	FILE* f;
	f = fopen(s, "r+b");
	long int i = search_record(f, a);
	if (i != -1) {
	
		insert(f, i, a);

	}
	else {

		printf("Запись найдена");

	}
	fclose(f);

}


long int search_record(FILE* f, inform a) {

	inform rec;
	long int k, p, i;
	int flag = 0;

	while (fread(&rec, sizeof(inform), 1, f) > 0)
	{
		flag = ftell(f);
		p = strcmp(a.name, rec.name);

		if (p == 0) {

			return -1;

		}
		else if (p < 0) {

			return(flag - sizeof(inform));

		}
	}
	return flag;

}


void insert(FILE* f, long int i, inform a) {

	inform rec;
	long int j, e;
	fseek(f, 0, SEEK_END);

	j = ftell(f);
	chsize(fileno(f), j + sizeof(inform));
	e = j + sizeof(inform);

	fseek(f, i, SEEK_SET);
	while (j < e) {

		fread(&rec, sizeof(inform), 1, f);
		fseek(f, -(int)(sizeof(inform)), SEEK_CUR);
		fwrite(&a, sizeof(inform), 1, f);
		a = rec;
		j = ftell(f);

	}
}


void write_f(char* s) {
	inform a;
	FILE* f;
	f = fopen(s, "rb");
	while (fread(&a, sizeof(inform), 1, f) > 0)
		printf("%s %s %s\n", a.name, a.adress, a.number);
	fclose(f);
}
*/