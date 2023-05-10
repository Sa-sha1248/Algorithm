#include <stdio.h>
#include <stdint.h>
#include <limits.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICED 100
#define INF 1000000/*무한대(연결이 없는 경우)*/

typedef struct {
	int n;
	int weight[MAX_VERTICED][MAX_VERTICED];
}GraphType;

int distance[MAX_VERTICED]; /*시작정점으로부터의 최단경로 거리*/
int found[MAX_VERTICED]; /*방문한 정점 표시*/

char* city[10] = { "서울", "천안", "대전", "논산", "광주", "부산", "대구", "포항", "강릉","원주" };

int choose(int distance[], int n, int found[])
{
	int i, min, minpos;
	min = INT_MAX;
	minpos = -1;
	for (i = 0; i < n; i++)
	{
		if (distance[i] < min && !found[i]) {
			min = distance[i];
			minpos = i;
		}
	}
	return minpos;
}

void print_status(GraphType* g)
{
	static int step = 1;
	printf("STEP %d: \n", step++);
	printf("distance: ");
	for (int i = 0; i < g->n; i++)
	{
		if (distance[i] == INF)
			printf("    * ");
		else
			printf("%5d ", distance[i]);
	}
	printf("\n");
	printf("   found: ");
	for (int i = 0; i < g->n; i++)
		printf("%5d ", found[i]);
	printf("\n\n");
}


void shortest_path(GraphType* g, int start)
{
	int i, u, w;
	for (i = 0; i < g->n; i++)//초기화
	{
		distance[i] = g->weight[start][i];
		found[i] = FALSE;
	}
	found[start] = TRUE;
	distance[start] = 0;
	for (i = 0; i < g->n; i++)
	{
		//print_status(g);
		u = choose(distance, g->n, found);
		found[u] = TRUE;
		for (w = 0; w < g->n; w++)
		{
			if (!found[w])
				if (distance[u] + g->weight[u][w] < distance[w])
					distance[w] = distance[u] + g->weight[u][w];
		}
	}
}

int main(void)
{

	//char* city[10] = { "서울", "천안", "대전", "논산", "광주", "부산", "대구", "포항", "강릉","원주" };
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


	
	for (int i = 0; i < 10; i++)
	{
		printf(" %s ", city[i]);
	}
	printf("\n");
	
	for (int i = 0; i < 10; i++)
	{
		for (int k = 0; k < 10; k++)
		{
			if (g.weight[i][k] == INF)
				printf("    * ");
			else
				printf("%5d ", g.weight[i][k]);
		}
		printf("\n");
	}

	printf("\n");
	for (int i = 0; i < 10; i++)
	{
		shortest_path(&g, i);
		for (int k = 0; k < 10; k++)
		{
			if (distance[k] == INF)
				printf("    * ");
			else
				printf("%5d ", distance[k]);
		}
		printf("\n");
	}
	
	return 0;
}

//참고자료
//C언어로 쉽게 풀어쓴 자료구조