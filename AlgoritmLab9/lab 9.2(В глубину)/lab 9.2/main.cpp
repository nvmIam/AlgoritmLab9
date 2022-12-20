#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <queue> 
#include "time.h"
#include <stack>
using namespace std;
int** M;
int* dist;
int BFSD(int size,int v)
{
  stack<int>Stack;
  Stack.push(v); 
  dist[0]=0;

while (!Stack.empty())
  { 
int v = Stack.top(); 
    Stack.pop();
for (int i = 0; i < size; i++)
    { 
if (M[v][i] == 1 && dist[i] == -1)
{ // если вершина смежная и не обнаружена
		Stack.push(i); 
        dist[i] = dist[v]+1; 
      }
    }

  }
return 0;
}

int main(){
	setlocale(LC_ALL, "Russian");
	int size;
  printf("Введите размер матрицы: ");
  scanf("%d", &size);
   M = (int**)malloc(sizeof(int*) * size);
    for (int i = 0; i < size; i++) {
        M[i] = (int*)malloc(sizeof(int) * size);
    }
	srand(time(NULL));
	for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            M[i][j] = rand() % 2;
        }
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == j) {
                M[i][j] = 0;
            }
            if (M[i][j] = M[j][i]) {
                M[i][j] = M[j][i];
            }
        }
   }
	printf("Матрица смежности:");
	for (int i = 0; i < size; i++) {
		printf("\n");
        for (int j = 0; j < size; j++) {
           printf("%3d",M[i][j]);
        }
    }
	
	 dist = (int*)malloc(sizeof(int) * size);
  for (int i = 0; i < size; i++)
    dist[i] = -1;
   printf("\nРасстояния в графе: ");
    int start = clock();
  BFSD(size, 0);
   int end = clock();
  for (int i = 0; i < size; i++) {
  printf("\nРасстояние до %d вершины -> %d",i, dist[i]);
        }
  printf("\n");
  double time = (end-start) / 1000.0;
	printf("Time: %lf\n", time);
	system("Pause");
	return 0;
}
