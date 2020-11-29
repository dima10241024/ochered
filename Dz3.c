#include <stdio.h> 
#include <stdlib.h> 
#define M 100 
void bubbleSort(int* num, int* B, int size);
int main(void) {

	int n;
	int N;
	int p;

	int i, j;
	
	printf("Enter the number of graph vertices: ");//вершины
	scanf("%d", &N);
	/*
	printf("Enter the number of graph edges: ");//ребра
	scanf("%d", &n);
	//проверка графа на связность
	p = 0.5 * (N - 1) * (N - 2);
	if (n > p) {
		printf("Graph connected\n");
	}
	if (n <= p) {
		printf("Graph not connected\n");
	}*/

	//вводим матрицу
	int** A = (int**)malloc(N * sizeof(int*));
	for (int i = 0; i < N; i++)
		A[i] = (int*)malloc(N * sizeof(int));

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			scanf("%d", &A[i][j]);

	//ищем Q - количество вершин с четными степенями
	int q = 0;
	for (i = 0; i < N; i++) {
		int sum = 0;
		for (j = 0; j < N; j++)
			sum = sum + A[i][j];
		if (sum % 2 == 0) {
			q++;
		}
	}


	//массив для вершнин четных степеней и значений этих степеней
	int* B=(int*)malloc(q * sizeof(int));
	int* C = (int*)malloc(q * sizeof(int));


	//поиск вершин с четными степенями
	int k = 0;
	for (i = 0; i < N; i++) {
		int s = 0;  
		for (j = 0; j < N; j++)
			s = s + A[i][j];
		if (s % 2 == 0) {
			B[k] = i + 1;
			C[k] = s;
			k++;
		}
	}
	
	//сортировка пузырьком в возрастающем порядке
	bubbleSort(C, B, q);  // вызываем функцию сортировки
	
	//вывод вершин со степенями в порядке убывания
	for (i = q-1; i >=0; i--) {
		printf("versh %d - ", B[i]);
		printf("stepen %d \n", C[i]);
	}

	//очищение
	for (int i = 0; i < N; i++) {
		free(A[i]);
	}
	free(A);
	free(B);
	free(C);

	return 0;
}
	
void bubbleSort(int* num, int* B, int size) {
	for (int i = 0; i < size - 1; i++)    //первый цикл ставим самый мин. на свое место, потом мин. из оставшихся и т.д.)
		for (int j = (size - 1); j > i; j--) // для всех элементов после i-ого
			if (num[j - 1] > num[j]) { // если текущий элемент меньше предыдущего
				int temp = num[j - 1]; // меняем их местами
				num[j - 1] = num[j];
				num[j] = temp;

				int t = B[j - 1]; // меняем их местами
				B[j - 1] = B[j];
				B[j] = t;
			}
}
