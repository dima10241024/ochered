
#include <stdio.h> 
#include <stdlib.h> 
#define M 100 
int main(void){

		int n;
		int N;
		int p;

		int i, j;
		//проверка графа на связность
		printf("Enter the number of graph vertices: ");
		scanf("%d", &N);
		printf("Enter the number of graph edges: ");
		scanf("%d", &n);
		p = 0.5 * (N - 1) * (N - 2);
		if (n > p) {
			printf("Graph connected\n");
		}
		if (n <= p) {
			printf("Graph not connected\n");
		}

		//вводим матрицу
		int** A = (int**)malloc(N * sizeof(int*));
		for (int i = 0; i < N; i++) 
			A[i] = (int*)malloc(N * sizeof(int));

		for (i = 0; i < N; i++)
			for (j = 0; j < N; j++) 
				scanf("%d", &A[i][j]);
			


		//запись в документ
		FILE* s;
		s = fopen("dima.dot", "w");
		//пример fprintf(s, ” % d”, a);
		fprintf(s, "digraph G {\n");
		//printf("digraph G {\n");
			
		for (i = 0; i < N; i++)
			for (j = 0; j < N; j++) {
				if (A[i][j] != 0){
                                        while(A[i][j]>=1){
					fprintf(s, "%d -> %d; \n", i + 1, j + 1);
					//printf("%d -> %d; \n", i+1, j+1);
                                        A[i][j]--;
                                        }
				}
			}
		fprintf(s, "}");
		//printf("}");

		fclose(s);

		//очищение
		for (int i = 0; i < N; i++) {
			free(A[i]);
		}
		free(A);

		return 0;
}
