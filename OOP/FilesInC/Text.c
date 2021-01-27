/*

#include <stdio.h>
#include <locale.h>
#define N 3

void delete_main_diagonal(char* f_name, size_t n);
// ‘ункци€ преобразовывает файл по имени f_name, удал€€ из каждой квадратной матрицы пор€дка n
// элементы побочной диагонали

int main() {

	setlocale(LC_ALL, "RUS");
	char f_name[30];
	puts("¬ведите им€ файла, который необходимо преобразовать: ");
	gets(f_name);
	delete_main_diagonal(f_name, N);
	printf("‘айл был успешно преобразован, из него были удалены элементы главной диагонали из каждой квадратной матрицы пор€дка %i", N);

}


void delete_main_diagonal(char* f_name, size_t n) {

	FILE* fr, * fw;
	fopen_s(&fr, f_name, "r");

	char tmpname[L_tmpnam];
	tmpnam_s(tmpname, L_tmpnam);
	fopen_s(&fw, tmpname, "w");

	double num;
	char buffer[30];

	while (!feof(fr)) {

		for (int j = 0; j < n; j++) {

			for (int i = 0; i < j; i++) {
				fscanf_s(fr, "%lf", &num);
				fprintf_s(fw, "%lf ", num);
			}
			fscanf_s(fr, "%lf", &num);

			for (int i = j + 1; i < n; i++) {
				fscanf_s(fr, "%lf", &num);
				fprintf_s(fw, "%lf ", num);
			}
			fputc('\n', fw);
			fgets(buffer, 30, fr);
		}

	}

	fclose(fr);
	remove(f_name);
	fclose(fw);
	rename(tmpname, f_name);

}
*/