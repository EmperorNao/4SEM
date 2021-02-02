#include <stdio.h> 
#include <stdlib.h> 
#include <locale.h> 

#pragma warning(disable:4996)

typedef struct { 
	char name[30];
	char number[15];
	char adress[30];
} inform;

// ¬вод структуры a
void read_struct(inform* a);

// Cоздание бинарного файла по имени filename
void create_binary_file(char* filename);

int main() {

	setlocale(LC_ALL, "RUS"); 
	char s[20]; 
	printf("¬ведите название файла\n"); 
	gets(s); 
	create_binary_file(s);
	puts("‘айл был успешно создан");
}


void create_binary_file(char* s) {

	int n; 
	printf("¬ведите количество записей\n"); 
	scanf("%d", &n); 
	gets();
	fflush(stdin); 
	FILE* f; 
	f = fopen(s, "wb"); 
	inform a; 
	for (int i = 0; i < n; i++) { 

		read_struct(&a); 
		fwrite(&a, sizeof(inform), 1, f); 

	} 
	fclose(f);

} 


void read_struct(inform* a) {

	printf("¬ведите фамилию\n"); 
	gets(a->name); 
	printf("¬ведите номер\n"); 
	gets(a->number); 
	printf("¬ведите адрес\n"); 
	gets(a->adress);

}