#include<stdio.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICED 100
#define INF 1000000/*무한대(연결이 없는 경우)*/

typedef struct {
	int n;
	int weight[MAX_VERTICED][MAX_VERTICED];
}GraphType;

void print_distance(int distance[][100], int n) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (distance[i][j] == INF)
				printf("*\t");
			else
				printf("%d\t", distance[i][j]);
		}
		printf("\n");
	}
	printf("\n");


}

int Floyd_Warsahll(GraphType* g) {

	int distance[100][100];
	for (int i = 0; i < g->n; i++)
	{
		for (int j = 0; j < g->n; j++)
		{
			distance[i][j] = g->weight[i][j];
		}
	}

	print_distance(distance, g->n);


	for (int k = 0; k < g->n; k++)
	{
		printf("K = %d\n", k);
		for (int i = 0; i < g->n; i++)
		{
			for (int j = 0; j < g->n; j++)
			{
				if (distance[i][k] + g->weight[k][j] < distance[i][j])
					if(distance[i][k] != INF && g->weight[k][j]!=INF)
						distance[i][j] = distance[i][k] + g->weight[k][j];
			}
		}
		print_distance(distance, g->n);
	}

}



int main() {

	//Dijkstra 비교
	GraphType g = { 10,
		{{0, 12, INF, INF, INF, INF, INF, INF, INF, 15},
		{12, 0, 10, 4, INF, INF, INF, INF, INF, INF},
		{INF, 10, 0, 3, INF, INF, 10, INF, INF, INF},
		{INF, 4, 3, 0, 13, INF, INF, INF, INF, INF},
		{INF, INF, INF, 13, 0, 15, INF, INF, INF, INF},
		{INF, INF, INF, INF, 15, 0, 9, 5, INF, INF},
		{INF, INF, 10, INF, INF, 9, 0, 19, INF, 7},
		{INF, INF, INF, INF, INF, 5, 19, 0, 25, INF},
		{INF, INF, INF, INF, INF, INF, INF, 25, 0, 21},
		{15, INF, INF,INF, INF, INF, 7, INF, 21, 0}}
	};

	//ppt 예제
	/*GraphType g = { 5,
		{{0,4,2,5,INF},
		{INF, 0, 1, INF, 4},
		{1,3,0,1,2},
		{-2, INF,INF,0,2},
		{INF, -3, 3, 1, 0}
	}
	};*/

	Floyd_Warsahll(&g);
}